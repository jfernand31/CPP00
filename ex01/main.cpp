#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

static bool	is_valid(const std::string tmp)
{
	for (size_t i = 0; i < tmp.size(); ++i)
	{
		unsigned char c = tmp[i];
		if(!std::isspace(c))
			return (true);
	}
	return (false);
}

static void	prompt(int p)
{
	if(p == 1)
		std::cout << "First Name: ";
	if(p == 2)
		std::cout << "Last Name: ";
	if (p == 3)
		std::cout << "Nickname: ";
	if (p == 4)
		std::cout << "Phone Number: ";
	if (p == 5)
		std::cout << "Darkest Secret: ";
}

static void	set_parameter(Contact &c, std::string tmp, int i)
{
	if (i == 1)
		c.set_first(tmp);
	else if(i == 2)
		c.set_last(tmp);
	else if(i == 3)
		c.set_nick(tmp);
	else if(i == 4)
		c.set_number(tmp);
	else if(i == 5)
		c.set_secret(tmp);
}

void	add_c(Contact &c)
{
	std::string	tmp;
	int			i = 1;

	while (i < 6)
	{
		prompt(i);
		std::getline(std::cin, tmp);
		if (is_valid(tmp))
		{
			set_parameter(c, tmp, i);
			i++;
		}
		else
			continue ;
	}
}

int	main(void)
{
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
			Contact	c;
			add_c(c);
			pb.AddContact(c);
		}
		if (command == "SEARCH")
		{
			std::string	tmp;
			if (pb.ListContact())
			{	
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
	}
	return (0);
}
