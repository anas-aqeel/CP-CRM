# Sample Code Structure (Reference Only)

## 🧭 Navigation

**You are here:** SAMPLE_CODE_STRUCTURE

**Other Documents:**
- [README](../../README.md)
- [PROJECT_DOCUMENTATION](../PROJECT_DOCUMENTATION/readme.md)
- [SYSTEM_ARCHITECTURE](../SYSTEM_ARCHITECTURE/readme.md)
- [DATA_STRUCTURES_GUIDE](../DATA_STRUCTURES_GUIDE/readme.md)

---

## This file shows how the C program structure would look like
## DO NOT implement yet - this is just for planning!

---

## Main Program Structure

```c
#include <stdio.h>
#include <string.h>

// ============================================
//          GLOBAL DATA STRUCTURES
// ============================================

// INVENTORY SYSTEM (Member 1)
char inventory_names[100][50];
int inventory_quantities[100];
float inventory_prices[100];
int inventory_count = 0;

// MENU SYSTEM (Member 1)
char menu_items[50][50];
float menu_prices[50];
int menu_categories[50];  // 1=Appetizer, 2=Main, 3=Beverage, 4=Dessert
int menu_count = 0;

// ORDER SYSTEM (Member 2)
int order_ids[200];
int order_table_numbers[200];
int order_items[200][10];      // Each order can have up to 10 items
int order_quantities[200][10];
int order_item_counts[200];    // How many items in each order
float order_amounts[200];
int order_statuses[200];       // 1=Pending, 2=Preparing, 3=Ready, 4=Served, 5=Rejected
float order_tips[200];
int order_count = 0;

// BOOKING SYSTEM (Member 2)
int booking_ids[100];
char booking_names[100][50];
char booking_phones[100][15];
int booking_table_numbers[100];
int booking_guest_counts[100];
int booking_statuses[100];     // 1=Confirmed, 2=Completed, 3=Cancelled
int booking_count = 0;

// STAFF SYSTEM (Member 3)
int staff_ids[20];
char staff_names[20][50];
int staff_roles[20];           // 1=Chef, 2=Waiter, 3=Helper
char staff_phones[20][15];
float staff_salaries[20];
int staff_attendance[20];      // Days present this month
int staff_count = 0;

// FINANCIAL SYSTEM (Member 3)
float total_revenue = 0.0;
float total_expenses = 0.0;
float total_tips = 0.0;
float monthly_investment = 0.0;

// ============================================
//        FUNCTION DECLARATIONS
// ============================================

// Main Functions
void displayWelcome();
void mainMenu();
void adminMenu();
void userMenu();

// MEMBER 1 - Inventory Functions
void addInventoryItem();
void viewInventory();
void updateInventory();
void checkLowStock();
float calculateInventoryValue();

// MEMBER 1 - Menu Functions
void addMenuItem();
void viewMenu();
void viewMenuByCategory();
void searchMenuItem();

// MEMBER 2 - Order Functions
void createOrder();
void viewAllOrders();
void updateOrderStatus();
void completeOrder();
void rejectOrder();
void trackOrder();
float calculateOrderTotal(int orderIndex);
void addTipToOrder();

// MEMBER 2 - Booking Functions
void createBooking();
void viewAllBookings();
void cancelBooking();
void checkTableAvailability();
void updateBookingStatus();

// MEMBER 3 - Staff Functions
void addStaff();
void viewAllStaff();
void markAttendance();
void calculateSalary();
void viewStaffPerformance();

// MEMBER 3 - Financial Functions
float calculateMonthlyRevenue();
float calculateTotalExpenses();
float calculateProfit();
void displayFinancialStats();
float calculateAverageOrderValue();
float getTotalTips();
int getCompletedOrdersCount();
int getRejectedOrdersCount();
float calculateROI();

// Utility Functions
void clearScreen();
void pressEnterToContinue();

// ============================================
//              MAIN FUNCTION
// ============================================

int main() {
    displayWelcome();
    mainMenu();
    return 0;
}

// ============================================
//          MAIN MENU FUNCTIONS
// ============================================

void displayWelcome() {
    printf("\n");
    printf("========================================\n");
    printf("    GOLDEN SPOON DINER - RMS\n");
    printf("  Restaurant Management System\n");
    printf("========================================\n");
    printf("\n");
}

void mainMenu() {
    int choice;
    
    while(1) {
        printf("\n");
        printf("========================================\n");
        printf("           MAIN MENU\n");
        printf("========================================\n");
        printf("1. Admin Login\n");
        printf("2. Customer Interface\n");
        printf("3. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            adminMenu();
        } else if(choice == 2) {
            userMenu();
        } else if(choice == 3) {
            printf("\nThank you for using Golden Spoon Diner RMS!\n");
            break;
        } else {
            printf("\nInvalid choice! Please try again.\n");
        }
    }
}

void adminMenu() {
    int choice;
    
    while(1) {
        printf("\n");
        printf("========================================\n");
        printf("         ADMIN DASHBOARD\n");
        printf("========================================\n");
        printf("1. Inventory Management\n");
        printf("2. Order Management\n");
        printf("3. Booking Management\n");
        printf("4. Staff Management\n");
        printf("5. Financial Statistics\n");
        printf("6. Menu Management\n");
        printf("7. Logout\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            // Inventory submenu
            int invChoice;
            printf("\n--- Inventory Management ---\n");
            printf("1. Add Item\n");
            printf("2. View Inventory\n");
            printf("3. Update Stock\n");
            printf("4. Check Low Stock\n");
            printf("Enter choice: ");
            scanf("%d", &invChoice);
            
            if(invChoice == 1) addInventoryItem();
            else if(invChoice == 2) viewInventory();
            else if(invChoice == 3) updateInventory();
            else if(invChoice == 4) checkLowStock();
            
        } else if(choice == 2) {
            // Order management submenu
            int ordChoice;
            printf("\n--- Order Management ---\n");
            printf("1. View All Orders\n");
            printf("2. Update Order Status\n");
            printf("Enter choice: ");
            scanf("%d", &ordChoice);
            
            if(ordChoice == 1) viewAllOrders();
            else if(ordChoice == 2) updateOrderStatus();
            
        } else if(choice == 3) {
            // Booking management submenu
            int bookChoice;
            printf("\n--- Booking Management ---\n");
            printf("1. View All Bookings\n");
            printf("2. Create Booking\n");
            printf("3. Cancel Booking\n");
            printf("4. Check Availability\n");
            printf("Enter choice: ");
            scanf("%d", &bookChoice);
            
            if(bookChoice == 1) viewAllBookings();
            else if(bookChoice == 2) createBooking();
            else if(bookChoice == 3) cancelBooking();
            else if(bookChoice == 4) checkTableAvailability();
            
        } else if(choice == 4) {
            // Staff management submenu
            int staffChoice;
            printf("\n--- Staff Management ---\n");
            printf("1. Add Staff\n");
            printf("2. View All Staff\n");
            printf("3. Mark Attendance\n");
            printf("4. Calculate Salary\n");
            printf("Enter choice: ");
            scanf("%d", &staffChoice);
            
            if(staffChoice == 1) addStaff();
            else if(staffChoice == 2) viewAllStaff();
            else if(staffChoice == 3) markAttendance();
            else if(staffChoice == 4) calculateSalary();
            
        } else if(choice == 5) {
            displayFinancialStats();
            
        } else if(choice == 6) {
            // Menu management
            int menuChoice;
            printf("\n--- Menu Management ---\n");
            printf("1. Add Menu Item\n");
            printf("2. View Menu\n");
            printf("Enter choice: ");
            scanf("%d", &menuChoice);
            
            if(menuChoice == 1) addMenuItem();
            else if(menuChoice == 2) viewMenu();
            
        } else if(choice == 7) {
            printf("\nLogging out...\n");
            break;
        } else {
            printf("\nInvalid choice!\n");
        }
    }
}

void userMenu() {
    int choice;
    
    while(1) {
        printf("\n");
        printf("========================================\n");
        printf("        CUSTOMER INTERFACE\n");
        printf("========================================\n");
        printf("1. View Menu\n");
        printf("2. Place Order\n");
        printf("3. Track Order\n");
        printf("4. Complete/Reject Order\n");
        printf("5. Back to Main Menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            viewMenu();
        } else if(choice == 2) {
            createOrder();
        } else if(choice == 3) {
            trackOrder();
        } else if(choice == 4) {
            int ordId;
            int action;
            printf("\nEnter Order ID: ");
            scanf("%d", &ordId);
            printf("1. Complete Order\n");
            printf("2. Reject Order\n");
            printf("Enter action: ");
            scanf("%d", &action);
            
            if(action == 1) completeOrder();
            else if(action == 2) rejectOrder();
            
        } else if(choice == 5) {
            break;
        } else {
            printf("\nInvalid choice!\n");
        }
    }
}

// ============================================
//      MEMBER 1 - INVENTORY FUNCTIONS
// ============================================

void addInventoryItem() {
    if(inventory_count >= 100) {
        printf("\nInventory is full!\n");
        return;
    }
    
    printf("\n--- Add Inventory Item ---\n");
    printf("Enter item name: ");
    scanf("%s", inventory_names[inventory_count]);
    
    printf("Enter quantity: ");
    scanf("%d", &inventory_quantities[inventory_count]);
    
    printf("Enter price per unit: ");
    scanf("%f", &inventory_prices[inventory_count]);
    
    inventory_count++;
    
    printf("\nItem added successfully!\n");
}

void viewInventory() {
    printf("\n");
    printf("========================================\n");
    printf("          INVENTORY LIST\n");
    printf("========================================\n");
    
    if(inventory_count == 0) {
        printf("No items in inventory!\n");
        return;
    }
    
    printf("%-20s %-10s %-10s\n", "Item Name", "Quantity", "Price");
    printf("----------------------------------------\n");
    
    for(int i = 0; i < inventory_count; i++) {
        printf("%-20s %-10d $%-9.2f\n", 
               inventory_names[i], 
               inventory_quantities[i], 
               inventory_prices[i]);
    }
    
    printf("========================================\n");
}

void updateInventory() {
    char itemName[50];
    int newQuantity;
    int found = 0;
    
    printf("\nEnter item name to update: ");
    scanf("%s", itemName);
    
    for(int i = 0; i < inventory_count; i++) {
        if(strcmp(inventory_names[i], itemName) == 0) {
            printf("Current quantity: %d\n", inventory_quantities[i]);
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            inventory_quantities[i] = newQuantity;
            printf("Inventory updated!\n");
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("Item not found!\n");
    }
}

void checkLowStock() {
    int threshold = 10;
    int lowStockCount = 0;
    
    printf("\n--- Low Stock Alert ---\n");
    printf("Items with stock below %d:\n\n", threshold);
    
    for(int i = 0; i < inventory_count; i++) {
        if(inventory_quantities[i] < threshold) {
            printf("%s: %d units remaining\n", 
                   inventory_names[i], 
                   inventory_quantities[i]);
            lowStockCount++;
        }
    }
    
    if(lowStockCount == 0) {
        printf("All items are well stocked!\n");
    }
}

float calculateInventoryValue() {
    float totalValue = 0.0;
    
    for(int i = 0; i < inventory_count; i++) {
        totalValue += inventory_quantities[i] * inventory_prices[i];
    }
    
    return totalValue;
}

// ============================================
//      MEMBER 1 - MENU FUNCTIONS
// ============================================

void addMenuItem() {
    if(menu_count >= 50) {
        printf("\nMenu is full!\n");
        return;
    }
    
    printf("\n--- Add Menu Item ---\n");
    printf("Enter item name: ");
    scanf("%s", menu_items[menu_count]);
    
    printf("Enter price: ");
    scanf("%f", &menu_prices[menu_count]);
    
    printf("Enter category (1=Appetizer, 2=Main, 3=Beverage, 4=Dessert): ");
    scanf("%d", &menu_categories[menu_count]);
    
    menu_count++;
    
    printf("\nMenu item added successfully!\n");
}

void viewMenu() {
    printf("\n");
    printf("========================================\n");
    printf("              MENU\n");
    printf("========================================\n");
    
    if(menu_count == 0) {
        printf("No items in menu!\n");
        return;
    }
    
    printf("%-5s %-25s %-10s %-12s\n", "ID", "Item", "Price", "Category");
    printf("----------------------------------------\n");
    
    for(int i = 0; i < menu_count; i++) {
        char category[15];
        if(menu_categories[i] == 1) strcpy(category, "Appetizer");
        else if(menu_categories[i] == 2) strcpy(category, "Main Course");
        else if(menu_categories[i] == 3) strcpy(category, "Beverage");
        else if(menu_categories[i] == 4) strcpy(category, "Dessert");
        
        printf("%-5d %-25s $%-9.2f %-12s\n", 
               i+1, menu_items[i], menu_prices[i], category);
    }
    
    printf("========================================\n");
}

void viewMenuByCategory() {
    // Implementation similar to viewMenu() but filtered by category
    printf("Function to be implemented by Member 1\n");
}

void searchMenuItem() {
    // Implementation to search menu by name
    printf("Function to be implemented by Member 1\n");
}

// ============================================
//      MEMBER 2 - ORDER FUNCTIONS
// ============================================

void createOrder() {
    printf("Function to be implemented by Member 2\n");
    // Will use viewMenu(), get item selections, calculate total
}

void viewAllOrders() {
    printf("Function to be implemented by Member 2\n");
}

void updateOrderStatus() {
    printf("Function to be implemented by Member 2\n");
}

void completeOrder() {
    printf("Function to be implemented by Member 2\n");
}

void rejectOrder() {
    printf("Function to be implemented by Member 2\n");
}

void trackOrder() {
    printf("Function to be implemented by Member 2\n");
}

float calculateOrderTotal(int orderIndex) {
    // Calculate total for an order
    printf("Function to be implemented by Member 2\n");
    return 0.0;
}

void addTipToOrder() {
    printf("Function to be implemented by Member 2\n");
}

// ============================================
//      MEMBER 2 - BOOKING FUNCTIONS
// ============================================

void createBooking() {
    printf("Function to be implemented by Member 2\n");
}

void viewAllBookings() {
    printf("Function to be implemented by Member 2\n");
}

void cancelBooking() {
    printf("Function to be implemented by Member 2\n");
}

void checkTableAvailability() {
    printf("Function to be implemented by Member 2\n");
}

void updateBookingStatus() {
    printf("Function to be implemented by Member 2\n");
}

// ============================================
//      MEMBER 3 - STAFF FUNCTIONS
// ============================================

void addStaff() {
    printf("Function to be implemented by Member 3\n");
}

void viewAllStaff() {
    printf("Function to be implemented by Member 3\n");
}

void markAttendance() {
    printf("Function to be implemented by Member 3\n");
}

void calculateSalary() {
    printf("Function to be implemented by Member 3\n");
}

void viewStaffPerformance() {
    printf("Function to be implemented by Member 3\n");
}

// ============================================
//      MEMBER 3 - FINANCIAL FUNCTIONS
// ============================================

float calculateMonthlyRevenue() {
    float revenue = 0.0;
    
    // Loop through all orders and sum completed orders
    for(int i = 0; i < order_count; i++) {
        if(order_statuses[i] == 4) {  // Status 4 = Served/Completed
            revenue += order_amounts[i];
        }
    }
    
    return revenue;
}

float calculateTotalExpenses() {
    float expenses = 0.0;
    
    // Calculate inventory cost
    expenses += calculateInventoryValue();
    
    // Calculate staff salaries
    for(int i = 0; i < staff_count; i++) {
        expenses += staff_salaries[i];
    }
    
    // Add other expenses
    expenses += monthly_investment;
    
    return expenses;
}

float calculateProfit() {
    return calculateMonthlyRevenue() - calculateTotalExpenses();
}

void displayFinancialStats() {
    printf("\n");
    printf("========================================\n");
    printf("      FINANCIAL STATISTICS\n");
    printf("========================================\n");
    
    printf("\nREVENUE METRICS:\n");
    printf("- Total Orders This Month: %d\n", order_count);
    printf("- Total Order Value: $%.2f\n", calculateMonthlyRevenue());
    printf("- Orders Completed: %d\n", getCompletedOrdersCount());
    printf("- Orders Rejected: %d\n", getRejectedOrdersCount());
    printf("- Average Order Value: $%.2f\n", calculateAverageOrderValue());
    
    printf("\nEXPENSE METRICS:\n");
    printf("- Total Expenses: $%.2f\n", calculateTotalExpenses());
    printf("- Inventory Cost: $%.2f\n", calculateInventoryValue());
    
    printf("\nPROFIT METRICS:\n");
    printf("- Gross Profit: $%.2f\n", calculateProfit());
    
    printf("\nADDITIONAL METRICS:\n");
    printf("- Total Tips: $%.2f\n", getTotalTips());
    
    printf("========================================\n");
}

float calculateAverageOrderValue() {
    int completedOrders = getCompletedOrdersCount();
    if(completedOrders == 0) return 0.0;
    return calculateMonthlyRevenue() / completedOrders;
}

float getTotalTips() {
    float tips = 0.0;
    for(int i = 0; i < order_count; i++) {
        tips += order_tips[i];
    }
    return tips;
}

int getCompletedOrdersCount() {
    int count = 0;
    for(int i = 0; i < order_count; i++) {
        if(order_statuses[i] == 4) count++;
    }
    return count;
}

int getRejectedOrdersCount() {
    int count = 0;
    for(int i = 0; i < order_count; i++) {
        if(order_statuses[i] == 5) count++;
    }
    return count;
}

float calculateROI() {
    // ROI = (Gain - Investment) / Investment * 100
    float gain = calculateProfit();
    float investment = monthly_investment;
    if(investment == 0) return 0.0;
    return (gain / investment) * 100;
}

// ============================================
//          UTILITY FUNCTIONS
// ============================================

void clearScreen() {
    // For Windows
    system("cls");
    // For Linux/Mac: system("clear");
}

void pressEnterToContinue() {
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}
```

