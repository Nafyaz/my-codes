#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll l, r;

ll Pow(ll a, ll p)
{
    ll ret = 1;
    while(p && ret <= (r + a - 1)/a)
    {
        ret *= a;
        p--;
    }

    if(p)
        return -1;
    else
        return ret;
}

void solve(ll caseno)
{
    ll x, y, val, val1, val2, i, j, ans;

    cin >> x >> y >> l >> r;

    set<ll> st;
    for(i = 0; i < 70; i++)
    {
        val1 = Pow(x, i);

        if(val1 == -1)
            break;

        for(j = 0; j < 70; j++)
        {
            val2 = Pow(y, j);

            if(val2 == -1)
                break;

            val = val1 + val2;
            if(val > r)
                break;

            if(l <= val)
                st.insert(val);
        }
    }

    vector<ll> v;
    for(auto u : st)
    {
        v.push_back(u);
        // cout << u << " ";
    }
    // cout << "\n";

    if(v.empty())
    {
        cout << r-l+1 << "\n";
        return;
    }

    ans = 0;
    for(i = 0; i < v.size(); i++)
    {
        if(i == 0)
            ans = max(ans, v[i] - l);
        else
            ans = max(ans, v[i] - v[i-1] - 1);
    }

    ans = max(ans, r - v.back());

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