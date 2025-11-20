# COMPUTER PROGRAMMING
## Course Code: CS-115

---

# CP-RMS: RESTAURANT MANAGEMENT SYSTEM

**Group Members:**
- Anas Aqeel - CS25139
- Noman - CS25136
- Ali - CS25

**Instructor:** [Your Instructor Name]

**Department of Computer & Information Systems Engineering**  
**NED University of Engineering and Technology**

**Fall Semester 2025**

---

# TABLE OF CONTENTS

**1. INTRODUCTION** ................................................... 1
   - 1.1 Problem Description
   - 1.2 Project Motivation, Relevance, and Beneficiaries
   - 1.3 Distinguishing Features
   - 1.4 Most Challenging Part
   - 1.5 New Things Learned in C

**2. METHODOLOGY** ................................................... 4
   - 2.1 Project Development Process
   - 2.2 Design of the Project
   - 2.3 Algorithms and Pseudocode
   - 2.4 Flowcharts

**3. TOOLS AND PLATFORMS** ................................................... 8
   - 3.1 Development Environment
   - 3.2 Programming Language
   - 3.3 Tools Used

**4. RESULTS AND TEST CASES** ................................................... 9
   - 4.1 Test Case 1: Admin Login and Menu Management
   - 4.2 Test Case 2: Adding Multiple Menu Items
   - 4.3 Test Case 3: Client Order Placement
   - 4.4 Test Case 4: Order Tracking and Status Update
   - 4.5 Test Case 5: Feedback System and Financial Report

**5. CONCLUSION AND FUTURE EXPANSION** ................................................... 15
   - 5.1 Conclusion
   - 5.2 Future Enhancements

**REFERENCES** ................................................... 16

---

# INDIVIDUAL CONTRIBUTION

## Anas Aqeel (CS25XXX)
**Role:** Menu & Inventory Module Developer

**Responsibilities:**
- Designed and implemented the menu management system
- Developed functions for adding and viewing menu items
- Created the main menu interface and navigation structure
- Implemented file handling for menu data persistence
- Designed user-friendly display formats and menus
- Handled input validation for menu items

**Key Functions Developed:**
- `printMainMenu()`, `printAdminMenu()`, `printClientMenu()`
- `viewMenu()`, `addMenuItem()`
- `saveMenuToFile()`, `loadMenuFromFile()`

---

## Noman (CS25XXX)
**Role:** Orders Module Developer

**Responsibilities:**
- Designed and implemented the complete order management system
- Developed order placement functionality for clients
- Created order tracking and status update features
- Implemented order validation and error handling
- Developed file operations for order persistence
- Created search functionality for finding menu items

**Key Functions Developed:**
- `placeOrder()`, `trackOrder()`, `viewAllOrders()`
- `updateOrderStatus()`, `clientUpdateOrder()`
- `findMenuItem()`
- `saveOrdersToFile()`, `loadOrdersFromFile()`

---

## Ali (CS25XXX)
**Role:** Feedback & Financial Module Developer

**Responsibilities:**
- Designed and implemented the customer feedback system
- Developed the financial reporting module
- Created feedback validation and rating system
- Implemented financial calculations and revenue tracking
- Developed file operations for feedback and financial data
- Created comprehensive reporting features

**Key Functions Developed:**
- `giveFeedback()`, `viewAllFeedback()`
- `viewFinancialReport()`
- `saveFeedbackToFile()`, `loadFeedbackFromFile()`
- `saveFinancialToFile()`, `loadFinancialFromFile()`

---

# CHAPTER 1: INTRODUCTION

## 1.1 Problem Description

The restaurant industry faces significant challenges in managing daily operations efficiently. Small to medium-sized restaurants often struggle with:

- Manual order taking leading to errors and delays
- Difficulty in tracking order status and customer satisfaction
- Lack of organized menu management systems
- Poor financial record keeping
- Absence of customer feedback mechanisms

CP-RMS (Computer Programming - Restaurant Management System) addresses these challenges by providing a comprehensive, console-based solution that streamlines restaurant operations. The system enables efficient menu management, order processing, customer feedback collection, and financial tracking—all through a simple, user-friendly interface.

## 1.2 Project Motivation, Relevance, and Beneficiaries

### Motivation
The motivation behind CP-RMS stems from observing real-world inefficiencies in local restaurants. Many establishments still rely on paper-based systems or basic spreadsheets, leading to:
- Lost orders and customer dissatisfaction
- Revenue tracking errors
- Inability to analyze customer preferences
- Time-consuming manual processes

### Relevance
In today's digital age, even small businesses need automated solutions. CP-RMS is relevant because:
- It provides an affordable, lightweight solution requiring minimal hardware
- The console-based interface is simple enough for staff with basic computer skills
- It addresses core restaurant needs without overwhelming complexity
- Data persistence ensures information is never lost

### Beneficiaries
**Restaurant Owners:** Gain insights into financial performance, order trends, and customer satisfaction without expensive software.

**Restaurant Staff:** Simplify order management, reduce errors, and serve customers faster.

**Customers:** Experience faster service, accurate order tracking, and a channel to provide feedback.

**Small Businesses:** Access enterprise-level features at no cost, helping them compete with larger establishments.

## 1.3 Distinguishing Features

