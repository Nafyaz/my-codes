#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

void solve(ll caseno)
{
    ll n, i, a, b, one = 0;

    cin >> n;

    for(i = 1; i < n; i++)
    {
        cin >> a >> b;
        if(a == 1 || b == 1)
            one++;
    }

    if(one == 1 || n%2 == 0)
        cout << "Alice\n";
    else
        cout << "Bob\n";
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