# Data Structures Reference Guide

## 🧭 Navigation

**You are here:** DATA_STRUCTURES_GUIDE

**Other Documents:**
- [README](../../README.md)
- [PROJECT_DOCUMENTATION](../PROJECT_DOCUMENTATION/readme.md)
- [SYSTEM_ARCHITECTURE](../SYSTEM_ARCHITECTURE/readme.md)
- [SAMPLE_CODE_STRUCTURE](../SAMPLE_CODE_STRUCTURE/readme.md)

---

## This guide shows how all data is organized in the RMS

---

## 📦 MEMBER 1 - Inventory & Menu Data

### Inventory Arrays

```
Array Name                  Type          Size    Purpose
─────────────────────────────────────────────────────────────
inventory_names[][]         char          100x50  Store item names
inventory_quantities[]      int           100     Current stock count
inventory_prices[]          float         100     Price per unit
inventory_count             int           1       Total items in inventory

Example Data:
─────────────────────────────────────────────────────────────
Index  | Name          | Quantity | Price
─────────────────────────────────────────────────────────────
0      | Chicken       | 50       | 5.00
1      | Tomatoes      | 100      | 1.50
2      | Pasta         | 75       | 2.00
3      | Cheese        | 30       | 4.00
```

### Menu Arrays

```
Array Name                  Type          Size    Purpose
─────────────────────────────────────────────────────────────
menu_items[][]              char          50x50   Menu item names
menu_prices[]               float         50      Item prices
menu_categories[]           int           50      Category codes
menu_count                  int           1       Total menu items

Category Codes:
1 = Appetizer
2 = Main Course
3 = Beverage
4 = Dessert

Example Data:
─────────────────────────────────────────────────────────────
Index  | Item Name          | Price  | Category
─────────────────────────────────────────────────────────────
0      | Caesar Salad       | 8.00   | 1 (Appetizer)
1      | Grilled Chicken    | 15.00  | 2 (Main)
2      | Coke               | 2.00   | 3 (Beverage)
3      | Chocolate Cake     | 6.00   | 4 (Dessert)
```

---

## 📦 MEMBER 2 - Order & Booking Data

### Order Arrays

```
Array Name                  Type          Size     Purpose
─────────────────────────────────────────────────────────────
order_ids[]                 int           200      Unique order IDs
order_table_numbers[]       int           200      Which table ordered
order_items[][]             int           200x10   Menu item IDs in order
order_quantities[][]        int           200x10   Qty of each item
order_item_counts[]         int           200      Items per order
order_amounts[]             float         200      Total bill amount
order_statuses[]            int           200      Order status code
order_tips[]                float         200      Tip amount
order_count                 int           1        Total orders

Status Codes:
1 = Pending
2 = Preparing
3 = Ready
4 = Served/Completed
5 = Rejected/Cancelled

Example Data:
─────────────────────────────────────────────────────────────
Order Details for Order Index 0:
order_ids[0] = 1001
order_table_numbers[0] = 5
order_item_counts[0] = 3

Items in this order:
order_items[0][0] = 1        (Menu item ID 1: Grilled Chicken)
order_quantities[0][0] = 1   (Quantity: 1)

order_items[0][1] = 2        (Menu item ID 2: Coke)
order_quantities[0][1] = 2   (Quantity: 2)

order_items[0][2] = 3        (Menu item ID 3: Chocolate Cake)
order_quantities[0][2] = 1   (Quantity: 1)

order_amounts[0] = 25.00     (Total: $25.00)
order_statuses[0] = 2        (Preparing)
order_tips[0] = 3.00         (Tip: $3.00)
```

### Booking Arrays

```
Array Name                  Type          Size     Purpose
─────────────────────────────────────────────────────────────
booking_ids[]               int           100      Unique booking IDs
booking_names[][]           char          100x50   Customer names
booking_phones[][]          char          100x15   Phone numbers
booking_table_numbers[]     int           100      Reserved table no.
booking_guest_counts[]      int           100      Number of guests
booking_statuses[]          int           100      Booking status code
booking_count               int           1        Total bookings

Status Codes:
1 = Confirmed
2 = Completed (customer showed up)
3 = Cancelled

Example Data:
─────────────────────────────────────────────────────────────
Index  | ID   | Name         | Phone        | Table | Guests | Status
─────────────────────────────────────────────────────────────
0      | 201  | John Smith   | 555-1234     | 5     | 4      | 1
1      | 202  | Mary Johnson | 555-5678     | 3     | 2      | 1
```

