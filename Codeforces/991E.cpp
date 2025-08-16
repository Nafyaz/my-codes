#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll freq[10], cnt[10], fact[20];

ll getFact(ll x)
{
    if(x <= 1)
        return fact[x] = 1;

    if(fact[x] != 0)
        return fact[x];

    return fact[x] = getFact(x-1) * x;
}

ll calc()
{
    ll pos, total = 0;
    for(pos = 0; pos < 10; pos++)
        total += cnt[pos];

    ll ret1, ret2;
    
    ret1 = getFact(total);
    for(pos = 0; pos < 10; pos++)
        ret1 /= getFact(cnt[pos]);

    if(cnt[0] == 0)
        ret2 = 0;
    else
    {
        ret2 = getFact(total - 1) / getFact(cnt[0] - 1);
        for(pos = 1; pos < 10; pos++)
            ret2 /= getFact(cnt[pos]);
    }

    return ret1 - ret2;
}

ll call(ll pos)
{
    if(pos == 10)
        return calc();

    if(freq[pos] == 0)
        return call(pos+1);

    ll ret = 0;
    for(ll i = 1; i <= freq[pos]; i++)
    {
        cnt[pos] = i;
        ret += call(pos+1);
    }

    return ret;
}

void solve(ll caseno)
{
    ll i;
    string s;
    
    cin >> s;

    for(i = 0; i < s.size(); i++)    
        freq[s[i] - '0']++;

    cout << call(0) << "\n";    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}