#include <iostream>
#include <stdlib.h>
using namespace std;

// I created an array for the board
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int choice;
int row;
int column;
char turn = 'X';
bool draw = false;

// this is the current status
void display_board()
{
    cout << "Player - 1  [X]\t   Player - 2  [0]\n\n";
    cout << "\t\t       |       |        \n";
    cout << "\t\t   " << board[0][0] << "   |   " << board[0][1] << "   |   " << board[0][2] << "   \n";
    cout << "\t\t_______|_______|________\n";
    cout << "\t\t       |       |        \n";
    cout << "\t\t   " << board[1][0] << "   |   " << board[1][1] << "   |   " << board[1][2] << "   \n";
    cout << "\t\t_______|_______|________\n";
    cout << "\t\t       |       |        \n";
    cout << "\t\t   " << board[2][0] << "   |   " << board[2][1] << "   |   " << board[2][2] << "   \n";
    cout << "\t\t       |       |        \n";
}

// I got the player input and updated the board
void player_turn()
{
    if (turn == 'X')
    {
        cout << "\n\t Player - 1  [X] turn : ";
    }
    else if (turn == '0')
    {
        cout << "\n\t Player - 2  [0] turn : ";
    }

    cin >> choice;
    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout << "Invalid Move";
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != '0')
    {
        // update the position for 'X' symbol
        board[row][column] = 'X';
        turn = '0';
    }

    else if (turn == '0' && board[row][column] != '0' && board[row][column] != 'X')
    {
        board[row][column] = '0';
        turn = 'X';
    }

    else
    {
        cout << "Box already filled!\n\n";
        // choose another board
        player_turn();
    }

    // end of the game
    display_board();
}

// game status
bool gameover()
{
    // I checked if the win is for simple row or for simple column
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return false;
        }

        // I checked the win for the diagonal
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return false;
        }
    }

    // I checked if the game is in continue mode or not
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

    // I checked if the game already draw
    draw = true;
    return false;
}

int main()
{
    cout << "\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t";
    cout << "\n\t\t\t\tFOR 2 PLAYERS\n\t\t\t";
    while (gameover())
    {
        display_board();
        player_turn();
        gameover();
    }

    if (turn == 'X' && draw == false)
    {
        cout << "\n\nCongratulations! Player with 'X' has won the game";
    }

    else if (turn == '0' && draw == false)
    {
        cout << "\n\nCongratulations! Player with '0' has won the game";
    }

    else
    {
        cout << "\n\nGAME DRAW!\n\n";
    }
}
