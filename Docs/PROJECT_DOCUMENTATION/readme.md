# Restaurant Management System (RMS) - Project Documentation

## 🧭 Navigation

**📍 You are here:** PROJECT_DOCUMENTATION (Full Specifications)

**📚 Other Documents:**
- 🏠 [README](../../README.md) - Project overview
- 🚀 [QUICK_START](../QUICK_START/readme.md) - Get started in 5 minutes
- 📚 [DOCUMENTATION_INDEX](../DOCUMENTATION_INDEX/readme.md) - Complete reading guide
- 🏗️ [SYSTEM_ARCHITECTURE](../SYSTEM_ARCHITECTURE/readme.md) - Technical architecture
- 📊 [DATA_STRUCTURES_GUIDE](../DATA_STRUCTURES_GUIDE/readme.md) - Data organization
- 💻 [SAMPLE_CODE_STRUCTURE](../SAMPLE_CODE_STRUCTURE/readme.md) - Code reference
- 📝 [PROJECT_SUMMARY](../PROJECT_SUMMARY/readme.md) - Quick reference

**Recommended Next:** 🏗️ [SYSTEM_ARCHITECTURE](../SYSTEM_ARCHITECTURE/readme.md)

---

## Team Members
- Member 1: [Name]
- Member 2: [Name]
- Member 3: [Name]

---

## 1. Hypothetical Business Scenario

**Restaurant Name:** "Golden Spoon Diner"

**Business Overview:**
Golden Spoon Diner is a medium-sized restaurant located in the heart of the city, serving 100-150 customers daily. The restaurant operates from 11 AM to 11 PM, offering a diverse menu of appetizers, main courses, beverages, and desserts. The restaurant has:
- 1 Manager (Admin)
- 3 Chefs
- 5 Waiters
- 2 Kitchen helpers
- 15 tables with seating capacity of 60 customers
- Average bill per customer: $25-30
- Monthly operational cost: $15,000

The restaurant currently handles all operations manually using paper-based systems for orders, inventory tracking, and staff management.

---

## 2. Business Issues (Current Problems)

### 2.1 Order Management Issues
- **Order Confusion:** Waiters write orders on paper, leading to illegible handwriting and wrong orders being prepared
- **Order Delays:** No systematic way to track order status, causing delays in food preparation and service
- **Lost Orders:** Paper slips get misplaced, leading to forgotten orders and angry customers
- **No Order History:** Cannot track which customer ordered what, making it difficult to analyze popular items

### 2.2 Inventory Management Issues
- **Stock Shortages:** Running out of ingredients mid-service because of poor inventory tracking
- **Wastage:** Over-ordering ingredients that expire before use
- **Manual Counting:** Staff spends hours manually counting inventory at the end of each week
- **Theft Prevention:** No proper system to track ingredient usage vs actual orders

### 2.3 Table Booking Issues
- **Double Bookings:** Same table booked for multiple customers at the same time
- **No Record Keeping:** No systematic record of reservations, leading to confusion
- **Walk-in vs Booking Confusion:** Difficulty managing both walk-in customers and pre-booked tables
- **Customer Information Loss:** Cannot contact customers if there are changes to booking

### 2.4 Staff Management Issues
- **Attendance Tracking:** No proper system to track which staff members are present
- **Shift Chaos:** Confusion about shift timings and staff availability
- **Performance Tracking:** Cannot identify which waiters are handling more orders
- **Salary Calculation Errors:** Manual calculation leads to payment disputes

### 2.5 Financial Issues
- **Lost Revenue Data:** No way to know exact daily/monthly revenue
- **Tip Tracking:** Tips collected are not properly recorded
- **No Profit Analysis:** Cannot calculate actual profit after deducting costs
- **Rejected Orders:** Money lost due to order cancellations not tracked
- **Investment ROI:** Cannot measure return on investment for new equipment or menu items

---

## 3. Why the Need for RMS?

