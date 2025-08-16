#ifndef G_HEADER_HPP
#define G_HEADER_HPP

#include <string>
#include <iomanip>
#include <cstdlib>
#include "color.hpp"
#include "PhoneBook.hpp"

enum
{
    INDEX = 3,
    PHONE,
    PADDING,
    NO_PADDING,
    STRING,
};

enum cmd
{
    ADD,
    SEARCH,
    EXIT,
};

int         isNumber(std::string line, int opcode);
void        printColored(std::string color, std::string text, int opcode);
bool        isWhitespace(const std::string str);
std::string catchString(std::string textWantToPrint, PhoneBook *phone, Contact *contact, int opcode);
#endif