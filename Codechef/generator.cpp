#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    mt19937 mt(time(nullptr)); 

    ll T = 2, n, i;

    cout << T << "\n";
    while(T--)
    {
        n = rand() % 999 + 2;
        cout << n << "\n";
        for(i = 1; i <= n; i++)
        {
            if(rand() % 2 == 1)
                cout << mt()%10000000000 << "\n";
            else
                cout << - (ll)(mt()%10000000000) << "\n";
        }
        cout << "\n";
    }
}