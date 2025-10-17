# Restaurant Management System - System Architecture

## 🧭 Navigation

**📍 You are here:** SYSTEM_ARCHITECTURE (Technical Design)

**📚 Other Documents:**
- 🏠 [README](../../README.md) - Project overview
- 🚀 [QUICK_START](../QUICK_START/readme.md) - Get started in 5 minutes
- 📚 [DOCUMENTATION_INDEX](../DOCUMENTATION_INDEX/readme.md) - Complete reading guide
- 📘 [PROJECT_DOCUMENTATION](../PROJECT_DOCUMENTATION/readme.md) - Full specifications
- 📊 [DATA_STRUCTURES_GUIDE](../DATA_STRUCTURES_GUIDE/readme.md) - Data organization
- 💻 [SAMPLE_CODE_STRUCTURE](../SAMPLE_CODE_STRUCTURE/readme.md) - Code reference
- 📝 [PROJECT_SUMMARY](../PROJECT_SUMMARY/readme.md) - Quick reference

**Recommended Next:** 📊 [DATA_STRUCTURES_GUIDE](../DATA_STRUCTURES_GUIDE/readme.md)

---

## Module Overview

```
┌─────────────────────────────────────────────────────────────┐
│                  RESTAURANT MANAGEMENT SYSTEM                │
│                      (Golden Spoon Diner)                    │
└─────────────────────────────────────────────────────────────┘
                              │
                              │
            ┌─────────────────┴─────────────────┐
            │                                   │
    ┌───────▼────────┐                  ┌──────▼────────┐
    │  ADMIN PANEL   │                  │  CUSTOMER     │
    │                │                  │  INTERFACE    │
    └───────┬────────┘                  └──────┬────────┘
            │                                   │
            │                                   │
    ┌───────┴────────────────────────┐         │
    │                                │         │
┌───▼───────────┐          ┌─────────▼─────┐  │
│   MEMBER 1    │          │    MEMBER 2   │  │
│   MODULE      │          │    MODULE     │◄─┘
│               │          │               │
│ - Inventory   │          │ - Orders      │
│ - Menu        │          │ - Bookings    │
└───────────────┘          └───────┬───────┘
                                   │
                           ┌───────▼───────┐
                           │   MEMBER 3    │
                           │   MODULE      │
                           │               │
                           │ - Staff       │
                           │ - Finance     │
                           └───────────────┘
```

## Data Flow Architecture

```
┌──────────────┐
│   CUSTOMER   │
└──────┬───────┘
       │
       │ (1) Views Menu
       │
       ▼
┌─────────────────┐
│   MENU DATA     │◄──── (Member 1: Menu Management)
│   (Arrays)      │
└─────────────────┘
       │
       │ (2) Places Order
       │
       ▼
┌─────────────────┐
│   ORDER DATA    │◄──── (Member 2: Order Management)
│   (Arrays)      │
└─────┬───────────┘
      │
      │ (3) Updates Inventory
      │
      ▼
┌─────────────────┐
│  INVENTORY DATA │◄──── (Member 1: Inventory Management)
│   (Arrays)      │
└─────────────────┘
      │
      │ (4) Completes Order
      │
      ▼
┌─────────────────┐
│  FINANCIAL DATA │◄──── (Member 3: Finance Calculations)
│  (Variables)    │
└─────────────────┘
```

## Function Call Hierarchy

```
main()
│
├─── adminMenu()
│    │
│    ├─── [MEMBER 1 FUNCTIONS]
│    │    ├─── addInventoryItem()
│    │    ├─── viewInventory()
│    │    ├─── updateInventory()
│    │    ├─── checkLowStock()
│    │    ├─── addMenuItem()
│    │    ├─── viewMenu()
│    │    └─── searchMenuItem()
│    │
│    ├─── [MEMBER 2 FUNCTIONS]
│    │    ├─── viewAllOrders()
│    │    ├─── updateOrderStatus()
│    │    ├─── viewAllBookings()
│    │    ├─── createBooking()
│    │    ├─── cancelBooking()
│    │    └─── checkTableAvailability()
│    │
│    └─── [MEMBER 3 FUNCTIONS]
│         ├─── addStaff()
│         ├─── viewAllStaff()
│         ├─── markAttendance()
│         ├─── calculateSalary()
│         ├─── calculateMonthlyRevenue()
│         ├─── calculateTotalExpenses()
│         ├─── calculateProfit()
│         └─── displayFinancialStats()
│
└─── userMenu()
     │
     ├─── viewMenu()              [MEMBER 1]
     ├─── createOrder()           [MEMBER 2]
     ├─── trackOrder()            [MEMBER 2]
     ├─── completeOrder()         [MEMBER 2]
     └─── rejectOrder()           [MEMBER 2]
```

