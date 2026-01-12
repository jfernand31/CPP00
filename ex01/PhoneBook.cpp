#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() : count(0), size(0)
{

}

std::string	truncate_s(std::string s)
{
	if (s.length() > 10)
		s = s.substr(0, 9) + ".";
	return (s);
}

void	PhoneBook::AddContact(const Contact &Contact)
{
	int index = count % 8;
	contact[index] = Contact;
	count++;

	if (size < 8)
		size++;
}

int	PhoneBook::GetSize(void) const
{
	return (size);
}

void	PhoneBook::PrintContact(int index) const
{
	std::cout << "First Name: " << contact[index].get_first() << std::endl;
	std::cout << "Last Name: " << contact[index].get_last() << std::endl;

	std::cout << "Nickname: " << contact[index].get_nick() << std::endl;
	std::cout << "Phone Number: " << contact[index].get_number() << std::endl;
	std::cout << "Darkest Secret: " << contact[index].get_secret() << std::endl;
}

void	PhoneBook::ListContact() const
{
	for(int i = 0; i < count && i < size; i++)
	{
	 std::cout << std::setw(10) << i << " | "
			<< std::setw(10) << truncate_s(contact[i].get_first()) << " | "
			<< std::setw(10) << truncate_s(contact[i].get_last()) << " | "
			<< std::setw(10) << truncate_s(contact[i].get_nick()) << std::endl;
	}
}
