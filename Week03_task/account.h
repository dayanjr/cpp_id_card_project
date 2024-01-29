#pragma once
#include "contact.h"
#include <string>
#include <iostream>
#include <memory>

class Account {
private:
	int id;
	std::string name;
	float balance;
	static int next_id; // static integer to keep track of the next account number
	std::shared_ptr<Contact> contact;
public:
	Account(); //Constructor
	void initialize(); // Prompt user for name and balance
	void display() const;
	void deposit(float amount);
	void withdraw(float amount);
	int get_id() const;
	int get_balance();
	void update_balance(float new_balance);
	void add_contact_info();

	// Optional parts of task
	//std::ostream& display(std::ostream& out) const;
	//Account& operator+= (float deposit);
	//Account& operator-=(float withdrawal);
};
//std::ostream& operator<<(std::ostream& out, const Account& account);