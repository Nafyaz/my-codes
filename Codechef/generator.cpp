#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    freopen("in.txt", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 50, n, i;

    cout << T << "\n";
    while(T--)
    {
        n = rand() % 5 + 1;
        cout << n << "\n";
        for(i = 1; i <= n; i++)
            cout << rand() % 9 + 1 << " ";
        cout << "\n";
    }
}