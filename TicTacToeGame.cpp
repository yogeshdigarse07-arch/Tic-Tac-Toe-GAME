#include <iostream>
using namespace std;

char box[3][3];

void resetBoard()
{

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            box[i][j] = '-';
           
        }
    }
}

void displayBoard()
{
    cout << "\n";
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << " " << box[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool checkWinner(char ch)
{
    for(int i = 0; i < 3; i++)
    {
        if(box[i][0] == ch && box[i][1] == ch && box[i][2] == ch)
            return true;

        if(box[0][i] == ch && box[1][i] == ch && box[2][i] == ch)
            return true;
    }

    if(box[0][0] == ch && box[1][1] == ch && box[2][2] == ch)
        return true;

    if(box[0][2] == ch && box[1][1] == ch && box[2][0] == ch)
        return true;

    return false;
}

int main()
{
    resetBoard();

    char player = 'X';
    int pos;
    int moves = 1;   // 🔥 start from 1

    while(true)
    {
        displayBoard();

        cout << "Player " << player << " enter position (1-9): ";
        cin >> pos;

        if(pos < 1 || pos > 9)
        {
            cout << "Invalid!\n";
            continue;
        }

        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;

        if(box[row][col] == 'X' || box[row][col] == 'O')
        {
            cout << "Already filled!\n";
            continue;
        }

        box[row][col] = player;

        if(checkWinner(player))
        {
            displayBoard();
            cout << "Player " << player << " Wins!\n";
            break;
        }

        // switch player
        if(player == 'X')
            player = 'O';
        else
            player = 'X';

        // 🔥 move update
        moves++;

        // 🔥 draw condition
        if(moves > 9)
        {
            displayBoard();
            cout << "Match Draw!\n";
            break;
        }
    }

    return 0;
}