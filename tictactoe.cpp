#include<iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char currentPlayer = 'X';

void displayBoard()
{
    cout << "\n";

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << " " << board[i][j] << " ";

            if(j<2)
                cout << "|";
        }

        cout << "\n";

        if(i<2)
            cout << "---|---|---\n";
    }

    cout << "\n";
}

bool placeMark(int choice)
{
    int row = (choice-1)/3;
    int col = (choice-1)%3;

    if(board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

bool checkWin()
{
    // Rows
    for(int i=0;i<3;i++)
    {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for(int i=0;i<3;i++)
    {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return true;
    }

    // Diagonals
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

void switchPlayer()
{
    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main()
{
    int choice;
    int moves = 0;

    while(true)
    {
        displayBoard();

        cout << "Player " << currentPlayer;
        cout << ", enter position (1-9): ";
        cin >> choice;

        if(choice < 1 || choice > 9)
        {
            cout << "Invalid Choice!\n";
            continue;
        }

        if(!placeMark(choice))
        {
            cout << "Position already taken!\n";
            continue;
        }

        moves++;

        if(checkWin())
        {
            displayBoard();
            cout << "Player " << currentPlayer << " Wins!\n";
            break;
        }

        if(moves == 9)
        {
            displayBoard();
            cout << "Match Draw!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}