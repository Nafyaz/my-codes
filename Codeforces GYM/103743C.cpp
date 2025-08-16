#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

ll n, p;
ll arr[MAXN];

ll call(ll pos, ll x)
{
    ll i, ret = LLONG_MIN;

    for(i = 1; x*i <= p; i++)    
    {
        if(pos + x*i <= n)
            ret = max(ret, arr[pos + x*i] + call(pos + x*i, x));
        else
        {
            ret = max(ret, 0LL);
            break;
        }
    }
    
    return ret;
}

void solve(ll caseno)
{
    ll q, i, x;

    cin >> n >> q >> p;

    for(i = 1; i <= n; i++)
        cin >> arr[i];

    while(q--)
    {
        cin >> x;

        if(p < x)
        {
            cout << "Noob\n";
            continue;
        }

        cout << call(0, x) << "\n";
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