CP-RMS stands out from similar systems through several key features:

1. **Dual Interface System**
   - Separate admin and client panels for role-based access
   - Admin password protection for data security

2. **Comprehensive Order Management**
   - Real-time order status tracking
   - Flexible order updates from both admin and client sides
   - Automatic revenue calculation

3. **Data Persistence**
   - Automatic saving and loading of all data
   - No data loss between sessions
   - Simple text file storage for easy data recovery

4. **Customer-Centric Design**
   - Built-in feedback system with rating mechanism
   - Order tracking for customer transparency
   - User-friendly prompts and error messages

5. **Financial Intelligence**
   - Automatic revenue tracking
   - Detailed financial reports with order statistics
   - Completed vs. pending order analysis

6. **Robust Error Handling**
   - Validation for all user inputs
   - Meaningful error messages
   - Protection against invalid operations

## 1.4 Most Challenging Part

The most challenging aspect of developing CP-RMS was implementing **data persistence with file operations** while maintaining code simplicity. 

**Specific Challenges:**

1. **File Format Design:** Creating a file format that could store structured data (menu items, orders, feedback) in plain text while remaining easy to read and parse.

2. **Data Synchronization:** Ensuring that in-memory data and file data remained synchronized, especially when multiple operations occurred before saving.

3. **Error Handling in File Operations:** Managing scenarios where files might not exist, be corrupted, or be inaccessible without crashing the program.

4. **String Parsing:** Using `fscanf()` with delimiters to read multi-field records while handling special characters in strings (especially in customer names and feedback comments).

