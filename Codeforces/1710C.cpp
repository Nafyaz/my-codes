#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll k;
ll a[MAXN];

bool isPossible(ll n, ll m)
{
    ll extra = 0, i, parts;

    for(i = 0; i < k; i++)
    {
        parts = a[i]/m;

        if(parts < 2)
            continue;

        if(n == 1 && extra == 0)
            return 0;

        extra += parts-2;
        n -= 2;
    }

    return (n <= extra);
}

void solve(int caseno)
{
    ll n, m, i;

    cin >> n >> m >> k;

    for(i = 0; i < k; i++)
        cin >> a[i];

    sort(a, a+k, greater<ll>());

    cout << ((isPossible(n, m) || isPossible(m, n))? "Yes\n" : "No\n");
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