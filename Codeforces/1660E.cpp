#include<bits/stdc++.h>
using namespace std;
#define ll long long

 string a[2003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, j, ones, mx, onesDiag;

    cin >> T;

    while(T--)
    {
        cin >> n;

        set<ll> rows, cols;

        for(i = 0; i < n; i++)
        {
            rows.insert(i);
            cols.insert(i);
        }

        ones = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];

            for(j = 0; j < n; j++)
                ones += (a[i][j] == '1');
        }

        mx = 0;
        for(i = 0; i < n; i++)
        {
            onesDiag = 0;
            for(j = 0; j < n; j++)
                onesDiag += (a[(i+j)%n][j] == '1');

            mx = max(mx, onesDiag);
        }
//        cout << "ones: " << ones << "; found: " << found << "\n";

        cout << ones - mx + n - mx << "\n";
    }
}
