#include <iostream>
#include <string>
#include <vector>
using namespace std;

void showMenu() {
    cout << "1. Add Expense" << '\n' << "2. View All Expenses" << '\n' << "3. Show Total Spent" << '\n' << "4. Show Highest Expense" << '\n' << "5. Show Expenses By Category" << '\n' << "6. Exit" << '\n' << '\n';
}

void addExpense(vector<string>& description, vector<string>& category, vector<double>& amount) {
    string desc;
    string cat;
    double amt;

    cout << "Enter expense description: ";
    cin >> desc;
    description.push_back(desc);

    cout << "Enter category: ";
    cin >> cat;
    category.push_back(cat);

    cout << "Enter amount: $";
    cin >> amt;
    while(amt < 0) {
        cout << "Invalid amount. Please enter an amount above or equal to $0: $";
        cin >> amt;
    }
    amount.push_back(amt);
}

void displayExpenses(vector<string> description, vector<string> category, vector<double> amount) {
    if (amount.size() == 0) {
        cout << "No expenses recorded yet." << '\n';
    } else {
        for (int i = 0; i < amount.size(); i++) {
            cout << i << ". " << description[i] << " - " << category[i] << " - $" << amount[i] << '\n';
        }
    }
}

void totalSpent(vector<double> amount) {
    int amt = 0;
    for(int i = 0; i < amount.size(); i++) {
        amt += amount[i];
    }

    cout << "Total Spent: $" << amt << '\n';
}

int getHighestExpenseIndex(vector<double> amount) {
    if (amount.size() == 0) {
        cout << "No expenses recorded yet." << '\n';
        return -1;
    } else {
        int currentAmount = amount[0];
        int index = 0;

        for (int i = 1; i < amount.size(); i++) {
            if (amount[i] > currentAmount) {
                currentAmount = amount[i];
                index = i;
            }
        }

        return index;
    }
}

void getExpensesByCategory(vector<string> description, vector<string> category, vector<double> amount) {
    if (category.size() == 0) {
        cout << "No categories found." << '\n';
    } else {
        string cat;
        vector<int> catIndex;
        int totalAmount = 0;
        cout << "Here are the available categories:" << '\n';

        for (int i = 0; i < category.size(); i++) {
            cout << category[i] << ", ";
        }

        cout << '\n' << '\n' << "Enter category to search: ";
        cin >> cat;
        cout << '\n';

        for (int i = 0; i < category.size(); i++) {
            if (cat == category[i]) {
                catIndex.push_back(i);
            }
        }

        if (catIndex.size() == 0) {
            cout << "Category not found." << '\n';
        } else {
            for (int i = 0; i < catIndex.size(); i++) {
                cout << i << ". " << description[catIndex[i]] << " - $" << amount[catIndex[i]] << '\n';
                totalAmount += amount[catIndex[i]];
            }

            cout << '\n' << "Total for " << cat << ": $" << totalAmount << '\n';
        }
    }
}

int getChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice <= 0 || choice > 6) {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
    }

    return choice;
}

int main() {

    vector<string> description;
    vector<string> category;
    vector<double> amount;
    int index;

    cout << "=======================" << '\n' << "    Expense Tracker    " << '\n' << "=======================" << '\n' << '\n';

    showMenu();
    int choice = getChoice();

    while (choice != 6) {
        switch (choice) {
            case 1:
                addExpense(description, category, amount);
                break;
            case 2:
                displayExpenses(description, category, amount);
                break;
            case 3:
                totalSpent(amount);
                break;
            case 4:
                index = getHighestExpenseIndex(amount);
                if (index == -1) break;
                cout << "Highest Expense:" << '\n';
                cout << "Description: " << description[index] << '\n' <<  "Category: " << category[index] << '\n' << "Amount: $" << amount[index] << '\n';
                break;
            case 5:
                getExpensesByCategory(description, category, amount);
                break;
        }
        cout << '\n';
        showMenu();
        choice = getChoice();
    }

    cout << "Thank you for using Expense Tracker!" << '\n';

    return 0;
}