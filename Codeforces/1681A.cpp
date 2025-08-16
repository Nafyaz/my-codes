#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, m, i;
    ll a, maxA, b, maxB;
    
    cin >> T;

    while(T--)
    {
        cin >> n;

        maxA = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            maxA = max(maxA, a);
        }
        
        cin >> m;

        maxB = 0;
        for(i = 0; i < m; i++)
        {
            cin >> b;
            maxB = max(maxB, b);
        }        

        if(maxA > maxB)
            cout << "Alice\nAlice\n";
        else if(maxA < maxB)
            cout << "Bob\nBob\n";
        else
            cout << "Alice\nBob\n";
    }
}