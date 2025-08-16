#include "g_header.hpp"

Contact::Contact() {};
Contact::~Contact() {};
void Contact::setFirstName(std::string line)
{
    this->firstName = line;
}

void Contact::setLastName(std::string line)
{
    this->lastName = line;
}

void Contact::setNickName(std::string line)
{
    this->nickName = line;
}

void Contact::setDarkestSecret(std::string line)
{
    this->darkestSecret = line;
}

void Contact::setPhoneNumber(std::string line)
{
    this->phoneNumber = line;
}

std::string Contact::getFirstName()
{
    return this->firstName;
}
std::string Contact::getLastName()
{
    return this->lastName;
}
std::string Contact::getNickName()
{
    return this->nickName;
}
std::string Contact::getDarkestSecret()
{
    return this->darkestSecret;
}
std::string Contact::getPhoneNumber()
{
    return this->phoneNumber;
}