#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define MAX_FIELD_LEN 64
#define MAX_FIELDS 8

#define MENU_FILE "data/menu.csv"
#define ORDERS_FILE "data/orders.csv"
#define FEEDBACK_FILE "data/feedback.csv"
#define FINANCIAL_FILE "data/financial.csv"

#define MAX_MENU_ITEMS 100
#define MAX_ORDERS 200
#define MAX_FEEDBACK 200

static void admin_view(void);
static void client_view(void);

typedef struct {
    char id[16];
    char name[64];
    char category[32];
    int price_cents;
} MenuItem;

typedef struct {
    char id[16];
    char item_id[16];
    int quantity;
    char status[16];
    char customer[64];
    int total_cents;
} OrderRecord;

typedef struct {
    char id[16];
    char item_id[16];
    int rating;
    char comment[128];
} FeedbackRecord;

static void trim_newline(char *text);
static void safe_input(char *buffer, size_t size);
static int parse_int(const char *text, int *result);
static void generate_id(const char *prefix, int number, char *out, size_t size);
static int ensure_data_file(const char *filename, const char *header_line);
static int read_csv_lines(const char *filename, char lines[][MAX_LINE_LEN], int max_lines);
static int write_csv_lines(const char *filename, char lines[][MAX_LINE_LEN], int line_count);
static int append_csv_line(const char *filename, const char *line);
static int parse_csv_fields(const char *line, char fields[][MAX_FIELD_LEN], int max_fields);
static void initialize_data_files(void);

static void pause_and_wait(void);
static int load_menu_items(MenuItem *items, int *count);
static int save_menu_items(const MenuItem *items, int count);
static void print_menu_items(const MenuItem *items, int count);
static int find_menu_index_by_id(const MenuItem *items, int count, const char *id);

static int load_orders(OrderRecord *orders, int *count);
static int save_orders(const OrderRecord *orders, int count);
static void print_orders(const OrderRecord *orders, int count);
static int find_order_index_by_id(const OrderRecord *orders, int count, const char *id);

static int load_feedback(FeedbackRecord *entries, int *count);
static void print_feedback(const FeedbackRecord *entries, int count);
static void update_financials_on_completion(const OrderRecord *order);

static int next_identifier_from_lines(const char *filename);
static void collect_price_input(int *price_cents);
static void collect_quantity_input(int *quantity);
static int confirm_choice(const char *message);

static void admin_manage_menu(void);
static void admin_manage_orders(void);
static void admin_view_financials(void);
static void admin_view_feedback(void);

static void client_view_menu(void);
static void client_place_order(void);
static void client_track_order(void);
static void client_update_order_status(void);
static void client_leave_feedback(void);

static void trim_newline(char *text) {
    if (text == NULL) {
        return;
    }

    size_t len = strlen(text);
    while (len > 0 && (text[len - 1] == '\n' || text[len - 1] == '\r')) {
        text[len - 1] = '\0';
        len--;
    }
}

static void safe_input(char *buffer, size_t size) {
    if (fgets(buffer, (int)size, stdin) == NULL) {
        if (size > 0) {
            buffer[0] = '\0';
        }
        return;
    }
    trim_newline(buffer);
}

static int parse_int(const char *text, int *result) {
    if (text == NULL || result == NULL) {
        return -1;
    }

    char *end_ptr = NULL;
    long value = strtol(text, &end_ptr, 10);
    if (end_ptr == text || *end_ptr != '\0') {
        return -1;
    }

    *result = (int)value;
    return 0;
}

static void generate_id(const char *prefix, int number, char *out, size_t size) {
    if (out == NULL || size == 0) {
        return;
    }

    snprintf(out, size, "%s%03d", prefix, number);
}

static int ensure_data_file(const char *filename, const char *header_line) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fclose(file);
        return 0;
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        return -1;
    }

    if (header_line != NULL && header_line[0] != '\0') {
        fprintf(file, "%s\n", header_line);
    }

    fclose(file);
    return 0;
}

static int read_csv_lines(const char *filename, char lines[][MAX_LINE_LEN], int max_lines) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    int count = 0;
    while (count < max_lines && fgets(lines[count], MAX_LINE_LEN, file) != NULL) {
        trim_newline(lines[count]);
        count++;
    }

    fclose(file);
    return count;
}

