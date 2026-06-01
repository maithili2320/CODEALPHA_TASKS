#include <iostream>
#include <vector>

using namespace std;

// Transaction Class
class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }

    void showTransaction() {
        cout << type << ": Rs. " << amount << endl;
    }
};

// Account Class
class Account {
private:
    int accountNumber;
    string customerName;
    double balance;
    vector<Transaction> transactions;

public:
    // Constructor
    Account(int accNo, string name, double bal) {
        accountNumber = accNo;
        customerName = name;
        balance = bal;
    }

    // Deposit Function
    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));

        cout << "Amount Deposited Successfully!\n";
    }

    // Withdraw Function
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            transactions.push_back(Transaction("Withdrawal", amount));

            cout << "Withdrawal Successful!\n";
        }
    }

    // Transfer Function
    void transfer(Account &receiver, double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            receiver.balance += amount;

            transactions.push_back(Transaction("Transfer Sent", amount));
            receiver.transactions.push_back(Transaction("Transfer Received", amount));

            cout << "Transfer Successful!\n";
        }
    }

    // Display Account Details
    void showAccountDetails() {
        cout << "\n===== Account Details =====\n";

        cout << "Account Number: " << accountNumber << endl;
        cout << "Customer Name : " << customerName << endl;
        cout << "Balance       : Rs. " << balance << endl;
    }

    // Display Transaction History
    void showTransactions() {
        cout << "\n===== Transaction History =====\n";

        for (int i = 0; i < transactions.size(); i++) {
            transactions[i].showTransaction();
        }
    }
};

// Main Function
int main() {

    // Create two accounts
    Account user1(1001, "Rahul", 5000);
    Account user2(1002, "Priya", 3000);

    int choice;
    double amount;

    do {
        cout << "\n====== BANKING SYSTEM ======\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer Money\n";
        cout << "4. Show Account Details\n";
        cout << "5. Show Transaction History\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;

            user1.deposit(amount);
            break;

        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            user1.withdraw(amount);
            break;

        case 3:
            cout << "Enter amount to transfer: ";
            cin >> amount;

            user1.transfer(user2, amount);
            break;

        case 4:
            user1.showAccountDetails();
            break;

        case 5:
            user1.showTransactions();
            break;

        case 6:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}

