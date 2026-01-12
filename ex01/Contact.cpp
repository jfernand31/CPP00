#include "Contact.hpp"

Contact::Contact()
	: fname(""), lname(""), nick(""), number(""), secret("") {}

void	Contact::set_first(const std::string &s)
{
	this->fname = s;
}

void	Contact::set_last(const std::string &s)
{
	this->lname = s;
}

void	Contact::set_nick(const std::string &s)
{
	this->nick = s;
}

void	Contact::set_number(const std::string &s)
{
	this->number = s;
}

void	Contact::set_secret(const std::string &s)
{
	this->secret = s;
}

std::string	Contact::get_first() const
{
	return (this->fname);
}
std::string	Contact::get_last() const
{
	return (this->lname);
}

std::string	Contact::get_nick() const
{
	return (this->nick);
}

std::string	Contact::get_number() const
{
	return (this->number);
}
std::string	Contact::get_secret() const
{
	return (this->secret);
}

