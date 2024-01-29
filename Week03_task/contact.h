#pragma once
# include <string>
class Contact {
private:
	std::string street_address;
	std::string city;
	std::string state;
	std::string zip_code;
	std::string phone_number;
public:
	Contact() : street_address(""), city(""), state(""), zip_code(""), phone_number("") {};
	void initialize();
	void display() const;
};