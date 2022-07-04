#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 998244353
#define MAXN 1000006

ll root[MAXN];

ll Find(ll x)
{
    if(root[x] == x)
        return x;
    
    return root[x] = Find(root[x]);
}

void solve(ll caseno)
{
    ll n, q, i, l, r, ans;

    cin >> n >> q;

    for(i = 1; i <= n; i++)
        root[i] = i;

    ans = 1;
    while(q--)
    {
        cin >> l >> r;

        l = Find(l-1);
        r = Find(r);

        if(l != r)
        {
            ans = (ans * 2) % MOD;
            root[max(l, r)] = min(l, r);
        }
    }
    
    cout << ans << "\n";
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

/*
2 3
1 2
2 2
1 1
*/