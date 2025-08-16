#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact list[8];
        int index;
    public:
        PhoneBook();
        ~PhoneBook();
        void    setIndex();
        void    setContact(Contact newContact);
        int     getIndex();
        Contact getContact(int index);
        void    dispalyPhoneContact();
        bool    displayOneContact(std::string line);
};

#endif