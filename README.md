# Expense Tracker CLI

A simple C++ terminal-based expense tracking program that allows a user to record expenses, view all expenses, calculate total spending, find the highest expense, and filter expenses by category.

This project was built as part of my C++ learning journey to practice vectors, functions, loops, conditionals, input validation, and menu-based terminal program structure.

## Features

* Add a new expense
* Store expense description
* Store expense category
* Store expense amount
* View all recorded expenses
* Calculate total amount spent
* Find and display the highest expense
* Search expenses by category
* Calculate total spending for a selected category
* Validate expense amount
* Keep running until the user chooses to exit

## Menu Options

```text
1. Add Expense
2. View All Expenses
3. Show Total Spent
4. Show Highest Expense
5. Show Expenses By Category
6. Exit
```

## Expense Format

Each expense contains:

```text
Description
Category
Amount
```

Example:

```text
Description: Lunch
Category: Food
Amount: $650
```

The program stores these values using parallel vectors:

```cpp
vector<string> description;
vector<string> category;
vector<double> amount;
```

The same index across all three vectors represents one expense record.

## Concepts Practiced

This project helped me practice:

* C++ vectors
* `push_back()`
* Vector indexing
* Vector `size()`
* Functions
* Passing vectors by reference
* Loops
* Conditional statements
* Menu-based CLI flow
* Input validation
* Searching/filtering data
* Calculating totals
* Finding the highest value in a list

## How to Compile

Use `g++`:

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o expense
```

## How to Run

```bash
./expense
```

## Sample Output

```text
=======================
    Expense Tracker    
=======================

1. Add Expense
2. View All Expenses
3. Show Total Spent
4. Show Highest Expense
5. Show Expenses By Category
6. Exit

Enter your choice: 1
Enter expense description: Lunch
Enter category: Food
Enter amount: $650

1. Add Expense
2. View All Expenses
3. Show Total Spent
4. Show Highest Expense
5. Show Expenses By Category
6. Exit

Enter your choice: 2
1. Lunch - Food - $650

1. Add Expense
2. View All Expenses
3. Show Total Spent
4. Show Highest Expense
5. Show Expenses By Category
6. Exit

Enter your choice: 3
Total Spent: $650
```

## Validation Rules

* Expense amount cannot be negative
* Amount of `0` is allowed for free items or services
* Menu choice must be between `1` and `6`
* If no expenses exist, the program displays an appropriate message

## Current Limitations

This is version 1, so the program is intentionally simple.

Current limitations:

* Descriptions and categories currently accept one word only
* Expenses are not saved after the program exits
* Money is not formatted to two decimal places
* Categories are matched exactly, so `Food` and `food` are treated differently
* Categories may appear more than once in the available category list

## Future Improvements

Possible improvements for future versions:

* Support full descriptions with spaces
* Format money to two decimal places
* Save expenses to a file
* Load previous expenses when the program starts
* Edit or delete expenses
* Show unique categories only
* Make category search case-insensitive
* Sort expenses by amount
* Add monthly budgets
* Rewrite using structs or classes
* Store all expense data in a single `Expense` object instead of parallel vectors

## Project Status

Version 1 is complete.

This version focuses on learning vector-based storage, basic data filtering, and clean function-based program structure in C++.
