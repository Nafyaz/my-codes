#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

ll Fact[MAXN], Inv[MAXN];

ll bigmod(ll a, ll p)
{
    if(p == 0)
        return 1;

    ll ret = bigmod(a, p/2);
    ret = (ret * ret) % MOD;

    if(p&1)
        ret = (ret * a) % MOD;

    return ret;
}

ll getInv(ll x)
{
    return bigmod(x, MOD-2);
}

ll nCr(ll n, ll r)
{
    ll ret = Fact[n];
    ret = (ret * Inv[r]) % MOD;
    ret = (ret * Inv[n-r]) % MOD;

    return ret;
}

void solve(int caseno)
{
    ll n, k, l, r, i, ans;
    string s;

    cin >> n >> s;
    k = s.size();

    if(n%2)
    {
        cout << "0\n";
        return;
    }

    l = r = n/2;
    for(i = 0; i < s.size(); i++)
    {
        l -= (s[i] == '(');
        r -= (s[i] == ')');

        if(l > r)
        {
            cout << "0\n";
            return;
        }
    }

    if(l < 0 || r < 0)
    {
        cout << "0\n";
        return;
    }

    ans = ((nCr(l+r, l) - nCr(l+r, l-1)) % MOD + MOD) % MOD;
    
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    Fact[0] = 1;
    Inv[0] = 1;
    for(ll i = 1; i < MAXN; i++)
    {
        Fact[i] = (Fact[i-1] * i) % MOD;
        Inv[i] = (Inv[i-1] * getInv(i)) % MOD;
    }

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}