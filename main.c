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
/*
 * Parameters: None
 * Functionality: Clears the input buffer by reading and discarding all characters 
 *                until a newline or EOF is encountered
 * Return: void (no return value)
 */

void getInput(char *buffer, int size)
{
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}
/*
 * Parameters: 
 *   - buffer: pointer to character array where input will be stored
 *   - size: maximum number of characters to read (including null terminator)
 * Functionality: Reads a line of input from stdin using fgets and removes the 
 *                trailing newline character
 * Return: void (no return value)
 */

// ========================================================================
// MEMBER 1 (ANAS): MENU & INVENTORY MODULE
// ========================================================================

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
/*
 * Parameters: None
 * Functionality: Displays the main menu interface with options for Admin Panel,
 *                Client Panel, and Exit
 * Return: void (no return value)
 */

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
/*
 * Parameters: None
 * Functionality: Displays the admin panel menu with options to manage menu items,
 *                orders, financial reports, and customer feedback
 * Return: void (no return value)
 */

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
/*
 * Parameters: None
 * Functionality: Displays the client panel menu with options to view menu, 
 *                place orders, track orders, update orders, and give feedback
 * Return: void (no return value)
 */

void viewMenu()
{
    if (menu_count == 0)
    {
        printf("\n No menu items available.\n");
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
/*
 * Parameters: None
 * Functionality: Displays all menu items in a formatted table showing ID, name,
 *                category, and price. Shows a message if no items are available
 * Return: void (no return value)
 */

void addMenuItem()
{
    if (menu_count >= MAX_MENU)
    {
        printf("\n Menu is full. Cannot add more items.\n");
        return;
    }

    char name[MAX_LEN];
    char category[MAX_LEN];
    int price;

    printf("\n--- Add New Menu Item ---\n");

    printf("Enter item name: ");
    clearInputBuffer();
    getInput(name, MAX_LEN);

    printf("Enter category: ");
    getInput(category, MAX_LEN);

    printf("Enter price (Rs): ");
    scanf("%d", &price);

    if (price <= 0)
    {
        printf(" Invalid price. Please enter a positive value.\n");
        return;
    }

    menu[menu_count].id = menu_count + 1;
    strcpy(menu[menu_count].name, name);
    strcpy(menu[menu_count].category, category);
    menu[menu_count].price = price;
    menu_count++;

    printf("Menu item added successfully! Item ID: %d\n", menu_count);
}
/*
 * Parameters: None (takes user input interactively)
 * Functionality: Prompts admin to enter details for a new menu item (name, category, price),
 *                validates the input, and adds the item to the menu array. Assigns a unique ID
 *                and increments menu_count
 * Return: void (no return value)
 */

void saveMenuToFile()
{
    FILE *file = fopen("menu.txt", "w");
    if (file == NULL)
    {
        return;
    }

    fprintf(file, "%d\n", menu_count);
    for (int i = 0; i < menu_count; i++)
    {
        fprintf(file, "%d|%s|%s|%d\n",
                menu[i].id, menu[i].name, menu[i].category, menu[i].price);
    }

    fclose(file);
}
/*
 * Parameters: None
 * Functionality: Saves all menu items to "menu.txt" file in pipe-delimited format.
 *                First line contains menu_count, followed by each item's data
 * Return: void (no return value)
 */

void loadMenuFromFile()
{
    FILE *file = fopen("menu.txt", "r");
    if (file == NULL)
    {
        return;
    }

    fscanf(file, "%d\n", &menu_count);
    for (int i = 0; i < menu_count; i++)
    {
        fscanf(file, "%d|%[^|]|%[^|]|%d\n",
               &menu[i].id, menu[i].name, menu[i].category, &menu[i].price);
    }

    fclose(file);
}
/*
 * Parameters: None
 * Functionality: Loads menu items from "menu.txt" file into the menu array.
 *                Reads menu_count first, then parses each pipe-delimited line
 * Return: void (no return value)
 */

// ========================================================================
// MEMBER 2 (NOMAN): ORDERS MODULE
// ========================================================================

void viewAllOrders()
{
    if (order_count == 0)
    {
        printf("\n No orders placed yet.\n");
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
/*
 * Parameters: None
 * Functionality: Displays all orders in a formatted table showing order ID, item ID,
 *                quantity, status, customer name, and total price
 * Return: void (no return value)
 */

int findMenuItem(int item_id)
{
    for (int i = 0; i < menu_count; i++)
    {
        if (menu[i].id == item_id)
        {
            return i;
        }
    }
    return -1;
}
/*
 * Parameters: 
 *   - item_id: integer representing the menu item ID to search for
 * Functionality: Searches the menu array for an item with the given ID
 * Return: integer - returns the array index if found, -1 if not found
 */

void placeOrder()
{
    if (order_count >= MAX_ORDERS)
    {
        printf("\n Order limit reached. Cannot place more orders.\n");
        return;
    }

    if (menu_count == 0)
    {
        printf("\n No menu items available. Cannot place order.\n");
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
        printf(" Invalid Item ID. Please check the menu.\n");
        return;
    }

    printf("Enter Quantity: ");
    scanf("%d", &qty);

    if (qty <= 0)
    {
        printf(" Invalid quantity. Please enter a positive number.\n");
        return;
    }

    printf("Enter Customer Name: ");
    clearInputBuffer();
    getInput(customer, MAX_LEN);

    orders[order_count].id = order_count + 1;
    orders[order_count].item_id = item_id;
    orders[order_count].qty = qty;
    strcpy(orders[order_count].customer, customer);
    strcpy(orders[order_count].status, "Pending");
    orders[order_count].total = menu[index].price * qty;

    printf("\nOrder placed successfully!\n");
    printf("    Order ID: %d\n", orders[order_count].id);
    printf("    Total Amount: Rs.%d\n", orders[order_count].total);

    order_count++;
}
/*
 * Parameters: None (takes user input interactively)
 * Functionality: Allows a client to place a new order by entering item ID, quantity,
 *                and customer name. Validates input, calculates total price, assigns
 *                a unique order ID, sets initial status to "Pending", and increments order_count
 * Return: void (no return value)
 */

void trackOrder()
{
    if (order_count == 0)
    {
        printf("\n No orders placed yet.\n");
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
        printf(" Order not found. Please check your Order ID.\n");
    }
}
/*
 * Parameters: None (takes user input interactively)
 * Functionality: Allows a client to track their order by entering an order ID.
 *                Searches for the order and displays its complete details including
 *                status, customer, item, quantity, and total
 * Return: void (no return value)
 */

void updateOrderStatus()
{
    if (order_count == 0)
    {
        printf("\n No orders available to update.\n");
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

            if (strcmp(status, "Completed") == 0)
            {
                financial_total += orders[i].total;
            }

            printf("Order status updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf(" Order not found. Please check the Order ID.\n");
    }
}
/*
 * Parameters: None (takes user input interactively)
 * Functionality: Allows admin to update an order's status by entering order ID and
 *                new status. If status is set to "Completed", adds order total to
 *                financial_total
 * Return: void (no return value)
 */

void clientUpdateOrder()
{
    if (order_count == 0)
    {
        printf("\n No orders available to update.\n");
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
                printf("Order marked as completed!\n");
            }
            else if (action == 2)
            {
                strcpy(orders[i].status, "Cancelled");
                printf("Order cancelled successfully!\n");
            }
            else
            {
                printf(" Invalid action.\n");
            }

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf(" Order not found. Please check your Order ID.\n");
    }
}
/*
 * Parameters: None (takes user input interactively)
 * Functionality: Allows a client to update their own order status. Provides two options:
 *                mark as completed (adds to financial_total) or cancel the order
 * Return: void (no return value)
 */

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
/*
 * Parameters: None
 * Functionality: Saves all orders to "orders.txt" file in pipe-delimited format.
 *                First line contains order_count, followed by each order's data
 * Return: void (no return value)
 */

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
/*
 * Parameters: None
 * Functionality: Loads orders from "orders.txt" file into the orders array.
 *                Reads order_count first, then parses each pipe-delimited line
 * Return: void (no return value)
 */

// ========================================================================
// MEMBER 3 (ALI): FEEDBACK & FINANCIALS MODULE
// ========================================================================

void viewAllFeedback()
{
    if (feedback_count == 0)
    {
        printf("\n No feedback available.\n");
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
/*
 * Parameters: None
 * Functionality: Displays all customer feedback in a formatted table showing feedback ID,
 *                item ID, rating, and comment
 * Return: void (no return value)
 */

void giveFeedback()
{
    if (feedback_count >= MAX_FEEDBACK)
    {
        printf("\n Feedback limit reached.\n");
        return;
    }

    if (menu_count == 0)
    {
        printf("\n No menu items available. Cannot give feedback.\n");
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
        printf(" Invalid Item ID. Please check the menu.\n");
        return;
    }

    printf("Enter Rating (1-5): ");
    scanf("%d", &rating);

    if (rating < 1 || rating > 5)
    {
        printf(" Invalid rating. Please enter a value between 1 and 5.\n");
        return;
    }

    printf("Enter Comment: ");
    clearInputBuffer();
    getInput(comment, MAX_LEN);

    feedbacks[feedback_count].id = feedback_count + 1;
    feedbacks[feedback_count].item_id = item_id;
    feedbacks[feedback_count].rating = rating;
    strcpy(feedbacks[feedback_count].comment, comment);

    feedback_count++;

    printf("Thank you for your feedback!\n");
}
/*
 * Parameters: None (takes user input interactively)
 * Functionality: Allows a client to give feedback on a menu item by entering item ID,
 *                rating (1-5), and comment. Validates input, assigns a unique feedback ID,
 *                and increments feedback_count
 * Return: void (no return value)
 */

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
/*
 * Parameters: None
 * Functionality: Displays a financial report showing total orders, breakdown by status
 *                (completed, pending, cancelled), and total revenue from completed orders
 * Return: void (no return value)
 */

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
/*
 * Parameters: None
 * Functionality: Saves all feedback to "feedback.txt" file in pipe-delimited format.
 *                First line contains feedback_count, followed by each feedback's data
 * Return: void (no return value)
 */

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
/*
 * Parameters: None
 * Functionality: Loads feedback from "feedback.txt" file into the feedbacks array.
 *                Reads feedback_count first, then parses each pipe-delimited line
 * Return: void (no return value)
 */

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
/*
 * Parameters: None
 * Functionality: Saves the financial_total (total revenue) to "financial.txt" file
 * Return: void (no return value)
 */

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
/*
 * Parameters: None
 * Functionality: Loads the financial_total (total revenue) from "financial.txt" file
 * Return: void (no return value)
 */

// ========================================================================
// ADMIN & CLIENT PANEL HANDLERS
// ========================================================================

int adminLogin()
{
    char password[MAX_LEN];

    printf("\n--- Admin Login ---\n");
    printf("Enter Password: ");
    clearInputBuffer();
    getInput(password, MAX_LEN);

    if (strcmp(password, ADMIN_PASSWORD) == 0)
    {
        printf("Login successful!\n");
        return 1;
    }
    else
    {
        printf(" Incorrect password. Access denied.\n");
        return 0;
    }
}
/*
 * Parameters: None (takes user input interactively)
 * Functionality: Prompts for admin password and validates it against ADMIN_PASSWORD constant.
 *                Displays success or failure message
 * Return: integer - returns 1 if authentication successful, 0 if failed
 */

void adminPanel()
{
    if (!adminLogin())
    {
        return;
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
            printf(" Invalid choice. Please try again.\n");
        }
    }
}
/*
 * Parameters: None
 * Functionality: Handles the admin panel interface. First authenticates the admin,
 *                then displays menu and processes admin choices in a loop until
 *                user chooses to exit back to main menu
 * Return: void (no return value)
 */

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
            printf(" Invalid choice. Please try again.\n");
        }
    }
}
/*
 * Parameters: None
 * Functionality: Handles the client panel interface. Displays menu and processes
 *                client choices in a loop until user chooses to exit back to main menu
 * Return: void (no return value)
 */

void saveAllData()
{
    saveMenuToFile();
    saveOrdersToFile();
    saveFeedbackToFile();
    saveFinancialToFile();
}
/*
 * Parameters: None
 * Functionality: Calls all save functions to persist menu, orders, feedback, and
 *                financial data to their respective files
 * Return: void (no return value)
 */

void loadAllData()
{
    loadMenuFromFile();
    loadOrdersFromFile();
    loadFeedbackFromFile();
    loadFinancialFromFile();
}
/*
 * Parameters: None
 * Functionality: Calls all load functions to retrieve menu, orders, feedback, and
 *                financial data from their respective files at program startup
 * Return: void (no return value)
 */

// ========================================================================
// MAIN FUNCTION
// ========================================================================

int main()
{
    int choice;

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
            printf(" Invalid choice. Please enter 0, 1, or 2.\n");
        }
    }

    return 0;
}
/*
 * Parameters: None (standard main function)
 * Functionality: Entry point of the program. Loads existing data from files, displays
 *                welcome message, runs main menu loop allowing user to access admin or
 *                client panels, and saves all data before exiting
 * Return: integer - returns 0 to indicate successful program termination
 */