## Member Responsibilities Breakdown

### Member 1: Foundation Module (Inventory & Menu)
```
┌─────────────────────────────────────────────┐
│         MEMBER 1 RESPONSIBILITIES           │
├─────────────────────────────────────────────┤
│                                             │
│  DATA STRUCTURES TO CREATE:                 │
│  • inventory_names[100][50]                 │
│  • inventory_quantities[100]                │
│  • inventory_prices[100]                    │
│  • menu_items[50][50]                       │
│  • menu_prices[50]                          │
│  • menu_categories[50]                      │
│                                             │
│  FUNCTIONS TO IMPLEMENT:                    │
│  1. addInventoryItem()                      │
│  2. viewInventory()                         │
│  3. updateInventory()                       │
│  4. checkLowStock()                         │
│  5. calculateInventoryValue()               │
│  6. addMenuItem()                           │
│  7. viewMenu()                              │
│  8. viewMenuByCategory()                    │
│  9. searchMenuItem()                        │
│                                             │
│  INTEGRATION POINTS:                        │
│  → Menu data used by Member 2 (Orders)      │
│  → Inventory updated when orders placed     │
└─────────────────────────────────────────────┘
```

### Member 2: Core Operations Module (Orders & Bookings)
```
┌─────────────────────────────────────────────┐
│         MEMBER 2 RESPONSIBILITIES           │
├─────────────────────────────────────────────┤
│                                             │
│  DATA STRUCTURES TO CREATE:                 │
│  • order_ids[200]                           │
│  • order_table_numbers[200]                 │
│  • order_items[200][10]                     │
│  • order_quantities[200][10]                │
│  • order_amounts[200]                       │
│  • order_statuses[200]                      │
│  • order_tips[200]                          │
│  • booking_ids[100]                         │
│  • booking_names[100][50]                   │
│  • booking_table_numbers[100]               │
│                                             │
│  FUNCTIONS TO IMPLEMENT:                    │
│  1. createOrder()                           │
│  2. viewAllOrders()                         │
│  3. updateOrderStatus()                     │
│  4. completeOrder()                         │
│  5. rejectOrder()                           │
│  6. trackOrder()                            │
│  7. calculateOrderTotal()                   │
│  8. addTipToOrder()                         │
│  9. createBooking()                         │
│  10. viewAllBookings()                      │
│  11. cancelBooking()                        │
│  12. checkTableAvailability()               │
│                                             │
│  INTEGRATION POINTS:                        │
│  → Uses menu data from Member 1             │
│  → Provides order data to Member 3          │
│  → Updates inventory (Member 1)             │
│  → INTEGRATOR of all modules                │
└─────────────────────────────────────────────┘
```

### Member 3: Analytics Module (Staff & Finance)
```
┌─────────────────────────────────────────────┐
│         MEMBER 3 RESPONSIBILITIES           │
├─────────────────────────────────────────────┤
│                                             │
│  DATA STRUCTURES TO CREATE:                 │
│  • staff_ids[20]                            │
│  • staff_names[20][50]                      │
│  • staff_roles[20]                          │
│  • staff_salaries[20]                       │
│  • staff_attendance[20]                     │
│  • total_revenue (float)                    │
│  • total_expenses (float)                   │
│  • total_tips (float)                       │
│                                             │
│  FUNCTIONS TO IMPLEMENT:                    │
│  1. addStaff()                              │
│  2. viewAllStaff()                          │
│  3. markAttendance()                        │
│  4. calculateSalary()                       │
│  5. viewStaffPerformance()                  │
│  6. calculateMonthlyRevenue()               │
│  7. calculateTotalExpenses()                │
│  8. calculateProfit()                       │
│  9. displayFinancialStats()                 │
│  10. calculateAverageOrderValue()           │
│  11. getTotalTips()                         │
│  12. getCompletedOrdersCount()              │
│  13. getRejectedOrdersCount()               │
│  14. calculateROI()                         │
│                                             │
│  INTEGRATION POINTS:                        │
│  → Uses order data from Member 2            │
│  → Uses inventory data from Member 1        │
│  → Provides financial reports               │
└─────────────────────────────────────────────┘
```

