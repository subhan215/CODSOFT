#include <iostream>
#include <cstdlib>
#include <string>
void checkNumber(std::string *s)
{
    bool check = true;
    bool dotCheck = false ;  
    while (1)
    {
        for (char c : *s)
        {
            if (!isdigit(c))
            {
                if(!dotCheck && c == '.') {
                    dotCheck = true ; 
                    continue ; 
                }
                check = false;
                break;
            }
        }
        if (check == false)
        {
            std::cout << "\nInvaid Input!\nEnter again: ";
            fflush(stdin);
            std::cin >> (*s);
            check = true;
            dotCheck = false ; 
            continue;
        }
        else
        {
            break;
        }
    }
}
int main()
{
    int choice;
    while (choice != 5)
    {
        double num1, num2, result;
        std::string num1Str, num2Str, choiceStr;
        std::cout << "\nWelome to Rangila's Basic Mathematic Calculator!!";
        std::cout << "\nWhat you want to perform: \n1:Addition\n2:Subtraction\n3:Multiplication";
        std::cout << "\n4:Division\n5:Exit\nEnter your choice: ";
        while (1)
        {
            std::cin >> choiceStr;
            checkNumber(&choiceStr);
            choice = std::stoi(choiceStr);
            if (choice < 1 || choice > 5)
            {
                std::cout << "\nInvalid Number!\nEnter again: ";
            }
            else
            {
                break;
            }
        }
        std::cout << "\nEnter number 1 : ";
        std::cin >> num1Str;
        checkNumber(&num1Str);
        num1 = std::stof(num1Str);
        std::cout << "\nEnter number 2: ";
        std::cin >> num2Str;
        checkNumber(&num2Str);
        num2 = std::stof(num2Str);
        if (choice == 1)
        {
            result = num1 + num2;
        }
        else if (choice == 2)
        {
            result = num1 - num2;
        }
        else if (choice == 3)
        {
            result = num1 * num2;
        }
        else if (choice == 4)
        {
            result = num1 / num2;
        }
        else
        {
            exit(1);
        }
        std::cout << "\nResult: " << result;
    }
}