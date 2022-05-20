#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, j, n = 3;

    cout << (1LL << n) - 1 << "\n";

    for(i = 0; i < (1LL << n); i++)
    {
        cout << "3 1\n";
        for(j = 0; j < n; j++)        
            cout << ((i & (1LL << j)) >> j) << " ";
        
        cout << "\n";
    }
}