# CP-RMS Guide (Kid-Friendly)

This file explains the whole restaurant program like you are 10 years old. No fancy words, just simple ideas.

---

## 1. What Is This Program?

- Think of CP-RMS as a digital helper for a tiny restaurant.
- It keeps four simple lists (menu, orders, money, feedback). Each list lives in a `.csv` text file inside the `data/` folder.
- When you run the program, you see a main screen with two doors:
  - **Admin door:** for the restaurant worker.
  - **Client door:** for the hungry customer.
- You press number keys to choose what to do. The program keeps looping until you pick Exit.

### How the story goes
1. The program makes sure every list file exists (it creates them if they are missing).
2. It shows the main menu over and over.
3. Admin tasks let workers edit menu items, watch orders, read money totals, and see feedback.
4. Client tasks let customers see the menu, order food, check order status, finish or cancel an order, and leave a rating.
5. Every time someone changes something, the program writes the update straight into the correct `.csv` file.

---

## 2. The Three Buckets of Information

We store data in simple boxes called **records**.

- **MenuItem**: holds an item ID, the item name, the food group (like drinks), and the price in cents.
- **OrderRecord**: holds an order ID, which menu item was ordered, the quantity, the order status, the customer name, and the total price in cents.
- **FeedbackRecord**: holds a feedback ID, which item the comment is about (can be empty), the rating from 1–5, and the text comment.

Arrays (long rows) of these records sit in memory while we work, then we write them back into the files.

---

## 3. Helper Skills (Functions) in Super-Simple Words

Each helper is shown like this: `function_name(what_it_takes)`.

### 3.1 Everyday helpers
- `trim_newline(text)`
  - **Takes:** A piece of text we want to clean.
  - **Does:** Cuts off the hidden "enter" characters at the end.
  - **Gives back:** Nothing; it just cleans the original text.

- `safe_input(buffer, size)`
  - **Takes:** A box to hold letters and the box size.
  - **Does:** Safely reads what the user typed and removes the final "enter".
  - **Gives back:** Nothing; the box now holds the user text.

- `parse_int(text, result)`
  - **Takes:** A number written as text and a place to store the number.
  - **Does:** Tries to turn the text into a real number.
  - **Gives back:** `0` if it worked, `-1` if the text was not a number.

- `generate_id(prefix, number, out, size)`
  - **Takes:** A letter like `M` or `O`, a number, and a box to store the new ID.
  - **Does:** Makes IDs such as `M005`.
  - **Gives back:** Nothing; the ID appears in `out`.

- `ensure_data_file(filename, header_line)`
  - **Takes:** A file name and the first line we want inside the file.
  - **Does:** If the file is missing, the function creates it and writes the header line.
  - **Gives back:** `0` on success, `-1` on error.

- `read_csv_lines(filename, lines, max_lines)`
  - **Takes:** A file name, a list of empty strings, and how many strings fit in that list.
  - **Does:** Reads each line from the file into the list (skipping extra ones).
  - **Gives back:** How many lines it read (or `-1` if it failed).

- `write_csv_lines(filename, lines, line_count)`
  - **Takes:** A file name, a list of lines, and how many of those lines to write.
  - **Does:** Writes the lines to the file, replacing whatever was there.
  - **Gives back:** `0` on success, `-1` on error.

- `append_csv_line(filename, line)`
  - **Takes:** A file name and one line of text.
  - **Does:** Adds that line to the end of the file.
  - **Gives back:** `0` on success, `-1` on error.

- `parse_csv_fields(line, fields, max_fields)`
  - **Takes:** One CSV line and an empty list to hold each comma piece.
  - **Does:** Splits the line into pieces, respecting quotes.
  - **Gives back:** How many pieces it found.

- `initialize_data_files()`
  - **Takes:** Nothing.
  - **Does:** Calls `ensure_data_file` for menu, orders, feedback, and money files.
  - **Gives back:** Nothing.

- `pause_and_wait()`
  - **Takes:** Nothing.
  - **Does:** Shows "Press Enter to continue" and waits until the user presses Enter.
  - **Gives back:** Nothing.

### 3.2 Menu helpers
- `load_menu_items(items, count)`
  - **Takes:** An empty list of menu items and a spot to store how many were loaded.
  - **Does:** Reads the menu file and fills the list.
  - **Gives back:** `0` if it worked, `-1` if the file could not be read.

- `save_menu_items(items, count)`
  - **Takes:** A filled list of menu items and how many are valid.
  - **Does:** Writes the list back to the menu file.
  - **Gives back:** `0` on success, `-1` on error.

- `print_menu_items(items, count)`
  - **Takes:** A list of menu items and how many to show.
  - **Does:** Prints a neat table of items.
  - **Gives back:** Nothing.

- `find_menu_index_by_id(items, count, id)`
  - **Takes:** The list, its length, and the item ID we want.
  - **Does:** Searches for the ID.
  - **Gives back:** The position where it found it, or `-1` if missing.

