#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	void	AddContact(const Contact &Contact);
	void	PrintContact(int index) const;
	bool	ListContact() const;
	int		GetSize(void) const;
	
private:
	Contact	contact[8];
	int		count;
	int		size;
};

#endif
