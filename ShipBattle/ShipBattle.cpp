#include <iostream>
#include <string>
#include <random>

using namespace std;

struct globalBattle
{
    char board[10][10] = {
            {'0','0','0','0','0','0','0','0','0','0'}, // 0
            {'0','0','0','0','0','0','0','0','0','0'}, // 1
            {'0','0','0','0','0','0','0','0','0','0'}, // 2
            {'0','0','0','0','0','0','0','0','0','0'}, // 3
            {'0','0','0','0','0','0','0','0','0','0'}, // 4
            {'0','0','0','0','0','0','0','0','0','0'}, // 5
            {'0','0','0','0','0','0','0','0','0','0'}, // 6
            {'0','0','0','0','0','0','0','0','0','0'}, // 7
            {'0','0','0','0','0','0','0','0','0','0'}, // 8
            {'0','0','0','0','0','0','0','0','0','0'} // 9
    };

    void PrintBoard()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int s = 0; s < 10; s++)
            {
                cout << board[i][s] << ' ';
            }
            cout << endl;
        }
    }

    void RandSettings()
    {
        int shipSymCoord = rand() % 10 + 1;
        int shipNumCoord = rand() % 10 + 1;
        int countTh = 0;
        int* ptrCountTh = &countTh;
        for (int i = 0; i < 4; i++)
        {
            board[shipSymCoord][shipNumCoord] = '1';
        }
    }

    void HandleSettings(int type, int sym, int num)
    {
        for (int i = 0; i < type; i++)
        {
            board[sym][num + i] = type;
        }
    }

    void SetBomb(string player, int sym, int num)
    {
        board[sym][num] = 'X';
        cout << player << " has bomb is planted";
    }

    void WinChecker()
    {
        for (int s = 0; s < 10; s++)
        {
            for (int i = 0; i < 10; i++)
            {
                if (board[s][i] == '0' || board[s][i] == 'X')
                {
                    cout << "Win";
                }
                else {
                    cout << "Lose";
                    break;
                }
            }
        }
    }
};

int main()
{
    char select;
    cout << "You need bot for game in ship battle? y/n" << endl;
    cin >> select;
    globalBattle global;
    switch (select)
    {
    case 'y':
        global.RandSettings();
    case 'n':
        string playerOne, playerTwo;
        cout << "First player name" << endl;
        cin >> playerOne;
        cout << "Second player name" << endl;
        cin >> playerTwo;
        int type, sym, num;
        for (int i = 0; i < 10; i++)
        {
            cout << playerOne << endl;
            cout << "Select type: " << endl;
            cin >> type;
            cout << "Select position: " << endl;
            cin >> sym;
            cout << "Number: " << endl;
            cin >> num;
            global.HandleSettings(type, sym, num);
            global.PrintBoard();
        }
        for (int i = 0; i < 80; i++)
        {
            cout << playerTwo << " Point: " << endl;
            cin >> sym;
            cin >> num;
            global.SetBomb(playerTwo, sym, num);
        }
        global.WinChecker();
    }
}