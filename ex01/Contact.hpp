#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string darkestSecret;
        std::string phoneNumber;
    public:
        Contact();
        void setFirstName(std::string line);
        void setLastName(std::string line);
        void setNickName(std::string line);
        void setDarkestSecret(std::string line);
        void setPhoneNumber(std::string line);
        
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getDarkestSecret();
        std::string getPhoneNumber();
        ~Contact();
};

#endif