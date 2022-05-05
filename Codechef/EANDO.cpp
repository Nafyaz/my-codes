#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, total, a;

    cin >> T;

    while(T--)
    {
        cin >> n;

        total = 0;

        for(i = 0; i < n; i++)
        {
            cin >> a;
            total += a;
        }

        cout << ((total % (n/2) == 0 && (total / (n/2)) % 2 == 1)? "YES\n" : "NO\n");
    }
}