static int write_csv_lines(const char *filename, char lines[][MAX_LINE_LEN], int line_count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return -1;
    }

    for (int i = 0; i < line_count; ++i) {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);
    return 0;
}

static int append_csv_line(const char *filename, const char *line) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        return -1;
    }

    fprintf(file, "%s\n", line);
    fclose(file);
    return 0;
}

static int parse_csv_fields(const char *line, char fields[][MAX_FIELD_LEN], int max_fields) {
    if (line == NULL || fields == NULL || max_fields <= 0) {
        return 0;
    }

    int field_index = 0;
    int field_pos = 0;
    int in_quote = 0;

    for (int i = 0; line[i] != '\0'; ++i) {
        char ch = line[i];

        if (ch == '"') {
            in_quote = !in_quote;
            continue;
        }

        if (ch == ',' && !in_quote) {
            fields[field_index][field_pos] = '\0';
            field_index++;
            if (field_index >= max_fields) {
                return field_index;
            }
            field_pos = 0;
            continue;
        }

        if (field_pos < MAX_FIELD_LEN - 1) {
            fields[field_index][field_pos] = ch;
            field_pos++;
        }
    }

    fields[field_index][field_pos] = '\0';
    return field_index + 1;
}

static void initialize_data_files(void) {
    ensure_data_file(MENU_FILE, "MenuID,Name,Category,PriceUnits");
    ensure_data_file(ORDERS_FILE, "OrderID,ItemID,Quantity,Status,Customer,TotalUnits");
    ensure_data_file(FEEDBACK_FILE, "FeedbackID,ItemID,Rating,Comment");
    ensure_data_file(FINANCIAL_FILE, "EntryID,OrderID,AmountUnits");
}

static void admin_manage_menu(void) {
    char input[16];
    for (;;) {
        printf("\n--- Menu Management ---\n");
        printf("1. View Menu\n");
        printf("2. Add Menu Item\n");
        printf("3. Edit Menu Item\n");
        printf("4. Delete Menu Item\n");
        printf("0. Back\n");
        printf("Choose an option: ");
        safe_input(input, sizeof(input));

        int choice = 0;
        if (parse_int(input, &choice) != 0) {
            printf("Invalid selection.\n");
            continue;
        }

        if (choice == 0) {
            return;
        }

        if (choice == 1) {
            MenuItem items[MAX_MENU_ITEMS];
            int count = 0;
            if (load_menu_items(items, &count) == 0) {
                print_menu_items(items, count);
            } else {
                printf("Unable to load menu items.\n");
            }
            pause_and_wait();
        } else if (choice == 2) {
            MenuItem items[MAX_MENU_ITEMS];
            int count = 0;
            if (load_menu_items(items, &count) != 0) {
                printf("Unable to load menu items.\n");
                pause_and_wait();
                continue;
            }
            if (count >= MAX_MENU_ITEMS) {
                printf("Menu is full.\n");
                pause_and_wait();
                continue;
            }

            MenuItem item;
            generate_id("M", count + 1, item.id, sizeof(item.id));
            printf("Enter item name: ");
            safe_input(item.name, sizeof(item.name));
            printf("Enter category: ");
            safe_input(item.category, sizeof(item.category));
            collect_price_input(&item.price_cents);

            items[count] = item;
            if (save_menu_items(items, count + 1) == 0) {
                printf("Menu item added successfully.\n");
            } else {
                printf("Failed to save menu item.\n");
            }
            pause_and_wait();
        } else if (choice == 3) {
            MenuItem items[MAX_MENU_ITEMS];
            int count = 0;
            if (load_menu_items(items, &count) != 0) {
                printf("Unable to load menu items.\n");
                pause_and_wait();
                continue;
            }

            printf("Enter item ID to edit: ");
            char id[16];
            safe_input(id, sizeof(id));
            int index = find_menu_index_by_id(items, count, id);
            if (index < 0) {
                printf("Item not found.\n");
                pause_and_wait();
                continue;
            }

            printf("Editing %s - %s\n", items[index].id, items[index].name);
            printf("Enter new name (leave blank to keep current): ");
            char buffer[64];
            safe_input(buffer, sizeof(buffer));
            if (strlen(buffer) > 0) {
                strncpy(items[index].name, buffer, sizeof(items[index].name) - 1);
                items[index].name[sizeof(items[index].name) - 1] = '\0';
            }
            printf("Enter new category (leave blank to keep current): ");
            safe_input(buffer, sizeof(buffer));
            if (strlen(buffer) > 0) {
                strncpy(items[index].category, buffer, sizeof(items[index].category) - 1);
                items[index].category[sizeof(items[index].category) - 1] = '\0';
            }
            printf("Update price? (y/n): ");
            safe_input(buffer, sizeof(buffer));
            if (buffer[0] == 'y' || buffer[0] == 'Y') {
                collect_price_input(&items[index].price_cents);
            }

            if (save_menu_items(items, count) == 0) {
                printf("Menu item updated.\n");
            } else {
                printf("Failed to update menu.\n");
            }
            pause_and_wait();
        } else if (choice == 4) {
            MenuItem items[MAX_MENU_ITEMS];
            int count = 0;
            if (load_menu_items(items, &count) != 0) {
                printf("Unable to load menu items.\n");
                pause_and_wait();
                continue;
            }

            printf("Enter item ID to delete: ");
            char id[16];
            safe_input(id, sizeof(id));
            int index = find_menu_index_by_id(items, count, id);
            if (index < 0) {
                printf("Item not found.\n");
                pause_and_wait();
                continue;
            }

            if (!confirm_choice("Are you sure you want to delete this item? (y/n): ")) {
                printf("Deletion cancelled.\n");
                pause_and_wait();
                continue;
            }

            for (int i = index; i < count - 1; ++i) {
                items[i] = items[i + 1];
            }

            if (save_menu_items(items, count - 1) == 0) {
                printf("Menu item deleted.\n");
            } else {
                printf("Failed to delete menu item.\n");
            }
            pause_and_wait();
        } else {
            printf("Unknown option.\n");
        }
    }
}

