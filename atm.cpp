#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Bank {
private:
	string name;
	long long acc;
	long long amount = 0;
	long long total = 0;
public:
	void setvalue()
	{
		cout << "Enter name\n";
		getline(cin, name);

		cout << "Enter Account number\n";
		cin >> acc;
		cout << "Enter Balance\n";
		cin >> total;
	}
	void display()
	{
		cout << "Name:" << name << endl;
		cout << "Account No:" << acc << endl;
		cout << "Balance:" << total << endl;
	}

	void deposit()
	{
		cout << "\nEnter amount to be Deposited\n";
		cin >> amount;
	}
	void showbal()
	{
		total = total + amount;
		cout << "\nTotal balance is: " << total;
	}

	void withdrawl()
	{
		int i, available;
		cout << "Enter amount to withdraw\n";
		cin >> i;
		available = total - i;
		cout << "Available Balance is" << available;
	}
};

int main()
{
	Bank b;

	int choice;
	while (1) {
		cout << "\nEnter Your Choice\n";
		cout << "\t1. Enter name, Account "
			<< "number, Account \n";
		cout << "\t2. Balance Enquiry\n";
		cout << "\t3. Deposit Money\n";
		cout << "\t4. Withdraw Money\n";
		cout << "\t5. Show Total balance\n";
		cout << "\t6. Cancel\n";
		cin >> choice;

		// Choices to select from
		switch (choice) {
		case 1:
			b.setvalue();
			break;
		case 2:
			b.display();
			break;
		case 3:
			b.deposit();
			break;
		case 4:
			b.withdrawl();
			break;
		case 5:
			b.showbal();
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "\nInvalid choice\n";
		}
	}
}