### 3.1 Operational Efficiency
- **Streamlined Operations:** Digital system ensures all orders are clearly visible and tracked
- **Time Savings:** Reduces manual paperwork, saving 5-6 hours daily
- **Error Reduction:** Minimizes human errors in order taking and billing

### 3.2 Financial Clarity
- **Real-time Financial Data:** Instant access to revenue, profit, and loss information
- **Better Decision Making:** Data-driven insights for menu pricing and inventory purchasing
- **Cost Control:** Track where money is being spent and identify cost-saving opportunities

### 3.3 Customer Satisfaction
- **Faster Service:** Orders are processed quickly without confusion
- **Accurate Orders:** Customers get exactly what they ordered
- **Better Booking Experience:** Reliable reservation system prevents double bookings

### 3.4 Business Growth
- **Scalability:** System can handle increased orders as business grows
- **Performance Metrics:** Identify best-selling items and optimize menu
- **Staff Accountability:** Better staff management leads to improved service quality

---

## 4. Main Features of RMS

### 4.1 ADMIN PERSPECTIVE

#### 4.1.1 Inventory Management
- **Add Inventory Items:** Add new ingredients/items with name, quantity, unit, and price
- **View All Inventory:** Display complete list of inventory items with current stock levels
- **Update Inventory:** Modify quantity when new stock arrives
- **Low Stock Alerts:** Show warning when items are below minimum threshold
- **Inventory Value:** Calculate total value of current inventory
- **Ingredient Consumption Tracking:** Track how much inventory is used per order

#### 4.1.2 Order Management
- **View All Orders:** Display all orders (pending, in-progress, completed, rejected)
- **Order Status Update:** Mark orders as confirmed, preparing, ready, served
- **Order Details:** View complete order information (table number, items, quantity, price)
- **Order Assignment:** Assign orders to specific kitchen staff
- **Order History:** View past orders with timestamps
- **Order Priority:** Mark urgent orders for faster processing

#### 4.1.3 Table Booking Management
- **View All Bookings:** Display all table reservations
- **Add New Booking:** Create reservation with customer name, phone, date, time, table number, guest count
- **Cancel Booking:** Remove cancelled reservations
- **Check Availability:** See which tables are available at specific times
- **Booking Status:** Track confirmed, pending, completed, cancelled bookings
- **Walk-in Management:** Assign tables to walk-in customers

#### 4.1.4 Staff Management
- **Add Staff:** Register new staff members with ID, name, role, phone, salary
- **View All Staff:** Display complete staff list
- **Mark Attendance:** Record daily attendance (present/absent)
- **Assign Shifts:** Allocate morning/evening/night shifts
- **Staff Performance:** Track number of orders handled per staff member
- **Salary Calculation:** Calculate monthly salary based on attendance

#### 4.1.5 Financial Calculations & Statistics

**Revenue Metrics:**
- Total orders this month (count)
- Total order value this month (sum of all order amounts)
- Orders completed (count and total value)
- Orders rejected/cancelled (count and lost revenue)
- Average order value
- Daily revenue tracking

**Expense Metrics:**
- Total invested amount (inventory purchases + staff salaries + other costs)
- Total inventory cost
- Total staff salaries
- Other operational expenses

**Profit Metrics:**
- Total return (revenue from completed orders)
- Gross profit (revenue - total costs)
- Net profit percentage
- Profit per order

**Additional Metrics:**
- Total tips collected
- Tips per waiter
- Best-selling menu items
- Peak hours (most orders)
- Table utilization rate
- Customer count per day/month

---

### 4.2 USER (CUSTOMER) PERSPECTIVE

#### 4.2.1 View Menu
- **Display Menu:** Show categorized menu (Appetizers, Main Course, Beverages, Desserts)
- **Item Details:** Display item name, description, price
- **Category Filtering:** View specific category items
- **Search Items:** Find specific dishes by name

#### 4.2.2 Place Order
- **Add Items to Order:** Select menu items with quantity
- **View Cart:** See all items in current order with subtotal
- **Remove Items:** Delete items from cart before confirming
- **Order Confirmation:** Finalize order with table number
- **Bill Preview:** See total amount before confirming

