#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Bank{
private:
    string accountHolderName;
    int pin;
    int accountNumber;
    unsigned int accountBalance;

public:
    Bank(string name, int pin, int accNumber) {
        accountHolderName = name;
        this->pin = pin;
        accountNumber = accNumber;
        accountBalance = 0;
    }

    void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Balance: $" << accountBalance << endl;
    }

    bool verifyPin(int enteredPin) {
        return pin == enteredPin;
    }    

    void deposit(unsigned int amount) {
        accountBalance += amount;
        cout << "Amount deposited successfully! New balance: $" << accountBalance << endl;
    }

    bool withdraw(unsigned int amount) {
        if (amount > accountBalance) {
            cout << "Insufficient balance!" << endl;
            return false;
        } else {
            accountBalance -= amount;
            cout << "Amount withdrawn successfully! New balance: $" << accountBalance << endl;
            return true;
        }
    }

    void deleteAccount() {
        accountHolderName = "";
        pin = 0;
        accountBalance = 0;
        cout << "Account deleted successfully!" << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    int getPin() {
        return pin;
    }
};

int findAccount(vector<Bank>& accounts, int accNumber) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNumber) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<Bank> accounts;
    int choice;
    int accNumber;
    int pin;
    string name;
    unsigned int amount;
    int index;

    do {
        cout << "C++ Bank" << endl;
        cout << "1. Create a New Account" << endl;
        cout << "2. Display Account Info" << endl;
        cout << "3. Deposit Funds" << endl;
        cout << "4. Withdraw Funds" << endl;
        cout << "5. Delete Account" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter PIN (4 digits): ";
                cin >> pin;
                accNumber = accounts.size() + 1;
                accounts.push_back(Bank(name, pin, accNumber));
                cout << "Account created successfully! Account Number: " << accNumber << endl;
                break;
            case 2:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                index = findAccount(accounts, accNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for Verification: ";
                    cin >> enteredPin;
                    if (accounts[index].verifyPin(enteredPin)) {
                        accounts[index].displayAccountInfo();
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 3:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                index = findAccount(accounts, accNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for Verification: ";
                    cin >> enteredPin;
                    if (accounts[index].verifyPin(enteredPin)) {
                        cout << "Enter Deposit Amount: $";
                        cin >> amount;
                        accounts[index].deposit(amount);
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 4:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                index = findAccount(accounts, accNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for Verification: ";
                    cin >> enteredPin;
                    if (accounts[index].verifyPin(enteredPin)) {
                        cout << "Enter Withdrawal Amount: $";
                        cin >> amount;
                        if (accounts[index].withdraw(amount)) {
                        }
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 5:
                cout << "Enter Account Number: ";
                cin >> accNumber;
                index = findAccount(accounts, accNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for Verification: ";
                    cin >> enteredPin;
                    if (accounts[index].verifyPin(enteredPin)) {
                        accounts[index].deleteAccount();
                        accounts.erase(accounts.begin() + index);
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 6:
                cout << "Thank you for using C++ Bank. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
