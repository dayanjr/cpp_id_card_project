#include <iostream>
#include <limits>
#include <ios>
#include "account.h"
#include <list>
#include <string>
#include <algorithm>
#include <numeric>


using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::list;
using std::string;

void display_menu();
list<Account>::iterator find_account(list<Account>& accounts);

int main() {
	list<Account> accounts;
	//Account account;
	//account.initialize();
	//
	//account.display();

	int choice = 1;
	while (choice) {
		display_menu();
		cin >> choice;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (choice) {
		case 0:
			break;
		case 1:
			for_each(accounts.begin(), accounts.end(),
				[](auto& account) {
					account.display();
				});
			break;
		case 2: {
			//float deposit_amount = 0;
			//cout << "Amount to deposit: ";
			//cin >> deposit_amount;
			//account.deposit(deposit_amount);
			list<Account>::iterator it = find_account(accounts);
			if (it == accounts.end())
				cout << "Account not found\n";
			else {
				it->display();
				string input;
				float deposit_amount = 0;
				cout << "Amount to deposit: ";
				getline(cin, input);
				deposit_amount = std::stof(input);
				it->deposit(deposit_amount);
			}
			break;
		}
		case 3: {
			//float deposit_amount = 0;
			//cout << "Amount to deposit: ";
			//cin >> deposit_amount;
			//account.deposit(deposit_amount);
			list<Account>::iterator it = find_account(accounts);
			if (it == accounts.end())
				cout << "Account not found\n";
			else {
				it->display();
				string input;
				float withdrawal_amount = 0;
				cout << "Amount to deposit: ";
				getline(cin, input);
				withdrawal_amount = std::stof(input);
				it->withdraw(withdrawal_amount);
			}
			break;
		}
		case 4:
		{
			Account account;
			account.initialize();
			accounts.push_back(account);
			cout << "Added account";
			break;
		}
		case 5: {
			list<Account>::iterator it = find_account(accounts);
			if (it != accounts.end())
				it->display();
			else
				cout << "Account not found\n";
			break;
		}case 6: {
			string input;
			cout << "Enter the ID of the account to remove: ";
			getline(cin, input);
			int id = std::stoi(input);
			auto new_end = remove_if(accounts.begin(), accounts.end(),
				[id](auto& account) {
					return account.get_id() == id;
				});
			accounts.erase(new_end, accounts.end());
			break;
		}case 7: {
			float total = accumulate(accounts.begin(), accounts.end(), 0.0f,
				[](auto accumlator, auto& account) {
					return accumlator + account.get_balance();
				});
			cout << "Total: " << total << endl;
			break;
		}case 8: {
			string input;
			float deposit_amount = 0;
			cout << "Enter the dividend as a percentage: ";
			getline(cin, input);
			deposit_amount = std::stof(input);
			float increment_by = deposit_amount / 100;
			transform(accounts.begin(), accounts.end(), accounts.begin(),
				[increment_by](auto& account) {
					account.update_balance(account.get_balance() + account.get_balance() * increment_by);
					return account;
				});
			break;
		}case 9: {
			list<Account>::iterator it = find_account(accounts);
			if (it == accounts.end())
				cout << "Account not found\n";
			else {
				it->display();
				it->add_contact_info();
				it->display();
			}
			break;
		}
		default:
			cout << "That is not a valid menu option, try again: ";
			continue;
		}
		
	}
	cout << "Goodbye." << endl;
	return 0;
}
void display_menu() {
	std::cout << "\nAccount Menu: \n"
		<< "0. Quit Program\n"
		<< "1. Display Account Information\n"
		<< "2. Add a deposit to an account\n"
		<< "3. Withdraw from an account\n"
		<< "4. Add new account\n"
		<< "5. Find account\n"
		<< "6. remove account\n"
		<< "7. Show total balance for all accounts\n"
		<< "8. Add a dividend to all accounts\n"
		<< "9. Add contact information to an account\n"
		<< "Your choice : ";
}
list<Account>::iterator find_account(list<Account>& accounts) {
	string input;
	cout << "Enter the ID of the account to find: ";
	getline(cin, input);
	int id = std::stoi(input);
	list<Account>::iterator it;
	for (it = accounts.begin(); it != accounts.end(); it++) {
		if (it->get_id() == id) {
			return it;
		}
	}
	return it;
}