#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    freopen("in.txt", "w", stdout);

    ll n = 1000, x = 100000, i;

    cout << n << " " << x << "\n";
    for(i = 0; i < n; i++)    
        cout << rand()%999 + 1 << " ";
    cout << "\n";

    for(i = 0; i < n; i++)
        cout << rand()%999 + 1 << " ";
    cout << "\n";    
}