# CP-RMS Overview

## What Problem Does It Solve?
- **Small restaurant helper:** CP-RMS keeps track of what the restaurant sells, who ordered what, how much money came in, and what customers said afterward.
- **Two main roles:**
  - **Admin (staff)** can update the menu, monitor orders, read total revenue, and review feedback.
  - **Client (customer)** can browse the menu, place or cancel an order, check an order’s status, and leave feedback.
- **Always-on memory:** Everything is saved in CSV text files under `data/`, so nothing disappears between runs and the information stays simple to edit or back up.

## High-Level Architecture (Super Simple View)
1. **Single C program (`main.c`)**
   - Starts by making sure each CSV file exists.
   - Shows the main menu with two doors: Admin and Client.
   - Uses helper functions to keep the core logic tidy.
2. **File-based storage**
   - `data/menu.csv` – menu list (id, name, category, price).
   - `data/orders.csv` – order history (id, item id, quantity, status, customer, total price).
   - `data/financial.csv` – lightweight revenue log per completed order.
   - `data/feedback.csv` – customer ratings and comments.
3. **Menu-driven workflows**
   - Each dashboard (Admin/Client) is just a loop: show options, read the choice, call the matching helper, then come back to the dashboard.
   - Helpers always load fresh data from the CSV, tweak it in memory, and save it back immediately.
4. **No external services**
   - No database servers, no background daemons—just the executable and the CSV files.

## Why This Matters for the Business
- **Easy training:** New staff can manage menu items and track orders through clear numbered menus—no SQL or extra tools required.
- **Customer transparency:** Clients can follow their order status themselves and leave feedback without staff intervention.
- **Auditable trail:** Because CSV files keep every action, managers can open them in Excel or any spreadsheet tool to analyze sales and satisfaction.

## Where to Go Next
- Run the program (`build/Debug/outDebug.exe`) to explore the Admin and Client dashboards.
- Check `docs/readme.md` for a kid-friendly deep dive into every helper function if you need more detail.
