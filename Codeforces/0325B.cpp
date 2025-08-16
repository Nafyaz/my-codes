#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll Mul(ll a, ll b, ll c)
{
    ll ret = 0;

    while(b)
    {
        if(a > c)
            return -1;
        if(b&1)
            ret += a;
        if(ret > c)
            return -1;
        
        a *= 2;

        b /= 2;
    }

    return ret;
}

void solve(ll caseno)
{
    ll n, p, low, high, mid, val;

    cin >> n;

    set<ll> ans;
    for(p = 0; (1LL << p) <= n+1; p++)
    {
        if(1 + (1LL << (p+1)) - 3 == 2*n)
            ans.insert(1LL << p);

        low = 1;
        high = sqrt(2*n)+1;
        while(low <= high)
        {
            mid = (low + high) / 2;
            val = Mul(mid, (mid + ((1LL << (p+1)) - 3)), 2*n);

            if(val > 2*n || val == -1)
                high = mid - 1;
            else if(val < 2*n)
                low = mid + 1;            
            else 
            {
                if(mid % 2 == 1)
                    ans.insert(mid << p);
                break;
            }
        }
    }

    if(ans.empty())
        cout << "-1\n";
    else
    {
        for(auto u : ans)
            cout << u << "\n";
    }
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