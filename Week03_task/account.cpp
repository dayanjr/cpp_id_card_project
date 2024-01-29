#include "account.h"
#include "contact.h"
#include <iostream>
#include <iomanip>

int Account::next_id = 1;

//constructor
Account::Account() : id(0), balance(0), contact(nullptr){}

//prompt user for name and balance
void Account::initialize()
{
	id = next_id++;

	std::cout << "Enter the name: ";
	std::getline(std::cin, name);

	std::string input;
	std::cout << "Enter the balance: ";
	std::getline(std::cin, input);
	balance = std::stof(input);
}
void Contact::initialize() {
std::cout << "Enter street address: ";
std::getline(std::cin, street_address);
std::cout << "Enter city name: ";
std::getline(std::cin, city);
std::cout << "Enter state name: ";
std::getline(std::cin, state);
std::cout << "Enter zip_code: ";
std::getline(std::cin, zip_code);
std::cout << "Enter phone_number: ";
std::getline(std::cin, phone_number);
}
void Contact::display() const {
	std::cout << "street address:" << street_address << std::endl
		<< "city: " << city << std::endl
		<< "state: " << state << std::endl
		<< "zip_code: " << zip_code << std::endl
		<< "phone_number: " << phone_number << std::endl;
}
void Account::display() const {
	std::cout << "Account ID: " << id
		<< "\nName: " << name
		<< "\nBalance: $" << std::fixed << std::setprecision(2) << balance
		<< std::endl;
	if (contact != nullptr) {
		contact->display();
	}
}
void Account::deposit(float amount) {
	balance += amount;
}
void Account::withdraw(float amount) {
	balance -= amount;
}
int Account::get_id() const {
	return id;
}
int Account::get_balance() {
	return balance;
}
void Account::update_balance(float new_balance)
{
		balance = new_balance;
}
void Account::add_contact_info() {
	contact = std::make_shared<Contact>();
	contact->initialize();
}
//Optional display
//std::ostream& Account::display(std::ostream& out) const {
//	out << "Account ID: " << id
//		<< "Name:" << name
//		<< "Balance $" << std::fixed << std::setprecision(2) << balance
//		<< std::endl;
//	return out;
//}
//account& Account::operator+= (float deposit) {
//	balance += deposit;
//	return *this;
//}
//account& Account::operator-= (float withdrawal) {
//	balance -= deposit;
//	return *this;
//}
//std::ostream& operator<<(std::ostream& out, const Account& account) {
//	return account.display(out);
//}