## Simple Example: Order Flow

```
STEP 1: Customer views menu
         ↓
    [Member 1: viewMenu() displays all menu items]
         ↓
STEP 2: Customer selects items
         ↓
    [Member 2: createOrder() stores order details]
         ↓
STEP 3: Calculate order total
         ↓
    [Member 2: calculateOrderTotal() sums item prices]
         ↓
STEP 4: Deduct from inventory
         ↓
    [Member 1: updateInventory() reduces stock]
         ↓
STEP 5: Admin updates order status
         ↓
    [Member 2: updateOrderStatus() changes status]
         ↓
STEP 6: Customer completes order
         ↓
    [Member 2: completeOrder() marks as done]
         ↓
STEP 7: Update financial records
         ↓
    [Member 3: calculateMonthlyRevenue() adds to total]
         ↓
STEP 8: Display statistics
         ↓
    [Member 3: displayFinancialStats() shows reports]
```

## Key Programming Concepts Used

### 1. Arrays for Data Storage
```c
// Example: Inventory array structure
char inventory_names[100][50];    // 100 items, each name up to 50 chars
int inventory_quantities[100];     // Quantities for each item
float inventory_prices[100];       // Prices for each item
int inventory_count = 0;           // Current number of items
```

### 2. Functions for Modularity
```c
// Example: Function to add inventory
void addInventoryItem() {
    // Get item name
    // Get quantity
    // Get price
    // Store in arrays
    // Increment count
}
```

### 3. Loops for Iteration
```c
// Example: Display all orders
for(int i = 0; i < order_count; i++) {
    printf("Order ID: %d\n", order_ids[i]);
    printf("Amount: %.2f\n", order_amounts[i]);
}
```

### 4. Conditionals for Logic
```c
// Example: Check order status
if(order_statuses[i] == 1) {
    printf("Pending");
} else if(order_statuses[i] == 2) {
    printf("Preparing");
} else if(order_statuses[i] == 3) {
    printf("Ready");
}
```

### 5. Input/Output
```c
// Input
printf("Enter item name: ");
scanf("%s", inventory_names[inventory_count]);

// Output
printf("Total Revenue: $%.2f\n", total_revenue);
```

## Integration Strategy

### Phase 1: Individual Development (Weeks 2-3)
Each member works independently on their module with dummy data.

### Phase 2: Interface Agreement (Week 3)
- Member 1 provides: `menu_items[]`, `menu_prices[]`, `menu_count`
- Member 2 uses: Menu data to create orders
- Member 2 provides: `order_amounts[]`, `order_statuses[]`, `order_count`
- Member 3 uses: Order data to calculate finances

### Phase 3: Integration (Week 4)
Member 2 (as integrator) combines all modules:
1. Include all header declarations
2. Link function calls
3. Ensure data sharing works
4. Test complete flow

### Phase 4: Testing (Week 5)
All members test the complete system together.

---

## Notes for Students

- Keep it SIMPLE - don't overcomplicate
- Test each function individually before integration
- Use meaningful variable names
- Comment your code
- Communicate with team members regularly
- Follow the same coding style (indentation, naming)

---

## 🧭 Navigation

**Next Recommended:**
- 📊 [DATA_STRUCTURES_GUIDE](../DATA_STRUCTURES_GUIDE/readme.md) - See detailed data structures
- 💻 [SAMPLE_CODE_STRUCTURE](../SAMPLE_CODE_STRUCTURE/readme.md) - Reference code

**Back to:**
- 🏠 [Main README](../../README.md)
- 📘 [PROJECT_DOCUMENTATION](../PROJECT_DOCUMENTATION/readme.md)
- [Top of this page](#restaurant-management-system---system-architecture)

---

END OF ARCHITECTURE DOCUMENT