---

## 📦 MEMBER 3 - Staff & Finance Data

### Staff Arrays

```
Array Name                  Type          Size     Purpose
─────────────────────────────────────────────────────────────
staff_ids[]                 int           20       Employee IDs
staff_names[][]             char          20x50    Employee names
staff_roles[]               int           20       Role codes
staff_phones[][]            char          20x15    Phone numbers
staff_salaries[]            float         20       Monthly salary
staff_attendance[]          int           20       Days present
staff_count                 int           1        Total staff

Role Codes:
1 = Chef
2 = Waiter
3 = Helper

Example Data:
─────────────────────────────────────────────────────────────
Index  | ID  | Name         | Role    | Phone      | Salary  | Days
─────────────────────────────────────────────────────────────
0      | 101 | Mike Chen    | 1(Chef) | 555-1111   | 2500.00 | 25
1      | 102 | Sarah Lee    | 2(Wait) | 555-2222   | 1800.00 | 28
2      | 103 | Tom Brown    | 2(Wait) | 555-3333   | 1800.00 | 26
```

### Financial Variables

```
Variable Name              Type          Purpose
─────────────────────────────────────────────────────────────
total_revenue              float         Sum of completed orders
total_expenses             float         All costs combined
total_tips                 float         All tips collected
monthly_investment         float         Money invested this month

Example Data:
─────────────────────────────────────────────────────────────
total_revenue = 4350.00
total_expenses = 15000.00
total_tips = 420.00
monthly_investment = 12000.00
```

---

## 🔄 How Data Flows Between Modules

### Example: Complete Order Flow

```
STEP 1: Customer views menu
┌─────────────────────────────────┐
│ Member 1: menu_items[]          │ → Display to customer
│           menu_prices[]         │
└─────────────────────────────────┘

STEP 2: Customer creates order
┌─────────────────────────────────┐
│ Member 2: Stores in order_*[]   │ → Customer selects items
│           Calculates total      │
└─────────────────────────────────┘

STEP 3: Kitchen prepares (Admin updates status)
┌─────────────────────────────────┐
│ Member 2: order_statuses[]      │ → Changes 1→2→3→4
└─────────────────────────────────┘

STEP 4: Update inventory
┌─────────────────────────────────┐
│ Member 1: inventory_quantities[]│ → Reduces stock
└─────────────────────────────────┘

STEP 5: Customer completes order
┌─────────────────────────────────┐
│ Member 2: order_statuses[i] = 4│ → Mark completed
│           order_tips[i] = X     │ → Add tip
└─────────────────────────────────┘

STEP 6: Update financial records
┌─────────────────────────────────┐
│ Member 3: total_revenue += amt  │ → Add to revenue
│           total_tips += tip     │ → Add to tips
└─────────────────────────────────┘

STEP 7: Display stats
┌─────────────────────────────────┐
│ Member 3: Calculate all metrics │ → Show financial report
└─────────────────────────────────┘
```

---

## 💡 Key Concepts Explained

### 1. Why Arrays?

```c
// Instead of creating 100 separate variables:
char item1[50], item2[50], item3[50]... // BAD!

// We use one array:
char inventory_names[100][50];  // GOOD!
```

### 2. Parallel Arrays

Multiple arrays with same index represent one entity:

```c
// Index 0 represents one inventory item:
inventory_names[0]      = "Chicken"
inventory_quantities[0] = 50
inventory_prices[0]     = 5.00

// Index 1 represents another item:
inventory_names[1]      = "Tomatoes"
inventory_quantities[1] = 100
inventory_prices[1]     = 1.50
```

### 3. 2D Arrays for Multiple Items per Record

```c
// Order 0 has 3 items:
order_items[0][0] = 1  // First item in order 0
order_items[0][1] = 2  // Second item in order 0
order_items[0][2] = 3  // Third item in order 0

// Order 1 has 2 items:
order_items[1][0] = 4  // First item in order 1
order_items[1][1] = 5  // Second item in order 1
```

### 4. Counter Variables

```c
// Always track how many items are actually stored:
int inventory_count = 0;  // Initially empty

// When adding first item:
inventory_count++;  // Now = 1

// Loop through only filled items:
for(int i = 0; i < inventory_count; i++) {
    // Process inventory_names[i]
}
```

---