static void admin_manage_orders(void) {
    char input[16];
    for (;;) {
        printf("\n--- Order Management ---\n");
        printf("1. View All Orders\n");
        printf("2. Update Order Status\n");
        printf("0. Back\n");
        printf("Choose an option: ");
        safe_input(input, sizeof(input));
        int choice = 0;
        if (parse_int(input, &choice) != 0) {
            printf("Invalid selection.\n");
            continue;
        }

        if (choice == 0) {
            return;
        }

        if (choice == 1) {
            OrderRecord orders[MAX_ORDERS];
            int count = 0;
            if (load_orders(orders, &count) == 0) {
                print_orders(orders, count);
            } else {
                printf("Unable to load orders.\n");
            }
            pause_and_wait();
        } else if (choice == 2) {
            OrderRecord orders[MAX_ORDERS];
            int count = 0;
            if (load_orders(orders, &count) != 0) {
                printf("Unable to load orders.\n");
                pause_and_wait();
                continue;
            }

            printf("Enter order ID: ");
            char id[16];
            safe_input(id, sizeof(id));
            int index = find_order_index_by_id(orders, count, id);
            if (index < 0) {
                printf("Order not found.\n");
                pause_and_wait();
                continue;
            }

            printf("Current status: %s\n", orders[index].status);
            printf("Enter new status (Pending/InProgress/Completed/Cancelled): ");
            char status[16];
            safe_input(status, sizeof(status));
            if (strlen(status) == 0) {
                printf("Status unchanged.\n");
                pause_and_wait();
                continue;
            }
            strncpy(orders[index].status, status, sizeof(orders[index].status) - 1);
            orders[index].status[sizeof(orders[index].status) - 1] = '\0';

            if (strcmp(status, "Completed") == 0) {
                update_financials_on_completion(&orders[index]);
            }

            if (save_orders(orders, count) == 0) {
                printf("Order status updated.\n");
            } else {
                printf("Failed to update order.\n");
            }
            pause_and_wait();
        } else {
            printf("Unknown option.\n");
        }
    }
}

