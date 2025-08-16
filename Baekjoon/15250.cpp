#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000006
#define MOD 1000000007

ll base = 31;
ll p[MAXN], Hash[MAXN];

bool isEqual(ll i, ll j, ll len)
{
    ll h1, h2;

    h1 = ((Hash[i+len-1] - Hash[i-1]*p[len])%MOD + MOD) % MOD;
    h2 = ((Hash[j] - Hash[j-len]*p[len])%MOD + MOD) % MOD;

    return h1 == h2;
}

void solve()
{
    ll i, j, len, ans;
    string s;

    cin >> s;

    for(i = 1; i <= s.size(); i++)
        Hash[i] = (Hash[i-1]*base + (s[i-1] - 'a' + 1)) % MOD;

    ans = 0;
    for(i = 1, j = s.size(); i <= j; i += len, j -= len)
    {
        for(len = 1; i+len-1 < j-len+1; len++)
        {
            if(isEqual(i, j, len))
                break;
        }

        if(i+len-1 >= j-len+1)
        {
            ans++;
            break;
        }

        ans += 2;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i;

    p[0] = 1;
    for(i = 1; i < MAXN; i++)
        p[i] = (p[i-1] * base) % MOD;

    cin >> T;

    while(T--)
    {
        solve();
    }
}
