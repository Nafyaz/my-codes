#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll S[5003], C[5003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, i, j, ans, baire;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            cin >> S[i];
            C[i] = 0;
        }

        ans = 0;
        for(i = 1; i <= n; i++)
        {
            ans += max(0LL, S[i] - C[i] - 1);

            for(j = i+2; j <= i+S[i] && j <= n; j++)
                C[j]++;

            C[i+1] += max(0LL, C[i] - S[i] + 1);
        }

        cout << ans << "\n";
    }
}