static void admin_view_financials(void) {
    char lines[256][MAX_LINE_LEN];
    int count = read_csv_lines(FINANCIAL_FILE, lines, 256);
    if (count < 1) {
        printf("No financial records available.\n");
        pause_and_wait();
        return;
    }

    long total_units = 0;
    int entries = 0;
    for (int i = 1; i < count; ++i) {
        char fields[MAX_FIELDS][MAX_FIELD_LEN];
        int field_count = parse_csv_fields(lines[i], fields, MAX_FIELDS);
        if (field_count < 3) {
            continue;
        }
        int amount = 0;
        if (parse_int(fields[2], &amount) == 0) {
            total_units += amount;
            entries++;
        }
    }

    printf("\n--- Financial Summary ---\n");
    printf("Recorded entries: %d\n", entries);
    printf("Total revenue (units): %ld\n", total_units);
    pause_and_wait();
}

static void admin_view_feedback(void) {
    FeedbackRecord feedback[MAX_FEEDBACK];
    int count = 0;
    if (load_feedback(feedback, &count) != 0 || count == 0) {
        printf("No feedback available.\n");
        pause_and_wait();
        return;
    }

    int total_rating = 0;
    int rated_entries = 0;
    for (int i = 0; i < count; ++i) {
        total_rating += feedback[i].rating;
        if (feedback[i].rating > 0) {
            rated_entries++;
        }
    }

    double average = 0.0;
    if (rated_entries > 0) {
        average = (double)total_rating / (double)rated_entries;
    }

    printf("\n--- Feedback Overview ---\n");
    printf("Entries: %d\n", count);
    printf("Average rating: %.2f\n", average);
    print_feedback(feedback, count);
    pause_and_wait();
}

static void client_view_menu(void) {
    MenuItem items[MAX_MENU_ITEMS];
    int count = 0;
    if (load_menu_items(items, &count) != 0 || count == 0) {
        printf("Menu is empty.\n");
    } else {
        print_menu_items(items, count);
    }
    pause_and_wait();
}

static void client_place_order(void) {
    MenuItem menu[MAX_MENU_ITEMS];
    int menu_count = 0;
    if (load_menu_items(menu, &menu_count) != 0 || menu_count == 0) {
        printf("Menu not available.\n");
        pause_and_wait();
        return;
    }
    print_menu_items(menu, menu_count);

    OrderRecord orders[MAX_ORDERS];
    int order_count = 0;
    load_orders(orders, &order_count);

    OrderRecord order;
    generate_id("O", order_count + 1, order.id, sizeof(order.id));
    printf("Enter menu item ID: ");
    safe_input(order.item_id, sizeof(order.item_id));
    int menu_index = find_menu_index_by_id(menu, menu_count, order.item_id);
    if (menu_index < 0) {
        printf("Invalid menu item.\n");
        pause_and_wait();
        return;
    }

    collect_quantity_input(&order.quantity);
    printf("Enter your name: ");
    safe_input(order.customer, sizeof(order.customer));
    strncpy(order.status, "Pending", sizeof(order.status) - 1);
    order.status[sizeof(order.status) - 1] = '\0';
    order.total_cents = menu[menu_index].price_cents * order.quantity;

    orders[order_count] = order;
    if (save_orders(orders, order_count + 1) == 0) {
        printf("Order placed successfully. ID: %s\n", order.id);
    } else {
        printf("Failed to save order.\n");
    }
    pause_and_wait();
}

static void client_track_order(void) {
    OrderRecord orders[MAX_ORDERS];
    int count = 0;
    if (load_orders(orders, &count) != 0 || count == 0) {
        printf("No orders found.\n");
        pause_and_wait();
        return;
    }
    printf("Enter your order ID: ");
    char id[16];
    safe_input(id, sizeof(id));
    int index = find_order_index_by_id(orders, count, id);
    if (index < 0) {
        printf("Order not found.\n");
    } else {
        printf("Order %s status: %s\n", orders[index].id, orders[index].status);
    }
    pause_and_wait();
}

