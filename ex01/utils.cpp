#include "g_header.hpp"

void printColored(std::string color, std::string text, int opcode)
{
    int padding = (35 - text.length()) / 2;
    if (padding > 0 && opcode == PADDING)
    {
        std::cout << std::string(padding, ' ') << color << text << RESET << std::endl;
    }
    else
    {
        std::cout << color << text << RESET << std::endl;
    }
}

int isNumber(std::string line, int opcode)
{
    if (line[0] == '-' || line[0] == '+' || std::isdigit(line[0]))
    {
        if (line[0] == '-' && opcode == PHONE)
            return 1;
        goto loop;
    }
    else
        return (1);

loop:
    for (int i = 1; line[i]; i++)
    {
        if (!std::isdigit(line[i])){
            
            return 1;
        }
    }
    return 0;
}

bool isWhitespace(const std::string str) 
{
    int i;

    i = 0;
    while (str[i] && std::isspace(str[i]))
        i++;
    if (str[i])
        return true;
    else
        return false;
}

std::string catchString(std::string textWantToPrint, PhoneBook *phone, Contact *contact, int opcode)
{
    std::string line;

start:
    std::cout << textWantToPrint;
    if (!std::getline(std::cin, line))
    {
		line.~basic_string();
		contact->~Contact();
        phone->~PhoneBook();
        exit(1);
    }
    if (opcode == STRING)
    {
        if (line.empty() || !isWhitespace(line))
        {
            printColored(RED, "string is empty", PADDING);
            goto start;
        }
    }
    else
    {
        if (isNumber(line, opcode))
        {
            printColored(RED, "invalid phone number", PADDING);
            goto start;
        }
    }
    return line;
}