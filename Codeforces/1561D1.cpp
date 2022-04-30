#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ans[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, i, j, sum = 0;

    cin >> n >> m;

    ans[1] = 1;
    sum = 1;

    for(i = 2; i <= n; i++)
    {
        ans[i] = sum;

        for(j = 1; j < i/j; j++)
        {
            ans[i] = (ans[i] + ans[j]*(i/j - i/(j+1))) % m;

            if(j > 1)
                ans[i] = (ans[i] + ans[i/j]) % m;
        }

        if(j == i/j)
            ans[i] = (ans[i] + ans[j]) % m;

        sum = (sum + ans[i]) % m;
    }

    cout << "\n";

    cout << ans[n];
}