### 3.3 Order helpers
- `load_orders(orders, count)` – same idea as `load_menu_items`, but for the orders file.
- `save_orders(orders, count)` – writes orders back to the file.
- `print_orders(orders, count)` – prints each order in a table.
- `find_order_index_by_id(orders, count, id)` – finds the place of a certain order ID.

### 3.4 Feedback helpers
- `load_feedback(entries, count)` – fills the feedback list from file.
- `print_feedback(entries, count)` – prints every feedback entry.
- `update_financials_on_completion(order)` – when an order becomes "Completed," this helper adds a money line to the financial file.

### 3.5 Shared helpers
- `next_identifier_from_lines(filename)`
  - **Takes:** A file name.
  - **Does:** Counts how many lines are already in the file.
  - **Gives back:** That count (or 1 if it could not read). We use the number to build the next ID.

- `collect_price_input(price_cents)`
  - **Takes:** A place to store the price.
  - **Does:** Keeps asking the user until they type a non-negative whole number.
  - **Gives back:** Nothing; the number is stored in `price_cents`.

- `collect_quantity_input(quantity)`
  - Same as above but requires a number greater than zero.

- `confirm_choice(message)`
  - **Takes:** A question like "Are you sure? (y/n)".
  - **Does:** Waits for a yes or no letter.
  - **Gives back:** `1` if the user said yes, `0` otherwise.

### 3.6 Admin task helpers
- `admin_manage_menu()` – lets the worker view/add/edit/delete menu items.
- `admin_manage_orders()` – shows all orders and lets the worker change the status.
- `admin_view_financials()` – totals the money earned so far and shows how many entries exist.
- `admin_view_feedback()` – shows every feedback entry and the average rating.

### 3.7 Client task helpers
- `client_view_menu()` – shows the menu to the customer.
- `client_place_order()` – asks the customer which item, how many, and their name, then saves the order.
- `client_track_order()` – lets the customer type their order ID and see the status.
- `client_update_order_status()` – lets the customer finish or cancel their order.
- `client_leave_feedback()` – lets the customer enter a rating and comment.

### 3.8 Dashboard loops
- `admin_view()` – keeps showing the admin options until "Back" is chosen.
- `client_view()` – keeps showing the client options until "Back" is chosen.

### 3.9 Program start
- `main()` – the very first function that runs. It prepares the files, shows the main doors, and reacts to the user until they pick Exit. It returns `0` when the program is done.

---

## 4. Words From the C Language (Explained Simply)

- `static` – tells C that a helper is private to this file only.
- `typedef` – lets us invent a new simple name for a complicated type.
- `struct` – packs several pieces of data into one box.
- `void` – means "nothing"; used when a helper takes nothing or gives back nothing.
- `int`, `long`, `char`, `size_t` – different kinds of numbers or small letters.
- `const` – promises "we will not change this value" inside the helper.
- `if`, `else`, `for`, `while`, `do`, `break`, `continue` – words that control how the story flows (conditions and loops).
- `return` – ends a helper and optionally hands back a value.
- `sizeof` – asks "how big is this thing".
- `NULL` – a special value that means "there is no real pointer here".

---

## 5. Built-In Helper Functions We Borrowed

| Function | What we hand in | What it does | What it hands back |
|----------|-----------------|--------------|---------------------|
| `printf` | Text with optional values. | Prints words on the screen. | Number of characters printed (or a negative number if it failed). |
| `fgets` | A buffer, its size, and which file/stream to read from. | Reads a line of text safely. | The same buffer on success, or `NULL` on failure. |
| `strlen` | A piece of text. | Counts how many characters are in it. | The character count. |
| `snprintf` | A buffer, its size, and a format. | Builds a string safely without overflowing the buffer. | How many characters it tried to write. |
| `fopen` | File name and mode (like "r" or "w"). | Opens a file. | A file pointer if it worked, `NULL` if not. |
| `fclose` | A file pointer. | Closes the file. | `0` if OK, `EOF` if not. |
| `fprintf` | A file pointer and a format. | Prints formatted text into a file. | Number of characters written (negative if it failed). |
| `strtol` | Text with digits, a pointer to mark the end, and the number base. | Turns text into a `long` number. | The number result (and it updates the end pointer). |
| `strcmp` | Two pieces of text. | Compares them alphabetically. | `<0`, `0`, or `>0` depending on order. |
| `strncpy` | A destination buffer, a source string, and a length. | Copies a limited number of characters safely. | The destination buffer. |

These helpers come from the standard C library, so we did not have to write them ourselves.

---

## 6. Final Notes

- Every helper here works together like players on the same team.
- The code always reads from or writes to the files right away, so nothing gets lost if the power goes out.
- Feel free to add drawings or flowcharts if you want an even friendlier version for kids.
