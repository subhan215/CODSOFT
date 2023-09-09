#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
bool draw = false;
char turn = 'X';
int choice;
int row, column;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
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
void showBoard()
{
    system("cls");
    std::cout << "T I C K -- T A C -- T O E -- G A M E\t\t";
    std::cout << "\n\tFOR 2 PLAYERS\n\t";
    std::cout << "PLAYER - 1 [X] PLAYER - 2 [0]\n";
    std::cout << "\t     |     |     \n";
    std::cout << "\t  " << board[0][0] << "  | " << board[0][1] << "   |  " << board[0][2] << " \n";
    std::cout << "\t_____|_____|_____\n";
    std::cout << "\t     |     |     \n";
    std::cout << "\t  " << board[1][0] << "  | " << board[1][1] << "   |  " << board[1][2] << " \n";
    std::cout << "\t_____|_____|_____\n";
    std::cout << "\t     |     |     \n";
    std::cout << "\t  " << board[2][0] << "  | " << board[2][1] << "   |  " << board[2][2] << " \n";
    std::cout << "\t     |     |     \n";
}
void playerTurn()
{

    while (1)
    {
        if (turn == 'X')
        {
            std::cout << "\nPlayer 1(X) Turn:";
        }
        else
        {
            std::cout << "\nPlayer 2(0) Turn: ";
        }
        std::string choiceStr;
        fflush(stdin);
        std::cin >> choiceStr;
        checkNumber(&choiceStr);
        choice = std::stoi(choiceStr);
        switch (choice)
        {
        case 1:
            row = 0, column = 0;
            break;
        case 2:
            row = 0, column = 1;
            break;
        case 3:
            row = 0, column = 2;
            break;
        case 4:
            row = 1, column = 0;
            break;
        case 5:
            row = 1, column = 1;
            break;
        case 6:
            row = 1, column = 2;
            break;
        case 7:
            row = 2, column = 0;
            break;
        case 8:
            row = 2, column = 1;
            break;
        case 9:
            row = 2, column = 2;
            break;
        default:
            std::cout << "\nInvalid Move!";
            continue;
        }
        break;
    }
    if (turn == 'X' && board[row][column] != '0' && board[row][column] != 'X')
    {
        turn = '0';
        board[row][column] = 'X';
    }
    else if (turn == '0' && board[row][column] != '0' && board[row][column] != 'X')
    {
        turn = 'X';
        board[row][column] = '0';
    }
    else
    {
        std::cout << "\nAlready filled! \nPlease choose another one!";
        playerTurn();
    }
}
bool game()
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][0] == board[i][2]) || (board[1][i] == board[0][i] && board[1][i] == board[2][i]))
        {
            return false;
        }
    }
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
    {
        return false;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != '0')
            {
                return true;
            }
        }
    }
    draw = true;
    return false;
}
int main()
{

    std::cout << "\nWhich player will have the first turn: ";
    while (1)
    {
        fflush(stdin);
        std::cin >> turn;
        if (turn == 'X' || turn == '0')
        {
            break;
        }
        std::cout << "\nInvalid!\nEnter again: ";
    }

    while (game())
    {
        showBoard();
        playerTurn();
        game();
    }
    showBoard() ; 
    if (turn == '0' && draw == false)
    {
        std::cout << "\nCongratulations!Player with 'X' has won the game";
    }
    else if (turn == 'X' && draw == false)
    {
        std::cout << "\nCongratulations!Player with '0' has won the game..";
    }
    else
    {
        std::cout << "\nGAME DRAW!!!\n";
    }
    getch() ; 
}
