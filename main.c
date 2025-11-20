#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MENU 50
#define MAX_ORDERS 50
#define MAX_FEEDBACK 50
#define MAX_LEN 64
#define ADMIN_PASSWORD "admin123"

// ========== STRUCTURES ==========
struct MenuItem
{
    int id;
    char name[MAX_LEN];
    char category[MAX_LEN];
    int price;
};

struct Order
{
    int id;
    int item_id;
    int qty;
    char status[MAX_LEN];
    char customer[MAX_LEN];
    int total;
};

struct Feedback
{
    int id;
    int item_id;
    int rating;
    char comment[MAX_LEN];
};

// ========== GLOBAL DATA ==========
struct MenuItem menu[MAX_MENU];
int menu_count = 0;

struct Order orders[MAX_ORDERS];
int order_count = 0;

struct Feedback feedbacks[MAX_FEEDBACK];
int feedback_count = 0;

int financial_total = 0;

// ========== UTILITY FUNCTIONS ==========
void clearInputBuffer()
{

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Simple fgets wrapper - reads input and removes newline
void getInput(char *buffer, int size)
{
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

// ========================================================================
// MEMBER 1 (ANAS): MENU & INVENTORY MODULE
// ========================================================================

// Display main menu
void printMainMenu()
{
    printf("\n========================================\n");
    printf("   CP-RMS: RESTAURANT MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Admin Panel\n");
    printf("2. Client Panel\n");
    printf("0. Exit\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

// Display admin menu
void printAdminMenu()
{
    printf("\n========================================\n");
    printf("           ADMIN PANEL\n");
    printf("========================================\n");
    printf("1. View Menu Items\n");
    printf("2. Add New Menu Item\n");
    printf("3. View All Orders\n");
    printf("4. Update Order Status\n");
    printf("5. View Financial Report\n");
    printf("6. View Customer Feedback\n");
    printf("0. Back to Main Menu\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

// Display client menu
void printClientMenu()
{
    printf("\n========================================\n");
    printf("           CLIENT PANEL\n");
    printf("========================================\n");
    printf("1. View Menu\n");
    printf("2. Place Order\n");
    printf("3. Track My Order\n");
    printf("4. Update My Order\n");
    printf("5. Give Feedback\n");
    printf("0. Back to Main Menu\n");
    printf("========================================\n");
    printf("Enter your choice: ");
}

// View all menu items
void viewMenu()
{
    if (menu_count == 0)
    {
        printf("\n[!] No menu items available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("           MENU ITEMS\n");
    printf("========================================\n");
    printf("%-5s %-20s %-15s %-10s\n", "ID", "Name", "Category", "Price");
    printf("----------------------------------------\n");

    for (int i = 0; i < menu_count; i++)
    {
        printf("%-5d %-20s %-15s Rs.%-7d\n",
               menu[i].id,
               menu[i].name,
               menu[i].category,
               menu[i].price);
    }
    printf("========================================\n");
}

// Add new menu item
void addMenuItem()
{
    if (menu_count >= MAX_MENU)
    {
        printf("\n[!] Menu is full. Cannot add more items.\n");
        return;
    }

    char name[MAX_LEN];
    char category[MAX_LEN];
    int price;

    printf("\n--- Add New Menu Item ---\n");

    printf("Enter item name: ");
    clearInputBuffer();
    getInput(name, MAX_LEN); // fgets to allow spaces in names

    printf("Enter category: ");
    getInput(category, MAX_LEN);

    printf("Enter price (Rs): ");
    scanf("%d", &price);

    // Validate price
    if (price <= 0)
    {
        printf("[!] Invalid price. Please enter a positive value.\n");
        return;
    }

    // Add item to menu
    menu[menu_count].id = menu_count + 1;
    strcpy(menu[menu_count].name, name);
    strcpy(menu[menu_count].category, category);
    menu[menu_count].price = price;

    menu_count++;

    printf("[✓] Menu item added successfully! Item ID: %d\n", menu_count);
}

// Save menu to file
void saveMenuToFile()
{
    FILE *file = fopen("menu.txt", "w");
    if (file == NULL)
    {
        return; // Silently fail if file can't be opened
    }

    fprintf(file, "%d\n", menu_count);
    for (int i = 0; i < menu_count; i++)
    {
        fprintf(file, "%d|%s|%s|%d\n",
                menu[i].id, menu[i].name, menu[i].category, menu[i].price);
    }

    fclose(file);
}

// Load menu from file
void loadMenuFromFile()
{
    FILE *file = fopen("menu.txt", "r");
    if (file == NULL)
    {
        return; // No file exists yet
    }

    fscanf(file, "%d\n", &menu_count);
    for (int i = 0; i < menu_count; i++)
    {
        fscanf(file, "%d|%[^|]|%[^|]|%d\n",
               &menu[i].id, menu[i].name, menu[i].category, &menu[i].price);
    }

    fclose(file);
}

// ========================================================================
// MEMBER 2 (NOMAN): ORDERS MODULE
// ========================================================================

// View all orders (Admin)
void viewAllOrders()
{
    if (order_count == 0)
    {
        printf("\n[!] No orders placed yet.\n");
        return;
    }

    printf("\n========================================\n");
    printf("           ALL ORDERS\n");
    printf("========================================\n");
    printf("%-5s %-10s %-5s %-12s %-15s %-10s\n",
           "ID", "Item ID", "Qty", "Status", "Customer", "Total");
    printf("----------------------------------------\n");

    for (int i = 0; i < order_count; i++)
    {
        printf("%-5d %-10d %-5d %-12s %-15s Rs.%-7d\n",
               orders[i].id,
               orders[i].item_id,
               orders[i].qty,
               orders[i].status,
               orders[i].customer,
               orders[i].total);
    }
    printf("========================================\n");
}

// Find menu item by ID
int findMenuItem(int item_id)
{
    for (int i = 0; i < menu_count; i++)
    {
        if (menu[i].id == item_id)
        {
            return i; // Return index
        }
    }
    return -1; // Not found
}

// Place new order (Client)
void placeOrder()
{
    if (order_count >= MAX_ORDERS)
    {
        printf("\n[!] Order limit reached. Cannot place more orders.\n");
        return;
    }

    if (menu_count == 0)
    {
        printf("\n[!] No menu items available. Cannot place order.\n");
        return;
    }

    int item_id, qty;
    char customer[MAX_LEN];

    printf("\n--- Place Your Order ---\n");

    printf("Enter Item ID: ");
    scanf("%d", &item_id);

    int index = findMenuItem(item_id);
    if (index == -1)
    {
        printf("[!] Invalid Item ID. Please check the menu.\n");
        return;
    }

    printf("Enter Quantity: ");
    scanf("%d", &qty);

    // Validate quantity
    if (qty <= 0)
    {
        printf("[!] Invalid quantity. Please enter a positive number.\n");
        return;
    }

    printf("Enter Customer Name: ");
    clearInputBuffer();
    getInput(customer, MAX_LEN); // fgets to allow spaces in names

    // Create order
    orders[order_count].id = order_count + 1;
    orders[order_count].item_id = item_id;
    orders[order_count].qty = qty;
    strcpy(orders[order_count].customer, customer);
    strcpy(orders[order_count].status, "Pending");
    orders[order_count].total = menu[index].price * qty;

    printf("\n[✓] Order placed successfully!\n");
    printf("    Order ID: %d\n", orders[order_count].id);
    printf("    Total Amount: Rs.%d\n", orders[order_count].total);

    order_count++;
}

// Track order status (Client)
void trackOrder()
{
    if (order_count == 0)
    {
        printf("\n[!] No orders placed yet.\n");
        return;
    }

    int order_id;

    printf("\n--- Track Your Order ---\n");
    printf("Enter Order ID: ");
    scanf("%d", &order_id);

    int found = 0;
    for (int i = 0; i < order_count; i++)
    {
        if (orders[i].id == order_id)
        {
            printf("\n========================================\n");
            printf("Order ID: %d\n", orders[i].id);
            printf("Customer: %s\n", orders[i].customer);
            printf("Item ID: %d\n", orders[i].item_id);
            printf("Quantity: %d\n", orders[i].qty);
            printf("Total: Rs.%d\n", orders[i].total);
            printf("Status: %s\n", orders[i].status);
            printf("========================================\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("[!] Order not found. Please check your Order ID.\n");
    }
}

// Update order status (Admin)
void updateOrderStatus()
{
    if (order_count == 0)
    {
        printf("\n[!] No orders available to update.\n");
        return;
    }

    int order_id;
    char status[MAX_LEN];

    printf("\n--- Update Order Status ---\n");
    printf("Enter Order ID: ");
    scanf("%d", &order_id);

    int found = 0;
    for (int i = 0; i < order_count; i++)
    {
        if (orders[i].id == order_id)
        {
            printf("Current Status: %s\n", orders[i].status);
            printf("Enter New Status (Pending/Preparing/Completed/Cancelled): ");
            clearInputBuffer();
            getInput(status, MAX_LEN);

            strcpy(orders[i].status, status);

            // Update financial if completed
            if (strcmp(status, "Completed") == 0)
            {
                financial_total += orders[i].total;
            }

            printf("[✓] Order status updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("[!] Order not found. Please check the Order ID.\n");
    }
}

// Update order by client
void clientUpdateOrder()
{
    if (order_count == 0)
    {
        printf("\n[!] No orders available to update.\n");
        return;
    }

    int order_id, action;

    printf("\n--- Update Your Order ---\n");
    printf("Enter Order ID: ");
    scanf("%d", &order_id);

    int found = 0;
    for (int i = 0; i < order_count; i++)
    {
        if (orders[i].id == order_id)
        {
            printf("Current Status: %s\n", orders[i].status);
            printf("\n1. Mark as Completed\n");
            printf("2. Cancel Order\n");
            printf("Enter action: ");
            scanf("%d", &action);

            if (action == 1)
            {
                strcpy(orders[i].status, "Completed");
                financial_total += orders[i].total;
                printf("[✓] Order marked as completed!\n");
            }
            else if (action == 2)
            {
                strcpy(orders[i].status, "Cancelled");
                printf("[✓] Order cancelled successfully!\n");
            }
            else
            {
                printf("[!] Invalid action.\n");
            }

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("[!] Order not found. Please check your Order ID.\n");
    }
}

// Save orders to file
void saveOrdersToFile()
{
    FILE *file = fopen("orders.txt", "w");
    if (file == NULL)
    {
        return;
    }

    fprintf(file, "%d\n", order_count);
    for (int i = 0; i < order_count; i++)
    {
        fprintf(file, "%d|%d|%d|%s|%s|%d\n",
                orders[i].id, orders[i].item_id, orders[i].qty,
                orders[i].status, orders[i].customer, orders[i].total);
    }

    fclose(file);
}

// Load orders from file
void loadOrdersFromFile()
{
    FILE *file = fopen("orders.txt", "r");
    if (file == NULL)
    {
        return;
    }

    fscanf(file, "%d\n", &order_count);
    for (int i = 0; i < order_count; i++)
    {
        fscanf(file, "%d|%d|%d|%[^|]|%[^|]|%d\n",
               &orders[i].id, &orders[i].item_id, &orders[i].qty,
               orders[i].status, orders[i].customer, &orders[i].total);
    }

    fclose(file);
}

// ========================================================================
// MEMBER 3 (ALI): FEEDBACK & FINANCIALS MODULE
// ========================================================================

// View all feedback (Admin)
void viewAllFeedback()
{
    if (feedback_count == 0)
    {
        printf("\n[!] No feedback available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("         CUSTOMER FEEDBACK\n");
    printf("========================================\n");
    printf("%-5s %-10s %-8s %-30s\n", "ID", "Item ID", "Rating", "Comment");
    printf("----------------------------------------\n");

    for (int i = 0; i < feedback_count; i++)
    {
        printf("%-5d %-10d %-8d %-30s\n",
               feedbacks[i].id,
               feedbacks[i].item_id,
               feedbacks[i].rating,
               feedbacks[i].comment);
    }
    printf("========================================\n");
}

// Give feedback (Client)
void giveFeedback()
{
    if (feedback_count >= MAX_FEEDBACK)
    {
        printf("\n[!] Feedback limit reached.\n");
        return;
    }

    if (menu_count == 0)
    {
        printf("\n[!] No menu items available. Cannot give feedback.\n");
        return;
    }

    int item_id, rating;
    char comment[MAX_LEN];

    printf("\n--- Give Your Feedback ---\n");

    printf("Enter Item ID: ");
    scanf("%d", &item_id);

    int index = findMenuItem(item_id);
    if (index == -1)
    {
        printf("[!] Invalid Item ID. Please check the menu.\n");
        return;
    }

    printf("Enter Rating (1-5): ");
    scanf("%d", &rating);

    // Validate rating
    if (rating < 1 || rating > 5)
    {
        printf("[!] Invalid rating. Please enter a value between 1 and 5.\n");
        return;
    }

    printf("Enter Comment: ");
    clearInputBuffer();
    getInput(comment, MAX_LEN); // fgets to allow spaces in comments

    // Save feedback
    feedbacks[feedback_count].id = feedback_count + 1;
    feedbacks[feedback_count].item_id = item_id;
    feedbacks[feedback_count].rating = rating;
    strcpy(feedbacks[feedback_count].comment, comment);

    feedback_count++;

    printf("[✓] Thank you for your feedback!\n");
}

// View financial report (Admin)
void viewFinancialReport()
{
    printf("\n========================================\n");
    printf("         FINANCIAL REPORT\n");
    printf("========================================\n");

    if (order_count == 0)
    {
        printf("Total Orders: 0\n");
        printf("Total Revenue: Rs.0\n");
    }
    else
    {
        int completed_orders = 0;
        int pending_orders = 0;
        int cancelled_orders = 0;

        for (int i = 0; i < order_count; i++)
        {
            if (strcmp(orders[i].status, "Completed") == 0)
            {
                completed_orders++;
            }
            else if (strcmp(orders[i].status, "Cancelled") == 0)
            {
                cancelled_orders++;
            }
            else
            {
                pending_orders++;
            }
        }

        printf("Total Orders: %d\n", order_count);
        printf("Completed Orders: %d\n", completed_orders);
        printf("Pending Orders: %d\n", pending_orders);
        printf("Cancelled Orders: %d\n", cancelled_orders);
        printf("\nTotal Revenue: Rs.%d\n", financial_total);
    }

    printf("========================================\n");
}

// Save feedback to file
void saveFeedbackToFile()
{
    FILE *file = fopen("feedback.txt", "w");
    if (file == NULL)
    {
        return;
    }

    fprintf(file, "%d\n", feedback_count);
    for (int i = 0; i < feedback_count; i++)
    {
        fprintf(file, "%d|%d|%d|%s\n",
                feedbacks[i].id, feedbacks[i].item_id,
                feedbacks[i].rating, feedbacks[i].comment);
    }

    fclose(file);
}

// Load feedback from file
void loadFeedbackFromFile()
{
    FILE *file = fopen("feedback.txt", "r");
    if (file == NULL)
    {
        return;
    }

    fscanf(file, "%d\n", &feedback_count);
    for (int i = 0; i < feedback_count; i++)
    {
        fscanf(file, "%d|%d|%d|%[^\n]\n",
               &feedbacks[i].id, &feedbacks[i].item_id,
               &feedbacks[i].rating, feedbacks[i].comment);
    }

    fclose(file);
}

// Save financial data
void saveFinancialToFile()
{
    FILE *file = fopen("financial.txt", "w");
    if (file == NULL)
    {
        return;
    }

    fprintf(file, "%d\n", financial_total);
    fclose(file);
}

// Load financial data
void loadFinancialFromFile()
{
    FILE *file = fopen("financial.txt", "r");
    if (file == NULL)
    {
        return;
    }

    fscanf(file, "%d", &financial_total);
    fclose(file);
}

// ========================================================================
// ADMIN & CLIENT PANEL HANDLERS
// ========================================================================

// Admin authentication
int adminLogin()
{
    char password[MAX_LEN];

    printf("\n--- Admin Login ---\n");
    printf("Enter Password: ");
    clearInputBuffer();
    getInput(password, MAX_LEN);

    if (strcmp(password, ADMIN_PASSWORD) == 0)
    {
        printf("[✓] Login successful!\n");
        return 1;
    }
    else
    {
        printf("[!] Incorrect password. Access denied.\n");
        return 0;
    }
}

// Admin panel handler
void adminPanel()
{
    if (!adminLogin())
    {
        return; // Exit if authentication fails
    }

    int choice;

    while (1)
    {
        printAdminMenu();
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("Returning to main menu...\n");
            break;
        }
        else if (choice == 1)
        {
            viewMenu();
        }
        else if (choice == 2)
        {
            addMenuItem();
        }
        else if (choice == 3)
        {
            viewAllOrders();
        }
        else if (choice == 4)
        {
            updateOrderStatus();
        }
        else if (choice == 5)
        {
            viewFinancialReport();
        }
        else if (choice == 6)
        {
            viewAllFeedback();
        }
        else
        {
            printf("[!] Invalid choice. Please try again.\n");
        }
    }
}

// Client panel handler
void clientPanel()
{
    int choice;

    while (1)
    {
        printClientMenu();
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("Returning to main menu...\n");
            break;
        }
        else if (choice == 1)
        {
            viewMenu();
        }
        else if (choice == 2)
        {
            placeOrder();
        }
        else if (choice == 3)
        {
            trackOrder();
        }
        else if (choice == 4)
        {
            clientUpdateOrder();
        }
        else if (choice == 5)
        {
            giveFeedback();
        }
        else
        {
            printf("[!] Invalid choice. Please try again.\n");
        }
    }
}

// Save all data to files
void saveAllData()
{
    saveMenuToFile();
    saveOrdersToFile();
    saveFeedbackToFile();
    saveFinancialToFile();
}

// Load all data from files
void loadAllData()
{
    loadMenuFromFile();
    loadOrdersFromFile();
    loadFeedbackFromFile();
    loadFinancialFromFile();
}

// ========================================================================
// MAIN FUNCTION
// ========================================================================

int main()
{
    int choice;

    // Load existing data from files
    loadAllData();

    printf("\n");
    printf("*****************************************\n");
    printf("*  WELCOME TO CP-RMS                   *\n");
    printf("*  Restaurant Management System        *\n");
    printf("*****************************************\n");

    while (1)
    {
        printMainMenu();
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("\nSaving data...\n");
            saveAllData();
            printf("Thank you for using CP-RMS!\n");
            printf("Goodbye!\n");
            break;
        }
        else if (choice == 1)
        {
            adminPanel();
        }
        else if (choice == 2)
        {
            clientPanel();
        }
        else
        {
            printf("[!] Invalid choice. Please enter 0, 1, or 2.\n");
        }
    }

    return 0;
}