**Solution Approach:**
We overcame these challenges by:
- Using pipe (`|`) delimiters to separate fields in files
- Implementing silent fail mechanisms for file operations (if a file doesn't exist, the program continues with empty data)
- Testing various input scenarios to ensure the parsing logic was robust
- Using the `%[^|]` format specifier to read strings until a delimiter

## 1.5 New Things Learned in C

Through this project, we gained practical experience with several C programming concepts:

1. **Advanced String Handling**
   - Using `fgets()` instead of `scanf()` for strings with spaces
   - String manipulation with `strcpy()`, `strcmp()`, and `strcspn()`
   - Removing newline characters from fgets input

2. **File Input/Output Operations**
   - Opening, reading, writing, and closing files with `fopen()`, `fprintf()`, `fscanf()`, `fclose()`
   - Custom format specifiers like `%[^|]` for reading until specific delimiters
   - Understanding file pointers and checking for NULL

3. **Modular Programming**
   - Breaking down a large program into manageable functions
   - Creating utility functions for reusable code
   - Organizing code by functional modules

4. **Input Buffer Management**
   - Understanding the input buffer and why it needs to be cleared
   - Implementing `clearInputBuffer()` to prevent input issues
   - Combining `scanf()` and `fgets()` safely

5. **Data Structure Organization**
   - Using arrays of structures to organize related data
   - Managing parallel arrays (menu, orders, feedback)
   - Implementing search functionality across data structures

6. **Validation and Error Handling**
   - Checking for edge cases (empty arrays, invalid IDs, negative values)
   - Providing user-friendly error messages
   - Preventing program crashes from invalid input

---

# CHAPTER 2: METHODOLOGY

## 2.1 Project Development Process

The development of CP-RMS followed a systematic, team-based approach:

### Phase 1: Planning and Analysis (Week 1)
- Identified core requirements for a restaurant management system
- Analyzed similar systems to understand common features
- Defined user roles (Admin and Client)
- Created a feature list and prioritized functionalities

### Phase 2: Design (Week 2)
- Designed the overall system architecture
- Created flowcharts for major functions
- Divided responsibilities among team members
- Designed data structures (MenuItem, Order, Feedback)

### Phase 3: Implementation (Weeks 3-4)
- Each team member implemented their assigned module
- **Anas:** Developed menu management and interface systems
- **Noman:** Implemented order processing and tracking
- **Ali:** Created feedback and financial reporting modules

### Phase 4: Integration and Testing (Week 5)
- Integrated all modules into a single system
- Performed unit testing on individual functions
- Conducted integration testing to ensure modules worked together
- Fixed bugs and improved error handling

### Phase 5: Enhancement and Documentation (Week 6)
- Added file operations for data persistence
- Improved user interface and messages
- Implemented additional validation
- Created comprehensive documentation

## 2.2 Design of the Project

### System Architecture

CP-RMS follows a **modular, function-based architecture** with three main components:

```
CP-RMS System
│
├── Menu & Inventory Module (Anas)
│   ├── Menu Display
│   ├── Menu Item Management
│   └── Menu Data Persistence
│
├── Orders Module (Noman)
│   ├── Order Placement
│   ├── Order Tracking
│   ├── Order Status Management
│   └── Order Data Persistence
│
└── Feedback & Financials Module (Ali)
    ├── Feedback Collection
    ├── Feedback Display
    ├── Financial Reporting
    └── Data Persistence
```

### Design Explanation

**1. Data Layer:**
The system uses three primary data structures stored as global arrays:
- `menu[]`: Stores all menu items with ID, name, category, and price
- `orders[]`: Stores all orders with ID, item ID, quantity, status, customer name, and total
- `feedbacks[]`: Stores customer feedback with ID, item ID, rating, and comments

**2. Presentation Layer:**
User interaction is handled through menu-driven interfaces:
- Main menu for role selection (Admin/Client)
- Admin panel with management features
- Client panel with ordering and feedback features

**3. Business Logic Layer:**
Core functionality is implemented through modular functions:
- Each operation (add menu item, place order, etc.) has its own function
- Validation logic is embedded within each function
- File operations are separated into save/load function pairs

**4. Persistence Layer:**
Data is saved to and loaded from four text files:
- `menu.txt`: Menu items
- `orders.txt`: Order records
- `feedback.txt`: Customer feedback
- `financial.txt`: Revenue total

## 2.3 Algorithms and Pseudocode

### Algorithm 1: Add Menu Item

**Purpose:** Allow admin to add a new item to the menu

**Algorithm:**
```
1. START
2. Check if menu is full (menu_count >= MAX_MENU)
   2.1 If full, display error message and EXIT
3. Prompt admin for item name
4. Read item name using fgets
5. Prompt admin for category
6. Read category using fgets
7. Prompt admin for price
8. Read price
9. Validate price (must be > 0)
   9.1 If invalid, display error and EXIT
10. Create new menu item:
    10.1 Set id = menu_count + 1
    10.2 Copy name and category
    10.3 Set price
11. Increment menu_count
12. Display success message
13. END
```

**Pseudocode:**
```
FUNCTION addMenuItem():
    IF menu_count >= MAX_MENU THEN
        PRINT "Menu is full"
        RETURN
    END IF
    
    INPUT name, category, price
    
    IF price <= 0 THEN
        PRINT "Invalid price"
        RETURN
    END IF
    
    menu[menu_count].id = menu_count + 1
    menu[menu_count].name = name
    menu[menu_count].category = category
    menu[menu_count].price = price
    
    menu_count = menu_count + 1
    
    PRINT "Menu item added successfully"
END FUNCTION
```

### Algorithm 2: Place Order

**Purpose:** Allow client to place a new order

**Algorithm:**
```
1. START
2. Check if order limit reached
   2.1 If reached, display error and EXIT
3. Check if menu is empty
   3.1 If empty, display error and EXIT
4. Prompt for item ID
5. Read item ID
6. Search for item in menu
   6.1 If not found, display error and EXIT
7. Prompt for quantity
8. Read quantity
9. Validate quantity (must be > 0)
   9.1 If invalid, display error and EXIT
10. Prompt for customer name
11. Read customer name
12. Create new order:
    12.1 Set order ID
    12.2 Set item ID and quantity
    12.3 Set customer name
    12.4 Set status to "Pending"
    12.5 Calculate total = item price × quantity
13. Increment order_count
14. Display success message with order ID and total
15. END
```

**Pseudocode:**
```
FUNCTION placeOrder():
    IF order_count >= MAX_ORDERS THEN
        PRINT "Order limit reached"
        RETURN
    END IF
    
    IF menu_count == 0 THEN
        PRINT "No menu items available"
        RETURN
    END IF
    
    INPUT item_id, qty, customer_name
    
    index = findMenuItem(item_id)
    IF index == -1 THEN
        PRINT "Invalid Item ID"
        RETURN
    END IF
    
    IF qty <= 0 THEN
        PRINT "Invalid quantity"
        RETURN
    END IF
    
    orders[order_count].id = order_count + 1
    orders[order_count].item_id = item_id
    orders[order_count].qty = qty
    orders[order_count].customer = customer_name
    orders[order_count].status = "Pending"
    orders[order_count].total = menu[index].price * qty
    
    order_count = order_count + 1
    
    PRINT "Order placed successfully"
END FUNCTION
```

### Algorithm 3: Update Order Status

**Purpose:** Allow admin to update the status of an order

**Algorithm:**
```
1. START
2. Check if orders exist
   2.1 If no orders, display message and EXIT
3. Prompt for order ID
4. Read order ID
5. Search for order in orders array
6. FOR each order in orders:
   6.1 IF order.id matches input ID:
       6.1.1 Display current status
       6.1.2 Prompt for new status
       6.1.3 Read new status
       6.1.4 Update order status
       6.1.5 IF new status is "Completed":
             6.1.5.1 Add order total to financial_total
       6.1.6 Display success message
       6.1.7 Set found = true
       6.1.8 BREAK
7. IF order not found:
   7.1 Display error message
8. END
```

### Algorithm 4: Give Feedback

**Purpose:** Allow client to submit feedback for a menu item

**Algorithm:**
```
1. START
2. Check if feedback array is full
3. Check if menu is empty
4. Prompt for item ID
5. Validate item ID exists in menu
6. Prompt for rating (1-5)
7. Validate rating is between 1 and 5
8. Prompt for comment
9. Read comment using fgets
10. Create new feedback entry
11. Increment feedback_count
12. Display thank you message
13. END
```

### Algorithm 5: View Financial Report

**Purpose:** Display comprehensive financial statistics

**Algorithm:**
```
1. START
2. Display report header
3. IF no orders exist:
   3.1 Display "0 orders, Rs.0 revenue"
   3.2 EXIT
4. Initialize counters: completed=0, pending=0, cancelled=0
5. FOR each order in orders:
   5.1 IF status is "Completed": increment completed
   5.2 ELSE IF status is "Cancelled": increment cancelled
   5.3 ELSE: increment pending
6. Display:
   6.1 Total orders
   6.2 Completed orders count
   6.3 Pending orders count
   6.4 Cancelled orders count
   6.5 Total revenue
7. END
```

## 2.4 Flowcharts

### Flowchart 1: Main Program Flow

```
[START]
   |
   v
[Load All Data from Files]
   |
   v
[Display Welcome Message]
   |
   v
[Display Main Menu]
   |
   v
[Read User Choice]
   |
   v
<Choice = 0?> --Yes--> [Save All Data] --> [Display Goodbye] --> [END]
   |
   No
   |
   v
<Choice = 1?> --Yes--> [Admin Login] --> [Admin Panel]
   |                                           |
   No                                          v
   |                                    [Back to Main Menu]
   v
<Choice = 2?> --Yes--> [Client Panel] --> [Back to Main Menu]
   |
   No
   |
   v
[Display Invalid Choice]
   |
   v
[Loop back to Display Main Menu]
```

### Flowchart 2: Add Menu Item Process

```
[START: addMenuItem]
   |
   v
<menu_count >= MAX_MENU?> --Yes--> [Display "Menu Full"] --> [RETURN]
   |
   No
   |
   v
[Input: name]
   |
   v
[Input: category]
   |
   v
[Input: price]
   |
   v
<price <= 0?> --Yes--> [Display "Invalid Price"] --> [RETURN]
   |
   No
   |
   v
[Set menu[menu_count].id = menu_count + 1]
   |
   v
[Copy name to menu[menu_count].name]
   |
   v
[Copy category to menu[menu_count].category]
   |
   v
[Set menu[menu_count].price = price]
   |
   v
[Increment menu_count]
   |
   v
[Display "Item Added Successfully"]
   |
   v
[RETURN]
```

### Flowchart 3: Place Order Process

```
[START: placeOrder]
   |
   v
<order_count >= MAX_ORDERS?> --Yes--> [Display "Order Limit Reached"] --> [RETURN]
   |
   No
   |
   v
<menu_count == 0?> --Yes--> [Display "No Menu Items"] --> [RETURN]
   |
   No
   |
   v
[Input: item_id]
   |
   v
[Call findMenuItem(item_id)]
   |
   v
<Item Found?> --No--> [Display "Invalid Item ID"] --> [RETURN]
   |
   Yes
   |
   v
[Input: quantity]
   |
   v
<quantity <= 0?> --Yes--> [Display "Invalid Quantity"] --> [RETURN]
   |
   No
   |
   v
[Input: customer_name]
   |
   v
[Create new order with all details]
   |
   v
[Calculate total = price × quantity]
   |
   v
[Set status = "Pending"]
   |
   v
[Increment order_count]
   |
   v
[Display "Order Placed" with Order ID]
   |
   v
[RETURN]
```

### Flowchart 4: Track Order Process

```
[START: trackOrder]
   |
   v
<order_count == 0?> --Yes--> [Display "No Orders"] --> [RETURN]
   |
   No
   |
   v
[Input: order_id]
   |
   v
[Initialize: found = 0, i = 0]
   |
   v
<i < order_count?> --No--> <found == 0?> --Yes--> [Display "Order Not Found"]
   |                              |                          |
   Yes                            No                         v
   |                              |                      [RETURN]
   v                              v
<orders[i].id == order_id?> [RETURN]
   |           |
   No         Yes
   |           |
   v           v
[i++]    [Display Order Details]
   |           |
   |           v
   |      [Set found = 1]
   |           |
   |<----------+
   |
[Loop back]
```

### Flowchart 5: Admin Login Process

```
[START: adminLogin]
   |
   v
[Display "Enter Password"]
   |
   v
[Input: password]
   |
   v
<password == ADMIN_PASSWORD?> --Yes--> [Display "Login Successful"] --> [Return 1]
   |
   No
   |
   v
[Display "Incorrect Password"]
   |
   v
[Return 0]
```

---

# CHAPTER 3: TOOLS AND PLATFORMS

## 3.1 Development Environment

**Operating System:** Windows 10/11

**IDE Used:** Code::Blocks 20.03 / Visual Studio Code

**Compiler:** GCC (GNU Compiler Collection) version 11.2.0

The development environment was chosen for its accessibility and ease of use. Code::Blocks provides a lightweight IDE with built-in GCC compiler, making it ideal for C programming projects.

## 3.2 Programming Language

**Language:** C (ANSI C / C99 Standard)

C was selected for this project due to:
- Course requirement (CS-115 Computer Programming)
- Excellent performance and efficiency
- Direct memory management capabilities
- Portability across different platforms
- Strong support for file operations
- Widely available compilers and development tools

## 3.3 Tools Used

### Development Tools

1. **Code::Blocks / Visual Studio Code**
   - Primary code editor and development environment
   - Syntax highlighting and code completion
   - Integrated debugging tools
   - Build automation

2. **GCC Compiler**
   - Compiles C source code to executable
   - Provides warning and error messages
   - Optimization options for better performance

3. **GDB Debugger**
   - Used for debugging and testing
   - Step-by-step code execution
   - Variable inspection and breakpoints

### Documentation Tools

1. **Microsoft Word**
   - Report writing and formatting
   - Table of contents generation
   - Professional document layout

2. **Draw.io / Lucidchart**
   - Flowchart creation
   - System architecture diagrams
   - Visual design documentation

### Version Control

1. **Git / GitHub**
   - Source code version control
   - Collaboration among team members
   - Backup and recovery of code

### Testing Tools

1. **Manual Testing**
   - Console-based testing of all features
   - Input validation testing
   - Edge case verification

2. **Text Editor (Notepad++)**
   - Viewing and verifying data files
   - Checking file format correctness

---

# CHAPTER 4: RESULTS AND TEST CASES

This chapter demonstrates the functionality of CP-RMS through five comprehensive test cases covering all major features of the system.

## 4.1 Test Case 1: Admin Login and Menu Management

**Objective:** Verify admin authentication and menu viewing functionality

**Test Steps:**
1. Launch CP-RMS application
2. Select Admin Panel (Option 1)
3. Enter admin password: "admin123"
4. Select View Menu Items (Option 1)

**Expected Output:**
- Successful authentication
- Display of all menu items in formatted table
- If no items exist, display "No menu items available"

**Screenshot Description:**
```
========================================
   CP-RMS: RESTAURANT MANAGEMENT SYSTEM
========================================
1. Admin Panel
2. Client Panel
0. Exit
========================================
Enter your choice: 1

--- Admin Login ---
Enter Password: admin123
[✓] Login successful!

========================================
           ADMIN PANEL
========================================
1. View Menu Items
2. Add New Menu Item
3. View All Orders
4. Update Order Status
5. View Financial Report
6. View Customer Feedback
0. Back to Main Menu
========================================
Enter your choice: 1

[!] No menu items available.
```

**Result:** ✓ PASSED - System correctly authenticates admin and handles empty menu scenario

---

## 4.2 Test Case 2: Adding Multiple Menu Items

**Objective:** Test menu item addition with validation

**Test Steps:**
1. From Admin Panel, select Add New Menu Item (Option 2)
2. Add Item 1: Name="Chicken Biryani", Category="Main Course", Price=350
3. Add Item 2: Name="Seekh Kabab", Category="Appetizer", Price=200
4. Add Item 3: Name="Mango Lassi", Category="Beverages", Price=150
5. Attempt to add invalid item with negative price
6. View menu to verify additions

**Expected Output:**
- Successful addition of valid items with unique IDs
- Rejection of invalid price with error message
- Display of all added items in formatted table

**Screenshot Description:**
```
--- Add New Menu Item ---
Enter item name: Chicken Biryani
Enter category: Main Course
Enter price (Rs): 350
[✓] Menu item added successfully! Item ID: 1

--- Add New Menu Item ---
Enter item name: Seekh Kabab
Enter category: Appetizer
Enter price (Rs): 200
[✓] Menu item added successfully! Item ID: 2

--- Add New Menu Item ---
Enter item name: Mango Lassi
Enter category: Beverages
Enter price (Rs): 150
[✓] Menu item added successfully! Item ID: 3

--- Add New Menu Item ---
Enter item name: Invalid Item
Enter category: Test
Enter price (Rs): -50
[!] Invalid price. Please enter a positive value.

========================================
           MENU ITEMS
========================================
ID    Name                 Category        Price     
----------------------------------------
1     Chicken Biryani      Main Course     Rs.350    
2     Seekh Kabab          Appetizer       Rs.200    
3     Mango Lassi          Beverages       Rs.150    
========================================
```

**Result:** ✓ PASSED - System correctly validates input and adds menu items with proper formatting

---

## 4.3 Test Case 3: Client Order Placement

**Objective:** Test order placement functionality with validation

**Test Steps:**
1. Navigate to Client Panel (Option 2 from main menu)
2. View menu (Option 1)
3. Place Order (Option 2)
   - Item ID: 1 (Chicken Biryani)
   - Quantity: 2
   - Customer Name: "Ahmed Khan"
4. Attempt to place order with invalid Item ID: 99
5. Attempt to place order with negative quantity
6. Place another valid order
   - Item ID: 3 (Mango Lassi)
   - Quantity: 3
   - Customer Name: "Sara Ali"

**Expected Output:**
- Valid orders accepted with confirmation and Order ID
- Invalid Item ID rejected with error message
- Negative quantity rejected with error message
- Correct total calculation (price × quantity)

**Screenshot Description:**
```
========================================
           CLIENT PANEL
========================================
1. View Menu
2. Place Order
3. Track My Order
4. Update My Order
5. Give Feedback
0. Back to Main Menu
========================================
Enter your choice: 2

--- Place Your Order ---
Enter Item ID: 1
Enter Quantity: 2
Enter Customer Name: Ahmed Khan

[✓] Order placed successfully!
    Order ID: 1
    Total Amount: Rs.700

--- Place Your Order ---
Enter Item ID: 99
[!] Invalid Item ID. Please check the menu.

--- Place Your Order ---
Enter Item ID: 1
Enter Quantity: -5
[!] Invalid quantity. Please enter a positive number.

--- Place Your Order ---
Enter Item ID: 3
Enter Quantity: 3
Enter Customer Name: Sara Ali

[✓] Order placed successfully!
    Order ID: 2
    Total Amount: Rs.450
```

**Result:** ✓ PASSED - System correctly handles order placement with proper validation and calculation

---

## 4.4 Test Case 4: Order Tracking and Status Update

**Objective:** Test order tracking and admin status update functionality

**Test Steps:**
1. **Client Side - Track Order:**
   - Navigate to Client Panel
   - Select Track Order (Option 3)
   - Enter Order ID: 1
   - Verify order details displayed

2. **Admin Side - Update Status:**
   - Navigate to Admin Panel
   - View All Orders (Option 3)
   - Update Order Status (Option 4)
   - Change Order 1 status to "Preparing"
   - Change Order 2 status to "Completed"

3. **Client Side - Verify Update:**
   - Track Order ID: 1 again
   - Verify status changed to "Preparing"

**Expected Output:**
- Order details displayed correctly for valid Order ID
- Error message for invalid Order ID
- Status successfully updated by admin
- Financial total updated when order marked "Completed"

**Screenshot Description:**
```
--- Track Your Order ---
Enter Order ID: 1

========================================
Order ID: 1
Customer: Ahmed Khan
Item ID: 1
Quantity: 2
Total: Rs.700
Status: Pending
========================================

[ADMIN PANEL]
========================================
           ALL ORDERS
========================================
ID    Item ID  Qty   Status       Customer        Total     
----------------------------------------
1     1        2     Pending      Ahmed Khan      Rs.700    
2     3        3     Pending      Sara Ali        Rs.450    
========================================

--- Update Order Status ---
Enter Order ID: 1
Current Status: Pending
Enter New Status (Pending/Preparing/Completed/Cancelled): Preparing
[✓] Order status updated successfully!

--- Update Order Status ---
Enter Order ID: 2
Current Status: Pending
Enter New Status (Pending/Preparing/Completed/Cancelled): Completed
[✓] Order status updated successfully!

[CLIENT TRACKING AGAIN]
--- Track Your Order ---
Enter Order ID: 1

========================================
Order ID: 1
Customer: Ahmed Khan
Item ID: 1
Quantity: 2
Total: Rs.700
Status: Preparing
========================================
```

**Result:** ✓ PASSED - Order tracking and status updates work correctly with proper synchronization

---

## 4.5 Test Case 5: Feedback System and Financial Report

**Objective:** Test feedback submission and financial reporting

**Test Steps:**
1. **Submit Feedback:**
   - Navigate to Client Panel
   - Select Give Feedback (Option 5)
   - Submit feedback for Item ID: 1
     - Rating: 5
     - Comment: "Excellent taste and quality"
   - Attempt invalid rating (7)
   - Submit feedback for Item ID: 3
     - Rating: 4
     - Comment: "Very refreshing drink"

2. **View Admin Reports:**
   - Navigate to Admin Panel
   - View Customer Feedback (Option 6)
   - View Financial Report (Option 5)

**Expected Output:**
- Valid feedback accepted with ratings 1-5
- Invalid ratings rejected
- Feedback displayed in admin panel
- Financial report shows correct statistics and revenue

**Screenshot Description:**
```
[CLIENT PANEL - FEEDBACK]
--- Give Your Feedback ---
Enter Item ID: 1
Enter Rating (1-5): 5
Enter Comment: Excellent taste and quality
[✓] Thank you for your feedback!

--- Give Your Feedback ---
Enter Item ID: 1
Enter Rating (1-5): 7
[!] Invalid rating. Please enter a value between 1 and 5.

--- Give Your Feedback ---
Enter Item ID: 3
Enter Rating (1-5): 4
Enter Comment: Very refreshing drink
[✓] Thank you for your feedback!

[ADMIN PANEL - VIEW FEEDBACK]
========================================
         CUSTOMER FEEDBACK
========================================
ID    Item ID    Rating   Comment                       
----------------------------------------
1     1          5        Excellent taste and quality   
2     3          4        Very refreshing drink         
========================================

[ADMIN PANEL - FINANCIAL REPORT]
========================================
         FINANCIAL REPORT
========================================
Total Orders: 2
Completed Orders: 1
Pending Orders: 1
Cancelled Orders: 0

Total Revenue: Rs.450
========================================
```

**Result:** ✓ PASSED - Feedback system validates ratings correctly, and financial report accurately displays statistics and revenue from completed orders only

---

## Test Cases Summary

| Test Case | Feature Tested | Status | Key Validation |
|-----------|---------------|--------|----------------|
| TC-1 | Admin Login & Menu View | ✓ PASSED | Authentication, Empty data handling |
| TC-2 | Add Menu Items | ✓ PASSED | Price validation, Data storage |
| TC-3 | Order Placement | ✓ PASSED | Item ID validation, Quantity validation, Total calculation |
| TC-4 | Order Tracking & Status | ✓ PASSED | Order search, Status updates, Financial sync |
| TC-5 | Feedback & Reports | ✓ PASSED | Rating validation, Statistics calculation |

**Overall System Performance:** All test cases passed successfully, demonstrating robust error handling, proper validation, and accurate data management.

---

# CHAPTER 5: CONCLUSION AND FUTURE EXPANSION

## 5.1 Conclusion

The CP-RMS (Restaurant Management System) project successfully demonstrates the application of fundamental C programming concepts to solve a real-world business problem. Through this project, we have created a functional, console-based system that addresses the core needs of restaurant operations.

### Key Achievements

1. **Successful Implementation of Core Features:**
   - Complete menu management system with add, view, and persist capabilities
   - Comprehensive order processing with real-time tracking
   - Customer feedback mechanism with rating validation
   - Financial reporting with detailed statistics

2. **Robust Error Handling:**
   - The system gracefully handles all edge cases including empty data sets, invalid inputs, and out-of-range values
   - User-friendly error messages guide users to correct their mistakes
   - No crashes or undefined behavior even with incorrect input

3. **Effective Team Collaboration:**
   - Clear division of responsibilities among three team members
   - Modular code structure that allowed parallel development
   - Successful integration of all modules into a cohesive system

4. **Data Persistence:**
   - Implementation of file I/O operations ensures no data loss
   - Simple text-based file format allows for easy backup and recovery
   - Automatic save/load functionality provides seamless user experience

5. **User-Centric Design:**
   - Separate interfaces for admin and client roles
   - Clear, intuitive menu structure
   - Informative prompts and confirmations

### Learning Outcomes

Through the development of CP-RMS, our team gained valuable experience in:
- Modular programming and function decomposition
- Advanced string handling and input management
- File operations for data persistence
- Validation and error handling techniques
- Team-based software development
- Problem-solving and debugging

### Project Impact

CP-RMS demonstrates that effective management solutions don't require complex technologies or expensive software. A well-designed console application can provide:
- Affordable automation for small businesses
- Easy deployment with minimal hardware requirements
- Straightforward operation requiring minimal training
- Reliable data management and reporting

The project successfully fulfills all requirements outlined in the Computer Programming course objectives, particularly in applying basic programming structures (CLO 2) to solve a complex engineering problem.

## 5.2 Future Enhancements

While CP-RMS currently meets its core objectives, several enhancements could expand its functionality and usability:

### 1. Enhanced User Interface
**Graphical User Interface (GUI):**
- Transition from console to GUI using libraries like GTK+ or Qt
- Visual menu display with images of food items
- Interactive buttons and forms for easier navigation
- Real-time dashboard with charts and graphs

**Web-Based Interface:**
- Convert to a web application using HTML/CSS for frontend
- Enable access from multiple devices (computers, tablets, smartphones)
- Cloud-based deployment for remote access

### 2. Advanced Database Management
**Database Integration:**
- Replace text files with SQLite or MySQL database
- Improved data query performance
- Support for concurrent users
- Better data integrity and relationships

**Data Analytics:**
- Sales trend analysis over time periods
- Popular items identification
- Peak hours and busy days reporting
- Customer preference patterns

### 3. Expanded Functionality
**Inventory Management:**
- Track ingredient stock levels
- Low stock alerts and notifications
- Automatic reorder suggestions
- Supplier management

**Table Management:**
- Table reservation system
- Dine-in order assignment to tables
- Table status tracking (occupied, available, reserved)

**Staff Management:**
- Employee login and role-based access
- Shift scheduling
- Performance tracking
- Commission calculation for waiters

**Multi-Branch Support:**
- Manage multiple restaurant locations
- Centralized reporting across branches
- Branch-wise inventory and sales tracking

### 4. Payment Integration
**Multiple Payment Methods:**
- Cash, card, and digital wallet support
- Payment status tracking
- Receipt generation
- Refund management

**Online Payment Gateway:**
- Integration with payment processors
- Secure transaction handling
- Payment history and invoicing

### 5. Customer Features
**Customer Accounts:**
- User registration and login
- Order history tracking
- Favorite items list
- Loyalty points and rewards program

**Online Ordering:**
- Browse menu and place orders remotely
- Delivery address management
- Order scheduling (pre-order for later)
- Real-time order status notifications

### 6. Reporting Enhancements
**Advanced Reports:**
- Daily, weekly, monthly sales reports
- Item-wise profit margins
- Tax calculations and reports
- Export reports to PDF/Excel

**Visual Analytics:**
- Sales graphs and charts
- Comparison reports (month-over-month, year-over-year)
- Predictive analysis for inventory planning

### 7. Communication Features
**Notifications:**
- SMS/Email notifications to customers
- Order ready alerts
- Promotional messages
- Feedback reminders

**Kitchen Display System:**
- Real-time order display in kitchen
- Priority-based order queue
- Preparation time tracking

### 8. Security Enhancements
**Advanced Authentication:**
- Multi-level user roles (Owner, Manager, Chef, Waiter)
- Password encryption
- Session management
- Activity logging and audit trails

**Data Security:**
- Encrypted data storage
- Regular automated backups
- Data recovery mechanisms
- Compliance with data protection regulations

### 9. Mobile Application
**Dedicated Mobile Apps:**
- Android and iOS applications
- Push notifications for orders
- QR code scanning for table orders
- Mobile payment integration

### 10. AI and Automation
**Smart Recommendations:**
- AI-based menu recommendations to customers
- Upselling suggestions based on order patterns
- Demand forecasting for inventory

**Chatbot Integration:**
- Automated customer support
- FAQ handling
- Order placement through chat

### Implementation Priority

For a small restaurant looking to expand CP-RMS, we recommend the following priority order:

**Phase 1 (Short-term - 1-3 months):**
1. Database integration (SQLite)
2. Enhanced reporting with exports
3. Basic inventory tracking

**Phase 2 (Medium-term - 3-6 months):**
1. Web-based interface
2. Online ordering system
3. Payment integration
4. SMS/Email notifications

**Phase 3 (Long-term - 6-12 months):**
1. Mobile applications
2. Multi-branch support
3. Advanced analytics and AI features
4. Complete ecosystem with supplier integration

### Conclusion on Future Scope

The future enhancements outlined above would transform CP-RMS from a basic management tool into a comprehensive restaurant ecosystem. However, the current system provides a solid foundation that can be incrementally improved based on specific business needs and available resources. The modular structure of the existing code makes it relatively straightforward to add new features without disrupting core functionality.

---

# REFERENCES

1. Kernighan, B. W., & Ritchie, D. M. (1988). *The C Programming Language* (2nd ed.). Prentice Hall.

2. Deitel, P., & Deitel, H. (2015). *C How to Program* (8th ed.). Pearson Education.

3. GeeksforGeeks. (2024). File Handling in C. Retrieved from https://www.geeksforgeeks.org/file-handling-c-classes/

4. TutorialsPoint. (2024). C Programming Tutorial. Retrieved from https://www.tutorialspoint.com/cprogramming/index.htm

5. Cprogramming.com. (2024). C Tutorial. Retrieved from https://www.cprogramming.com/tutorial/c-tutorial.html

6. Stack Overflow. (2024). C Programming Questions and Solutions. Retrieved from https://stackoverflow.com/questions/tagged/c

7. GitHub. (2024). Restaurant Management System Projects. Retrieved from https://github.com/topics/restaurant-management-system

8. Microsoft Docs. (2024). C Language Reference. Retrieved from https://docs.microsoft.com/en-us/cpp/c-language/

9. Lecture Notes, CS-115 Computer Programming, NED University of Engineering and Technology, Fall 2025.

10. Project Guidelines and Rubric, CS-115 Computer Programming Complex Engineering Problem, Department of Computer & Information Systems Engineering, NED UET, 2025.

---

## APPENDIX

### A. File Structure
The CP-RMS system creates and maintains four data files:

1. **menu.txt** - Stores menu items in format: `id|name|category|price`
2. **orders.txt** - Stores orders in format: `id|item_id|qty|status|customer|total`
3. **feedback.txt** - Stores feedback in format: `id|item_id|rating|comment`
4. **financial.txt** - Stores total revenue as a single integer value

### B. System Requirements
**Minimum Hardware:**
- Processor: Intel Pentium 4 or equivalent
- RAM: 512 MB
- Storage: 10 MB free space
- Display: Any standard monitor

**Software:**
- Operating System: Windows 7/8/10/11, Linux, or macOS
- C Compiler: GCC 4.8 or later
- IDE: Code::Blocks, Visual Studio Code, or any text editor

### C. Installation and Usage
1. Compile the source code using GCC:
   ```
   gcc main.c -o CP-RMS.exe
   ```
2. Run the executable:
   ```
   ./CP-RMS.exe
   ```
3. Default admin password: `admin123`

### D. Known Limitations
- Single-user system (no concurrent access)
- Console-based interface only
- Limited to 50 menu items, 50 orders, and 50 feedback entries
- No built-in backup functionality
- Comments limited to single line without pipes (|)

### E. Troubleshooting
**Common Issues:**
- **Issue:** Program doesn't save data
  - **Solution:** Ensure write permissions in program directory
  
- **Issue:** Input buffer problems
  - **Solution:** System automatically clears buffer, but ensure proper input format

- **Issue:** File not found errors
  - **Solution:** Files are created automatically on first run

---

**END OF REPORT**

---

## DOCUMENT FORMATTING NOTES

**For MS Word Implementation:**

1. **Title Page:**
   - Insert NED logo at top center
   - Title: "CP-RMS: RESTAURANT MANAGEMENT SYSTEM" (Bold, 18pt)
   - Course info: "Computer Programming (CS-115)" (14pt)
   - Group members with roll numbers (12pt)
   - Instructor name (12pt)
   - Department and semester info at bottom
   - No page number on this page

2. **Table of Contents:**
   - Generate automatically using Word's built-in feature
   - Update page numbers after finalizing document
   - No page number on this page

3. **Individual Contribution Page:**
   - Clear section headers for each member
   - No page number on this page

4. **Main Content (Chapters 1-5):**
   - Start page numbering from Chapter 1
   - Heading 1: Size 14, Bold, Times New Roman
   - Heading 2: Size 12, Bold, Times New Roman
   - Body text: Size 11, Times New Roman
   - Line spacing: 1.5
   - Justified alignment
   - Page numbers in footer (center or right)

5. **References:**
   - Hanging indent format
   - Alphabetically ordered
   - Include page number

**Screenshot Placeholders:**
In the actual Word document, replace the text descriptions with actual screenshots of the program running, showing:
- Console output
- Menu displays
- Input prompts
- Success/error messages
- Data displays


