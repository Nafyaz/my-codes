#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll n, BIT[MAXN];

void Update(ll i, ll d)
{
    while(i <= n)
    {
        BIT[i] += d;
        i += i & (-i);
    }
}

ll Query(ll i)
{
    ll sum = 0;
    while(i > 0)
    {
        sum += BIT[i];
        i -= i & (-i);
    }
    
    return sum;
}

void solve(ll caseno)
{
    ll idx, add, i;

    n = 20;

    while(1)
    {
        cin >> idx >> add;
        Update(idx, add);
        for(i = 0; i <= n; i++)
            cout << setw(3) << i;
        cout << "\n";
        for(i = 0; i <= n; i++)
            cout << setw(3) << BIT[i];
        cout << "\n";
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}