#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        if(n == 1)
        {
            if(a[0] == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }

        sort(a, a+n);

        if(a[n-1] - a[n-2] <= 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