static void client_update_order_status(void) {
    OrderRecord orders[MAX_ORDERS];
    int count = 0;
    if (load_orders(orders, &count) != 0 || count == 0) {
        printf("No orders available.\n");
        pause_and_wait();
        return;
    }

    printf("Enter order ID: ");
    char id[16];
    safe_input(id, sizeof(id));
    int index = find_order_index_by_id(orders, count, id);
    if (index < 0) {
        printf("Order not found.\n");
        pause_and_wait();
        return;
    }

    printf("1. Mark as Completed\n");
    printf("2. Cancel Order\n");
    printf("Choose an option: ");
    char input[16];
    safe_input(input, sizeof(input));
    int choice = 0;
    if (parse_int(input, &choice) != 0) {
        printf("Invalid selection.\n");
        pause_and_wait();
        return;
    }

    if (choice == 1) {
        strncpy(orders[index].status, "Completed", sizeof(orders[index].status) - 1);
        orders[index].status[sizeof(orders[index].status) - 1] = '\0';
        update_financials_on_completion(&orders[index]);
    } else if (choice == 2) {
        strncpy(orders[index].status, "Cancelled", sizeof(orders[index].status) - 1);
        orders[index].status[sizeof(orders[index].status) - 1] = '\0';
    } else {
        printf("Unknown option.\n");
        pause_and_wait();
        return;
    }

    if (save_orders(orders, count) == 0) {
        printf("Order status updated.\n");
    } else {
        printf("Failed to update order.\n");
    }
    pause_and_wait();
}

static void client_leave_feedback(void) {
    FeedbackRecord entries[MAX_FEEDBACK];
    int count = 0;
    load_feedback(entries, &count);

    FeedbackRecord entry;
    generate_id("F", count + 1, entry.id, sizeof(entry.id));

    printf("Enter item ID (leave blank for overall feedback): ");
    safe_input(entry.item_id, sizeof(entry.item_id));

    char input[16];
    int rating = 0;
    do {
        printf("Enter rating (1-5): ");
        safe_input(input, sizeof(input));
    } while (parse_int(input, &rating) != 0 || rating < 1 || rating > 5);
    entry.rating = rating;

    printf("Enter comment (optional): ");
    safe_input(entry.comment, sizeof(entry.comment));

    char line[MAX_LINE_LEN];
    snprintf(line, sizeof(line), "%s,%s,%d,%s", entry.id, entry.item_id, entry.rating, entry.comment);
    if (append_csv_line(FEEDBACK_FILE, line) == 0) {
        printf("Thank you for your feedback!\n");
    } else {
        printf("Failed to record feedback.\n");
    }
    pause_and_wait();
}

static void pause_and_wait(void) {
    char temp[4];
    printf("Press Enter to continue...");
    safe_input(temp, sizeof(temp));
}

static int load_menu_items(MenuItem *items, int *count) {
    char lines[MAX_MENU_ITEMS + 1][MAX_LINE_LEN];
    int line_count = read_csv_lines(MENU_FILE, lines, MAX_MENU_ITEMS + 1);
    if (line_count < 0) {
        *count = 0;
        return -1;
    }

    int idx = 0;
    for (int i = 1; i < line_count && idx < MAX_MENU_ITEMS; ++i) {
        char fields[MAX_FIELDS][MAX_FIELD_LEN];
        int field_count = parse_csv_fields(lines[i], fields, MAX_FIELDS);
        if (field_count < 4) {
            continue;
        }
        MenuItem item;
        strncpy(item.id, fields[0], sizeof(item.id) - 1);
        item.id[sizeof(item.id) - 1] = '\0';
        strncpy(item.name, fields[1], sizeof(item.name) - 1);
        item.name[sizeof(item.name) - 1] = '\0';
        strncpy(item.category, fields[2], sizeof(item.category) - 1);
        item.category[sizeof(item.category) - 1] = '\0';
        parse_int(fields[3], &item.price_cents);
        items[idx++] = item;
    }
    *count = idx;
    return 0;
}

static int save_menu_items(const MenuItem *items, int count) {
    char lines[MAX_MENU_ITEMS + 1][MAX_LINE_LEN];
    snprintf(lines[0], MAX_LINE_LEN, "MenuID,Name,Category,PriceUnits");
    for (int i = 0; i < count; ++i) {
        snprintf(lines[i + 1], MAX_LINE_LEN, "%s,%s,%s,%d", items[i].id, items[i].name, items[i].category, items[i].price_cents);
    }
    return write_csv_lines(MENU_FILE, lines, count + 1);
}

