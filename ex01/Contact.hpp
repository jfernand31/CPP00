#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
public:
	Contact();
	void		set_first(const std::string &s);
	void		set_last(const std::string &s);
	void		set_nick(const std::string &s);
	void		set_number(const std::string &s);
	void		set_secret(const std::string &s);
	std::string	get_first() const;
	std::string	get_last() const;
	std::string	get_nick() const;
	std::string	get_number() const;
	std::string	get_secret() const;

private:
	std::string	fname;
	std::string	lname;
	std::string	nick;
	std::string	number;
	std::string	secret;
};

#endif