## 📝 Access Patterns

### Member 1 Functions Access:

```c
// Adding inventory:
inventory_names[inventory_count] = "NewItem";
inventory_quantities[inventory_count] = 100;
inventory_prices[inventory_count] = 5.00;
inventory_count++;

// Viewing inventory:
for(int i = 0; i < inventory_count; i++) {
    printf("%s - %d units - $%.2f\n", 
           inventory_names[i],
           inventory_quantities[i],
           inventory_prices[i]);
}
```

### Member 2 Functions Access:

```c
// Creating order:
order_ids[order_count] = generateID();
order_table_numbers[order_count] = tableNum;

// Adding items to order:
for(int i = 0; i < selectedItemCount; i++) {
    order_items[order_count][i] = menuItemID;
    order_quantities[order_count][i] = qty;
}

order_item_counts[order_count] = selectedItemCount;
order_amounts[order_count] = calculateTotal();
order_statuses[order_count] = 1;  // Pending
order_count++;
```

### Member 3 Functions Access:

```c
// Calculate revenue:
float revenue = 0.0;
for(int i = 0; i < order_count; i++) {
    if(order_statuses[i] == 4) {  // Completed
        revenue += order_amounts[i];
    }
}

// Calculate expenses:
float expenses = 0.0;
for(int i = 0; i < staff_count; i++) {
    expenses += staff_salaries[i];
}
```

---

## 🎯 Integration Points

### What Member 2 Needs from Member 1:

```c
// From Menu module:
extern char menu_items[50][50];
extern float menu_prices[50];
extern int menu_count;

// From Inventory module:
extern int inventory_quantities[100];
```

### What Member 3 Needs from Member 2:

```c
// From Order module:
extern float order_amounts[200];
extern int order_statuses[200];
extern float order_tips[200];
extern int order_count;
```

### What Member 3 Needs from Member 1:

```c
// From Inventory module:
extern float inventory_prices[100];
extern int inventory_quantities[100];
extern int inventory_count;
```

---

## 🧪 Sample Test Data

### Use this data for testing:

```c
// Initialize some test inventory:
strcpy(inventory_names[0], "Chicken");
inventory_quantities[0] = 50;
inventory_prices[0] = 5.00;

strcpy(inventory_names[1], "Rice");
inventory_quantities[1] = 100;
inventory_prices[1] = 1.00;

inventory_count = 2;

// Initialize some test menu:
strcpy(menu_items[0], "Grilled Chicken");
menu_prices[0] = 15.00;
menu_categories[0] = 2;

strcpy(menu_items[1], "Coke");
menu_prices[1] = 2.00;
menu_categories[1] = 3;

menu_count = 2;

// Initialize some test orders:
order_ids[0] = 1001;
order_table_numbers[0] = 5;
order_items[0][0] = 0;  // Menu item 0
order_quantities[0][0] = 1;
order_item_counts[0] = 1;
order_amounts[0] = 15.00;
order_statuses[0] = 4;  // Completed
order_tips[0] = 2.00;

order_count = 1;
```

---

## 🔍 Common Patterns

### Pattern 1: Add Item to Array
```c
if(count < MAX_SIZE) {
    // Store data at current count position
    array[count] = newValue;
    count++;
} else {
    printf("Array is full!\n");
}
```

### Pattern 2: Find Item in Array
```c
int found = 0;
for(int i = 0; i < count; i++) {
    if(condition_matches) {
        // Found it!
        found = 1;
        // Do something with array[i]
        break;
    }
}
if(!found) {
    printf("Item not found!\n");
}
```

### Pattern 3: Calculate Sum
```c
float total = 0.0;
for(int i = 0; i < count; i++) {
    total += array[i];
}
```

### Pattern 4: Count Matching Items
```c
int matches = 0;
for(int i = 0; i < count; i++) {
    if(condition_matches) {
        matches++;
    }
}
```

---

## 🧭 Navigation

**Other Documents:**
- [README](../../README.md)
- [PROJECT_DOCUMENTATION](../PROJECT_DOCUMENTATION/readme.md)
- [SYSTEM_ARCHITECTURE](../SYSTEM_ARCHITECTURE/readme.md)
- [SAMPLE_CODE_STRUCTURE](../SAMPLE_CODE_STRUCTURE/readme.md)

[Back to top](#data-structures-reference-guide)

---

END OF DATA STRUCTURES REFERENCE GUIDE

