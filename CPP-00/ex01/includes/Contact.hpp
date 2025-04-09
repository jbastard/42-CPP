
#ifndef CONTACT_H
#define CONTACT_H

class Contact {
private:
	std::string	_name;
	std::string	_nickname;
	int			_phoneNumber;
	std::string	_darkestSecret;
public:
	Contact();
	Contact(const Contact&);
	~Contact();
};

#endif