---

## Key Points for Students:

1. **Global Variables**: All data is stored in global arrays for simplicity
2. **Function Organization**: Functions are grouped by member responsibility
3. **Menu-Driven**: Uses while loops and switch/if-else for navigation
4. **Modular**: Each function does one specific task
5. **Simple Data Types**: Only int, float, and char arrays used
6. **No Complex Features**: No pointers, structs, file I/O, or APIs

---

## Tips for Implementation:

### For Member 1 (Inventory & Menu):
- Start with addInventoryItem() and viewInventory()
- Test with sample data
- Then implement menu functions
- Make sure menu data can be accessed by Member 2

### For Member 2 (Orders & Bookings):
- Start with simple createOrder() using dummy menu
- Test order calculations
- Implement booking functions
- You will integrate all modules!

### For Member 3 (Staff & Finance):
- Implement staff management first
- Create financial calculation functions
- These functions will use data from other members
- Test with sample order and inventory data

---

## 🧭 Navigation

**Other Documents:**
- [README](../../README.md)
- [PROJECT_DOCUMENTATION](../PROJECT_DOCUMENTATION/readme.md)
- [SYSTEM_ARCHITECTURE](../SYSTEM_ARCHITECTURE/readme.md)
- [DATA_STRUCTURES_GUIDE](../DATA_STRUCTURES_GUIDE/readme.md)

[Back to top](#sample-code-structure-reference-only)

---

END OF SAMPLE CODE STRUCTURE