static void print_menu_items(const MenuItem *items, int count) {
    printf("\n%-8s | %-20s | %-12s | Price\n", "ID", "Name", "Category");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%-8s | %-20s | %-12s | %d\n", items[i].id, items[i].name, items[i].category, items[i].price_cents);
    }
}

static int find_menu_index_by_id(const MenuItem *items, int count, const char *id) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(items[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

static int load_orders(OrderRecord *orders, int *count) {
    char lines[MAX_ORDERS + 1][MAX_LINE_LEN];
    int line_count = read_csv_lines(ORDERS_FILE, lines, MAX_ORDERS + 1);
    if (line_count < 0) {
        *count = 0;
        return -1;
    }

    int idx = 0;
    for (int i = 1; i < line_count && idx < MAX_ORDERS; ++i) {
        char fields[MAX_FIELDS][MAX_FIELD_LEN];
        int field_count = parse_csv_fields(lines[i], fields, MAX_FIELDS);
        if (field_count < 6) {
            continue;
        }
        OrderRecord order;
        strncpy(order.id, fields[0], sizeof(order.id) - 1);
        order.id[sizeof(order.id) - 1] = '\0';
        strncpy(order.item_id, fields[1], sizeof(order.item_id) - 1);
        order.item_id[sizeof(order.item_id) - 1] = '\0';
        parse_int(fields[2], &order.quantity);
        strncpy(order.status, fields[3], sizeof(order.status) - 1);
        order.status[sizeof(order.status) - 1] = '\0';
        strncpy(order.customer, fields[4], sizeof(order.customer) - 1);
        order.customer[sizeof(order.customer) - 1] = '\0';
        parse_int(fields[5], &order.total_cents);
        orders[idx++] = order;
    }
    *count = idx;
    return 0;
}

static int save_orders(const OrderRecord *orders, int count) {
    char lines[MAX_ORDERS + 1][MAX_LINE_LEN];
    snprintf(lines[0], MAX_LINE_LEN, "OrderID,ItemID,Quantity,Status,Customer,TotalUnits");
    for (int i = 0; i < count; ++i) {
        snprintf(lines[i + 1], MAX_LINE_LEN, "%s,%s,%d,%s,%s,%d", orders[i].id, orders[i].item_id, orders[i].quantity, orders[i].status, orders[i].customer, orders[i].total_cents);
    }
    return write_csv_lines(ORDERS_FILE, lines, count + 1);
}

static void print_orders(const OrderRecord *orders, int count) {
    printf("\n%-8s | %-6s | Qty | %-10s | %-15s | Total\n", "OrderID", "ItemID", "Status", "Customer");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%-8s | %-6s | %-3d | %-10s | %-15s | %d\n", orders[i].id, orders[i].item_id, orders[i].quantity, orders[i].status, orders[i].customer, orders[i].total_cents);
    }
}

static int find_order_index_by_id(const OrderRecord *orders, int count, const char *id) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(orders[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

static int load_feedback(FeedbackRecord *entries, int *count) {
    char lines[MAX_FEEDBACK + 1][MAX_LINE_LEN];
    int line_count = read_csv_lines(FEEDBACK_FILE, lines, MAX_FEEDBACK + 1);
    if (line_count < 0) {
        *count = 0;
        return -1;
    }

    int idx = 0;
    for (int i = 1; i < line_count && idx < MAX_FEEDBACK; ++i) {
        char fields[MAX_FIELDS][MAX_FIELD_LEN];
        int field_count = parse_csv_fields(lines[i], fields, MAX_FIELDS);
        if (field_count < 4) {
            continue;
        }
        FeedbackRecord entry;
        strncpy(entry.id, fields[0], sizeof(entry.id) - 1);
        entry.id[sizeof(entry.id) - 1] = '\0';
        strncpy(entry.item_id, fields[1], sizeof(entry.item_id) - 1);
        entry.item_id[sizeof(entry.item_id) - 1] = '\0';
        parse_int(fields[2], &entry.rating);
        strncpy(entry.comment, fields[3], sizeof(entry.comment) - 1);
        entry.comment[sizeof(entry.comment) - 1] = '\0';
        entries[idx++] = entry;
    }
    *count = idx;
    return 0;
}

static void print_feedback(const FeedbackRecord *entries, int count) {
    printf("\n%-8s | %-6s | Rating | Comment\n", "FeedID", "ItemID");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%-8s | %-6s | %-6d | %s\n", entries[i].id, entries[i].item_id, entries[i].rating, entries[i].comment);
    }
}

static void update_financials_on_completion(const OrderRecord *order) {
    if (order == NULL) {
        return;
    }

    int next_id = next_identifier_from_lines(FINANCIAL_FILE);
    char entry_id[16];
    generate_id("R", next_id, entry_id, sizeof(entry_id));

    char line[MAX_LINE_LEN];
    snprintf(line, sizeof(line), "%s,%s,%d", entry_id, order->id, order->total_cents);
    append_csv_line(FINANCIAL_FILE, line);
}

static int next_identifier_from_lines(const char *filename) {
    char lines[256][MAX_LINE_LEN];
    int count = read_csv_lines(filename, lines, 256);
    if (count < 0) {
        return 1;
    }
    return count;
}

static void collect_price_input(int *price_cents) {
    char input[32];
    while (1) {
        printf("Enter price (whole units): ");
        safe_input(input, sizeof(input));
        if (parse_int(input, price_cents) == 0 && *price_cents >= 0) {
            break;
        }
        printf("Invalid price. Try again.\n");
    }
}

static void collect_quantity_input(int *quantity) {
    char input[32];
    while (1) {
        printf("Enter quantity: ");
        safe_input(input, sizeof(input));
        if (parse_int(input, quantity) == 0 && *quantity > 0) {
            break;
        }
        printf("Invalid quantity. Try again.\n");
    }
}

static int confirm_choice(const char *message) {
    char input[8];
    printf("%s", message);
    safe_input(input, sizeof(input));
    return (input[0] == 'y' || input[0] == 'Y');
}

static void admin_view(void) {
    char input[16];
    for (;;) {
        printf("\n--- Admin Dashboard ---\n");
        printf("1. Manage Menu\n");
        printf("2. Manage Orders\n");
        printf("3. View Financial Stats\n");
        printf("4. View Feedback\n");
        printf("0. Back\n");
        printf("Choose an option: ");
        safe_input(input, sizeof(input));
        int choice = 0;
        if (parse_int(input, &choice) != 0) {
            printf("Invalid selection.\n");
            continue;
        }

        if (choice == 0) {
            return;
        }
        if (choice == 1) {
            admin_manage_menu();
        } else if (choice == 2) {
            admin_manage_orders();
        } else if (choice == 3) {
            admin_view_financials();
        } else if (choice == 4) {
            admin_view_feedback();
        } else {
            printf("Unknown option.\n");
        }
    }
}

static void client_view(void) {
    char input[16];
    for (;;) {
        printf("\n--- Client Dashboard ---\n");
        printf("1. See Menu\n");
        printf("2. Place Order\n");
        printf("3. Track Order\n");
        printf("4. Cancel/Complete Order\n");
        printf("5. Give Feedback\n");
        printf("0. Back\n");
        printf("Choose an option: ");
        safe_input(input, sizeof(input));
        int choice = 0;
        if (parse_int(input, &choice) != 0) {
            printf("Invalid selection.\n");
            continue;
        }

        if (choice == 0) {
            return;
        }
        if (choice == 1) {
            client_view_menu();
        } else if (choice == 2) {
            client_place_order();
        } else if (choice == 3) {
            client_track_order();
        } else if (choice == 4) {
            client_update_order_status();
        } else if (choice == 5) {
            client_leave_feedback();
        } else {
            printf("Unknown option.\n");
        }
    }
}



int main(void) {
    initialize_data_files();

    char input[16];
    for (;;) {
        printf("\n=== Restaurant Management System ===\n");
        printf("1. Admin View\n");
        printf("2. Client View\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        safe_input(input, sizeof(input));

        int choice = 0;
        if (parse_int(input, &choice) != 0) {
            printf("Invalid selection.\n");
            continue;
        }

        if (choice == 0) {
            printf("Goodbye!\n");
            break;
        }
        if (choice == 1) {
            admin_view();
        } else if (choice == 2) {
            client_view();
        } else {
            printf("Unknown option.\n");
        }
    }

    return 0;
}

