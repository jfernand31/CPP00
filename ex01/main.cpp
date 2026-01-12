#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

void	add_c(Contact &c)
{
	std::string	tmp;

	std::cout << "First Name: ";
	std::getline(std::cin, tmp);
	c.set_first(tmp);
	std::cout << "Last Name: ";
	std::getline(std::cin, tmp);
	c.set_last(tmp);
	std::cout << "Nickname: ";
	std::getline(std::cin, tmp);
	c.set_nick(tmp);
	std::cout << "Phone Number: ";
	std::getline(std::cin, tmp);
	c.set_number(tmp);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, tmp);
	c.set_secret(tmp);
}

int	main(void)
{
	Contact		c;
	PhoneBook	pb;
	std::string	command;

	while (true)
	{
		std::cout << "Usable commands are ADD, SEARCH, EXIT: ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "EXIT")
			break ;
		if (command == "ADD")
		{
			add_c(c);
			pb.AddContact(c);
		}
		if (command == "SEARCH")
		{
			std::string	tmp;
			pb.ListContact();
			while (true)
			{
				std::cout << "Index to display: ";
				if (!std::getline(std::cin, tmp))
					return (0);
				int		value;
				char	extra;
				std::stringstream	ss(tmp);
				if ((ss >> value) && !(ss >> extra))
				{
					if (value >= 0 && value < pb.GetSize())
					{
						pb.PrintContact(value);
						break;
					}
					else
						std::cout << "Invalid index" << std::endl;
					
				}
				else
				{
					std::cout << "Invalid index" << std::endl;
				}
			}
		}
	}
	return (0);
}
