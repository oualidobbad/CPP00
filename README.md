# CPP00

C++ Module 00: introduction to classes, encapsulation, and I/O in C++98 — three exercises covering string manipulation, a PhoneBook with an 8-slot circular buffer, and Account class static member reconstruction.

## Project Overview
- What it does: introduces fundamental C++ class design through three progressive exercises.
- Use cases: learning C++ class basics, encapsulation, `static` members, formatted I/O with `<iomanip>`.

## Architecture & Design
- **ex00 (Megaphone)**: simple `main()` that uppercases all argv strings — intro to C++ string handling.
- **ex01 (PhoneBook)**: CLI phonebook with `Contact` and `PhoneBook` classes.
  - `PhoneBook`: 8-slot fixed array with circular index; `ADD`/`SEARCH`/`EXIT` commands.
  - `Contact`: stores 5 fields (first name, last name, nickname, phone, secret).
  - Display: `std::setw(10)` formatted table with truncation at 10 chars.
- **ex02 (Account)**: reconstruct `Account.cpp` from `Account.hpp` and test output — `static` member accounting (total accounts, deposits, withdrawals).

## Core Concepts (with code)
- PhoneBook circular buffer and formatted display:
```cpp
// PhoneBook.hpp
class PhoneBook {
    private:
        Contact list[8];
        int index;  // wraps at 8 for circular behavior
    public:
        void setContact(Contact newContact);
        void dispalyPhoneContact();  // formatted table output
        bool displayOneContact(std::string line);
};
```
- Account static tracking:
```cpp
// Account.hpp — static members track totals across all instances
static int _nbAccounts;
static int _totalAmount;
static int _totalNbDeposits;
static int _totalNbWithdrawals;
```

## Code Walkthrough
1) ex00: iterate argv, toupper each char, print. Minimal C++ entry point.
2) ex01: main loop reads commands; `ADD` fills contacts cyclically; `SEARCH` displays a formatted table with `std::setw(10)` and `std::right`, then shows full details for a selected index.
3) ex02: match `Account.cpp` implementation to reproduce the exact log output from `tests.cpp`.

## Installation & Setup
- Build per exercise: `cd ex00 && make` (compiled with `-Wall -Wextra -Werror -std=c++98`).

## Usage Guide
```bash
./megaphone "hello world"    # HELLO WORLD
./phonebook                   # interactive CLI
```

## Technical Deep Dive
- C++98 constraint: no `auto`, no range-for, no `std::string::stoi`.
- PhoneBook index wraps via modulo for circular replacement of oldest entries.
- Account uses timestamped logging with `static` display methods.

## Improvements & Future Work
- Add input validation for phone numbers (digits only).
- Add file persistence for the PhoneBook.

## Author
Oualid Obbad (@oualidobbad)