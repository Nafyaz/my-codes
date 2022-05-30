#include<bits/stdc++.h>
using namespace std;
#define ll long long

int isValidSudoku(vector<vector<char>> board) {
    int i, j, k, bgR, bgC, freq[10];
    for(i = 0; i < 9; i++)
    {
        memset(freq, 0, sizeof freq);
        for(j = 0; j < 9; j++)
        {
            if(board[i][j] != '.')
            {
                freq[board[i][j] - '0']++;
                if(freq[board[i][j] - '0'] >= 2)
                    return 0;
            }
        }
    }
    
    for(j = 0; j < 9; j++)
    {
        memset(freq, 0, sizeof freq);
        for(i = 0; i < 9; i++)
        {
            if(board[i][j] != '.')
            {
                freq[board[i][j] - '0']++;
                if(freq[board[i][j] - '0'] >= 2)
                    return 0;
            }
        }
    }
    
    for(k = 0; k < 9; k++)
    {
        bgR = k/3*3;
        bgC = k%3;
        memset(freq, 0, sizeof freq);
        for(i = bgR; i < bgR+3; i++)
        {
            for(j = bgC; j < bgC+3; j++)
            {
                if(board[i][j] != '.')
                {
                    freq[board[i][j] - '0']++;
                    if(freq[board[i][j] - '0'] >= 2)
                    {
                        cout << k << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    
    return 1;
}

vector<vector<char>> strTochar(vector<vector<string>> temp)
{
    int i, j;
    vector<vector<char>> ret(9, vector<char>(9, '.'));
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
            ret[i][j] = temp[i][j][0];
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<string>> temp = vector<vector<string>>{vector<string>{"5","3",".",".","7",".",".",".","."},vector<string>{"6",".",".","1","9","5",".",".","."},vector<string>{".","9","8",".",".",".",".","6","."},vector<string>{"8",".",".",".","6",".",".",".","3"},vector<string>{"4",".",".","8",".","3",".",".","1"},vector<string>{"7",".",".",".","2",".",".",".","6"},vector<string>{".","6",".",".",".",".","2","8","."},vector<string>{".",".",".","4","1","9",".",".","5"},vector<string>{".",".",".",".","8",".",".","7","9"}};
    vector<vector<char>> board = strTochar(temp);

    // for(int i = 0; i < 9; i++)
    // {
    //     for(int j = 0; j < 9; j++)
    //         cout << board[i][j];
    //     cout << "\n";
    // }

    cout << isValidSudoku(board);
}