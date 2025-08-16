#include "g_header.hpp"

PhoneBook::PhoneBook()
{
    this->index = 0;
};
PhoneBook::~PhoneBook(){};

void PhoneBook::setContact(Contact newContact)
{
    static int index;

    if (index > 7)
        index = 0;
    this->list[index] = newContact;
    index++;
}

Contact PhoneBook::getContact(int index)
{
    return this->list[index];
}

void PhoneBook::setIndex()
{
	static int index = 1;
	
    if (index < 9)
        this->index = index++;
}
int PhoneBook::getIndex(){
    return this->index;
}
std::string str_modif(std::string text)
{
    if (text.length() > 9)
    {
        return text.substr(0, 9) + '.';
    }
    else
        return text;
}

void PhoneBook::dispalyPhoneContact()
{
    if (!this->index){
        printColored(UNDERLINE_CYAN, "👤", PADDING);
        printColored(UNDERLINE_CYAN, "Phone Book is Empty", PADDING);
        return ;
    }
    std::cout <<std::string(45, '-') << std::endl;
    std::cout <<  "|   index  |first name| last name| nickname |" <<std::endl;
    std::cout << std::string(45, '-') << std::endl;
    for (int i = 0; i < this->index; i++)
    {
        std::cout << '|' << std::setw(10) << i + 1;
        std::cout << '|' << std::setw(10) << str_modif(this->list[i].getFirstName());
        std::cout << '|' << std::setw(10) << str_modif(this->list[i].getLastName());
        std::cout << '|' << std::setw(10) << str_modif(this->list[i].getNickName());
        std::cout << '|' << std::endl;
        std::cout << std::string(45, '-') << std::endl;
    }
}

bool PhoneBook::displayOneContact(std::string line)
{
    int index;
    
    if (isNumber(line, INDEX))
    {
        printColored(RED, "invalide index", NO_PADDING);
        return false;
    }
    index = atoi(line.c_str());
    if (index < 9 && index > 0)
    {
        index--;
        if (index >= this->index)
        {
            std::cout << index + 1 << " :index doesn't exist" << std::endl;
            return false;
        }
        else
        {
            std::cout << std::string(25, '_') << std::endl;
            printColored(CYAN, "| First name: " + this->list[index].getFirstName(), NO_PADDING);
            printColored(CYAN, "| Last name: " + this->list[index].getLastName(), NO_PADDING);
            printColored(CYAN, "| Nickname: " + this->list[index].getNickName(), NO_PADDING);
            printColored(CYAN, "| Darkest secret: " + this->list[index].getDarkestSecret(), NO_PADDING);
            printColored(CYAN, "| Phone number: " + this->list[index].getPhoneNumber(), NO_PADDING);
            std::cout << std::string(25, '_') << std::endl;
            return true;
            
        }
    }
    else
    {
        std::cout << index << " :out of range" << std::endl;
        return false;
    }
}
