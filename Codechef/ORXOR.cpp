#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int n, x, i, val;

    cin >> n >> x;

    if(n == 2)
    {
        if(x == 3)
            cout << "1 1 2\n";
        else
            cout << "-1\n";
        return;
    }

    if((n&(n-1)) == 0 && (x&(1 << __builtin_ctz(n))) == 0)
    {
        cout << "-1\n";
        return;
    }

    if(__builtin_clz(n) > __builtin_clz(x))
    {
        cout << "-1\n";
        return;
    }

    val = 3;
    vector<pair<int, pii>> ans;
    for(i = 5; i <= n; i++)
    {
        if(i&(i-1))
        {
            ans.push_back({1, {val, i}});
            val |= i;
        }
    }

    for(i = 1; i <= n; i++)
    {
        if((i&(i-1)) == 0)
        {
            if(x&i)
            {
                ans.push_back({1, {val, i}});
                val |= i;
            }
            else
            {
                ans.push_back({2, {val, i}});
                val ^= i;
            }
        }
    }

    if(val != x)
    {
        cout << "-1\n";
        return;
    }

    for(auto u : ans)
        cout << u.ff << " " << u.ss.ff << " " << u.ss.ss << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}