#### 4.2.3 Track Order
- **Order Status:** Check if order is confirmed, preparing, ready, or served
- **Estimated Time:** See approximate wait time
- **Order ID:** Unique identifier to track specific order
- **Order Details:** View what was ordered and quantities

#### 4.2.4 Complete or Reject Order
- **Complete Order:** Confirm order is received and satisfactory (triggers payment)
- **Reject Order:** Cancel order before it's served (with reason)
- **Add Tip:** Option to add tip amount when completing order
- **View Bill:** Final bill with all items and total amount

---

## 5. System Architecture

### 5.1 Data Structures (Using Arrays and Simple Variables)

```
INVENTORY SYSTEM:
- inventory_names[100][50]      → Store item names (max 100 items)
- inventory_quantities[100]     → Current stock quantities
- inventory_prices[100]         → Price per unit
- inventory_count               → Total number of inventory items

MENU SYSTEM:
- menu_items[50][50]            → Menu item names (max 50 items)
- menu_prices[50]               → Price of each menu item
- menu_categories[50]           → Category (1=Appetizer, 2=Main, 3=Beverage, 4=Dessert)
- menu_count                    → Total menu items

ORDER SYSTEM:
- order_ids[200]                → Unique order identifiers
- order_table_numbers[200]      → Which table placed the order
- order_items[200][10]          → Item IDs in each order (max 10 items per order)
- order_quantities[200][10]     → Quantity of each item
- order_item_counts[200]        → How many items in each order
- order_amounts[200]            → Total amount for each order
- order_statuses[200]           → Status (1=Pending, 2=Preparing, 3=Ready, 4=Served, 5=Rejected)
- order_tips[200]               → Tip amount for each order
- order_count                   → Total orders

BOOKING SYSTEM:
- booking_ids[100]              → Unique booking identifiers
- booking_names[100][50]        → Customer names
- booking_phones[100][15]       → Phone numbers
- booking_table_numbers[100]    → Reserved table numbers
- booking_guest_counts[100]     → Number of guests
- booking_statuses[100]         → Status (1=Confirmed, 2=Completed, 3=Cancelled)
- booking_count                 → Total bookings

STAFF SYSTEM:
- staff_ids[20]                 → Employee IDs
- staff_names[20][50]           → Employee names
- staff_roles[20]               → Role (1=Chef, 2=Waiter, 3=Helper)
- staff_phones[20][15]          → Contact numbers
- staff_salaries[20]            → Monthly salary
- staff_attendance[20]          → Days present this month
- staff_count                   → Total staff members

FINANCIAL SYSTEM:
- total_revenue                 → Sum of all completed orders
- total_expenses                → Inventory + salaries + other costs
- total_tips                    → All tips collected
- monthly_investment            → Money invested this month
```

### 5.2 Main Functions (Modular Design)

```
MAIN PROGRAM:
- main()                        → Entry point, display main menu
- adminMenu()                   → Display admin dashboard
- userMenu()                    → Display customer interface

INVENTORY FUNCTIONS:
- addInventoryItem()            → Add new inventory item
- viewInventory()               → Display all inventory
- updateInventory()             → Update stock quantity
- checkLowStock()               → Alert for low inventory
- calculateInventoryValue()     → Total inventory worth

MENU FUNCTIONS:
- addMenuItem()                 → Add dish to menu
- viewMenu()                    → Display menu to customers
- viewMenuByCategory()          → Filter by category
- searchMenuItem()              → Find specific dish

ORDER FUNCTIONS:
- createOrder()                 → Customer places new order
- viewAllOrders()               → Admin views all orders
- updateOrderStatus()           → Change order status
- completeOrder()               → Mark order as completed
- rejectOrder()                 → Cancel order
- trackOrder()                  → Check order status
- calculateOrderTotal()         → Compute bill amount
- addTipToOrder()               → Add tip to completed order

BOOKING FUNCTIONS:
- createBooking()               → Make table reservation
- viewAllBookings()             → Display all bookings
- cancelBooking()               → Cancel reservation
- checkTableAvailability()      → See available tables
- updateBookingStatus()         → Change booking status

STAFF FUNCTIONS:
- addStaff()                    → Register new employee
- viewAllStaff()                → Display staff list
- markAttendance()              → Record daily attendance
- calculateSalary()             → Compute monthly salary
- viewStaffPerformance()        → Orders handled by each staff

FINANCIAL FUNCTIONS:
- calculateMonthlyRevenue()     → Total sales this month
- calculateTotalExpenses()      → Sum of all costs
- calculateProfit()             → Revenue - Expenses
- displayFinancialStats()       → Show all financial metrics
- calculateAverageOrderValue()  → Revenue / Order count
- getTotalTips()                → Sum of all tips
- getCompletedOrdersCount()     → Number of completed orders
- getRejectedOrdersCount()      → Number of cancelled orders
- calculateROI()                → Return on investment

UTILITY FUNCTIONS:
- displayHeader()               → Show program title
- clearScreen()                 → Clear console
- pressEnterToContinue()        → Pause for user
- getIntegerInput()             → Validate integer input
- getStringInput()              → Validate string input
- generateUniqueID()            → Create unique identifiers
```

