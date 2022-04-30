#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, R, C, i, j;

    cin >> T;

    while(T--)
    {
        cin >> R >> C;

        cout << "Case #" << ++caseno << ":\n";
        cout << "..+";
        for(j = 2; j <= C; j++)
            cout << "-+";
        cout << "\n";

        cout << "..|";
        for(j = 2; j <= C; j++)
            cout << ".|";
        cout << "\n";

        cout << "+";
        for(j = 1; j <= C; j++)
            cout << "-+";
        cout << "\n";

        for(i = 2; i <= R; i++)
        {
            cout << "|";
            for(j = 1; j <= C; j++)
                cout << ".|";
            cout << "\n";

            cout << "+";
            for(j = 1; j <= C; j++)
                cout << "-+";
            cout << "\n";
        }
    }
}
