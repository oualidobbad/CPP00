%:include "g_header.hpp"

cmd displayPrompt(PhoneBook *phone)
{
    std::string line;

start:
    std::cout << std::endl;
    printColored(YELLOW, "what do you want ...", PADDING);
    printColored(BOLD_BLUE, "ADD", PADDING);
    printColored(BOLD_GREEN, "SEARCH", PADDING);
    printColored(BOLD_MAGENTA, "EXIT", PADDING);
    std::cout << "    > ";
    if (!std::getline(std::cin, line))
    {
        phone->~PhoneBook();
        exit(0);
    }
    if (line == "SEARCH")
        return SEARCH;
    else if (line == "ADD")
        return ADD;
    else if (line == "EXIT")
        return EXIT;
    else
    {
        printColored(RED, line + " :commande Not Found please enter right commnad", NO_PADDING);
        goto start;
    }
}

void creatContact(PhoneBook *phone)
{
    Contact contact;

    contact.setFirstName(catchString("First name: ", phone, &contact, STRING));
    contact.setLastName(catchString("Last name: ", phone, &contact, STRING));
    contact.setNickName(catchString("Nickname: ", phone, &contact, STRING));
    contact.setDarkestSecret(catchString("DarkestSecret: ", phone, &contact, STRING));
    contact.setPhoneNumber(catchString("Phone number: ", phone, &contact, PHONE));
    phone->setContact(contact);
    phone->setIndex();
}

void searchInContact(PhoneBook *phone)
{
    std::string line;

    phone->dispalyPhoneContact();
    if (!phone->getIndex())
        return;
start:
    std::cout << YELLOW << "what index contact you want> " << RESET;
    if (!getline(std::cin, line))
    {
		line.~basic_string();
        phone->~PhoneBook();
        exit(1);
    }
    if (!phone->displayOneContact(line))
        goto start;
}

int main()
{
    cmd command;
    PhoneBook phone;

    while (true)
    {
        command = displayPrompt(&phone);
        switch (command)
        {
        case ADD:
            creatContact(&phone);
            break;
        case SEARCH:
            searchInContact(&phone);
            break;
        case EXIT:
            phone.~PhoneBook();
            exit(0);
        }
    }
    return (0);
}