### 5.3 Program Flow

```
START
  │
  ├─→ Display Welcome Screen
  │
  ├─→ Main Menu
  │    ├─→ [1] Admin Login
  │    │     │
  │    │     ├─→ Admin Dashboard
  │    │     │    ├─→ [1] Inventory Management
  │    │     │    │     ├─→ Add Item
  │    │     │    │     ├─→ View Inventory
  │    │     │    │     ├─→ Update Stock
  │    │     │    │     └─→ Check Low Stock
  │    │     │    │
  │    │     │    ├─→ [2] Order Management
  │    │     │    │     ├─→ View All Orders
  │    │     │    │     ├─→ Update Order Status
  │    │     │    │     └─→ View Order History
  │    │     │    │
  │    │     │    ├─→ [3] Booking Management
  │    │     │    │     ├─→ View All Bookings
  │    │     │    │     ├─→ Cancel Booking
  │    │     │    │     └─→ Check Availability
  │    │     │    │
  │    │     │    ├─→ [4] Staff Management
  │    │     │    │     ├─→ Add Staff
  │    │     │    │     ├─→ View Staff
  │    │     │    │     ├─→ Mark Attendance
  │    │     │    │     └─→ Calculate Salary
  │    │     │    │
  │    │     │    └─→ [5] Financial Statistics
  │    │     │          ├─→ Monthly Revenue
  │    │     │          ├─→ Total Expenses
  │    │     │          ├─→ Profit/Loss
  │    │     │          ├─→ Order Statistics
  │    │     │          └─→ ROI Analysis
  │    │     │
  │    │     └─→ Back to Main Menu
  │    │
  │    └─→ [2] Customer Interface
  │          │
  │          ├─→ Customer Menu
  │          │    ├─→ [1] View Menu
  │          │    │     └─→ Display by Category
  │          │    │
  │          │    ├─→ [2] Place Order
  │          │    │     ├─→ Select Items
  │          │    │     ├─→ View Cart
  │          │    │     └─→ Confirm Order
  │          │    │
  │          │    ├─→ [3] Track Order
  │          │    │     └─→ Enter Order ID
  │          │    │
  │          │    └─→ [4] Complete/Reject Order
  │          │          ├─→ Enter Order ID
  │          │          ├─→ [Option 1] Complete (Add Tip)
  │          │          └─→ [Option 2] Reject (Reason)
  │          │
  │          └─→ Back to Main Menu
  │
  └─→ [3] Exit Program
        │
        └─→ END
```

### 5.4 Control Flow Concepts Used

**Loops:**
- `for` loops: Iterate through arrays (inventory, orders, menu, staff)
- `while` loops: Keep menus running until user chooses to exit
- Nested loops: Display order details (loop through orders, then items in each order)

