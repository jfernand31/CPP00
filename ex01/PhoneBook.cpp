#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

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

bool	PhoneBook::ListContact() const
{
	if (count == 0)
	{
		std::cout << "No contacts available.\n";
		return (false);
	}
	int oldest_index;

	if(count < 8)
		oldest_index = 0;
	else
		oldest_index = count % 8;
	std::cout << std::setw(10) << "Index" << " | "
		<< std::setw(10) << "First Name" << " | "
		<< std::setw(10) << "Last Name" << " | "
		<< std::setw(10) << "Nickname" << std::endl;
	for(int i = 0; i < size; i++)
	{
		int index = (oldest_index + i) % 8;

	 std::cout << std::setw(10) << i << " | "
			<< std::setw(10) << truncate_s(contact[index].get_first()) << " | "
			<< std::setw(10) << truncate_s(contact[index].get_last()) << " | "
			<< std::setw(10) << truncate_s(contact[index].get_nick()) << std::endl;
	}
	return (true);
}
