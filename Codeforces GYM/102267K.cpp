#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, mask, ans, OR;
    ll a[21];

    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];

    ans = 0;
    for(mask = 0; mask < (1LL << n); mask++)
    {
        OR = 0;
        for(i = 0; i < n; i++)
        {
            if(mask & (1LL << i))
                OR |= a[i];
        }

        ans += OR;
    }

    cout << ans;
}