**Conditional Statements:**
- `if-else`: Check user choices, validate inputs, check status
- `switch-case`: Handle menu selections
- Nested conditions: Check multiple criteria (e.g., table available AND time slot free)

**Functions:**
- Modular functions for each feature
- Functions with parameters (pass IDs, amounts, names)
- Functions with return values (calculations return results)

**Input/Output:**
- `printf()`: Display menus, information, results
- `scanf()`: Get user input (numbers, strings)
- Formatted output: Display tables with aligned columns

**Arrays:**
- Single-dimensional: Store quantities, prices, IDs
- Multi-dimensional: Store names (strings), order items

**Data Types:**
- `int`: IDs, quantities, counts, status codes
- `float`: Prices, amounts, salaries
- `char`: Names, phone numbers (as character arrays)

---

## 6. Project Module Division (3 Members)

### Member 1: Inventory & Menu Management
**Responsibilities:**
- Implement all inventory functions (add, view, update, low stock alert)
- Implement all menu functions (add items, display menu, search)
- Create data structures for inventory and menu
- Calculate inventory value

**Estimated Complexity:** Medium

---

### Member 2: Order & Booking Management
**Responsibilities:**
- Implement all order functions (create, view, track, complete, reject)
- Implement all booking functions (create, view, cancel, availability check)
- Handle order calculations (total, tips)
- Manage order and booking status updates

**Estimated Complexity:** High (Most complex module)

---

### Member 3: Staff & Financial Management
**Responsibilities:**
- Implement all staff functions (add, view, attendance, salary)
- Implement all financial calculation functions
- Generate financial reports and statistics
- Calculate ROI, profit/loss, revenue metrics

**Estimated Complexity:** Medium

---

## 7. Sample Output Screens

### 7.1 Admin Dashboard
```
========================================
    GOLDEN SPOON DINER - ADMIN PANEL
========================================

1. Inventory Management
2. Order Management
3. Booking Management
4. Staff Management
5. Financial Statistics
6. Logout

Enter your choice: _
```

### 7.2 Financial Statistics Screen
```
========================================
      FINANCIAL STATISTICS
========================================

REVENUE METRICS:
- Total Orders This Month: 145
- Total Order Value: $4,350.00
- Orders Completed: 138
- Orders Rejected: 7
- Average Order Value: $30.00

EXPENSE METRICS:
- Total Invested Amount: $15,000.00
- Inventory Cost: $8,500.00
- Staff Salaries: $6,000.00
- Other Expenses: $500.00

PROFIT METRICS:
- Total Return: $4,350.00
- Gross Profit: -$10,650.00
- Net Profit Margin: -71.00%

ADDITIONAL METRICS:
- Total Tips Collected: $420.00
- Best Selling Item: Grilled Chicken
- Peak Hours: 7 PM - 9 PM
- Average Guests per Day: 48

Press Enter to return to menu...
```

### 7.3 Customer Order Screen
```
========================================
        PLACE YOUR ORDER
========================================

MENU:
1. Caesar Salad - $8.00
2. Grilled Chicken - $15.00
3. Pasta Carbonara - $12.00
4. Coke - $2.00
5. Chocolate Cake - $6.00

Enter item number (0 to finish): 2
Enter quantity: 1

Item added! Current total: $15.00

Enter item number (0 to finish): 4
Enter quantity: 2

Item added! Current total: $19.00

Enter item number (0 to finish): 0

Your order total: $19.00
Enter table number: 5

Order confirmed! Your Order ID: 1001
Estimated wait time: 20 minutes
```

---


## 🧭 Navigation

**Next Recommended:**
- 🏗️ [SYSTEM_ARCHITECTURE](../SYSTEM_ARCHITECTURE/readme.md) - Understand the technical design
- 📊 [DATA_STRUCTURES_GUIDE](../DATA_STRUCTURES_GUIDE/readme.md) - See data organization

**Back to:**
- 🏠 [Main README](../../README.md)
- 🚀 [QUICK_START](../QUICK_START/readme.md)
- [Top of this page](#restaurant-management-system-rms---project-documentation)

---

## END OF DOCUMENTATION
