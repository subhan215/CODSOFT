#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <conio.h>
void checkNumber(std::string *s)
{
    bool check = true;
    while (1)
    {
        for (char c : *s)
        {
            if (!isdigit(c))
            {
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
    srand(time(0)) ; 
    int numToGuess = rand() % 101;
    std::string guessNumStr ; 
    int guessNum ; 
    std::cout << "\nGuess a number between 0 to 100";
    while (guessNum != numToGuess)
    {
        std::cout << "\nEnter number: ";
        std::cin >> guessNumStr;
        checkNumber(&guessNumStr) ; 
        guessNum = std::stoi(guessNumStr) ; 
        if (numToGuess == guessNum)
        {
            std::cout << "\nCongratulations! You have guessed the correct number!!!...";
            std::cout <<"\nPress any key to exit!" ; 
            getch() ; 
            break;
        }
        if (guessNum > numToGuess)
        {
            std::cout << "\nYour guessed number is too high from the correct number!!";
        }
        else
        {
            std::cout << "\nYour guessed number is too low from the correct number!!";
        }
    }
}