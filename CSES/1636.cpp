#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll c[105];
ll ans[1000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen("in.txt", "r", stdin);

    ll n, x, i, j;

    cin >> n >> x;

    for(i = 1; i <= n; i++)
        cin >> c[i];

    ans[0] = 1;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= x; j++)
        {
            if(c[i] <= j)
                ans[j] = (ans[j] + ans[j-c[i]]) % mod;
        }
    }

    cout << ans[x];
}
