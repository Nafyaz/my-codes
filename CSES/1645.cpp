#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll x[MAXN];
stack<ll> stk;

void solve(ll caseno)
{
    ll n, i;

    x[0] = 0;
    stk.push(0);

    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> x[i];

        while(x[stk.top()] >= x[i])
        {
            stk.pop();
        }

        cout << stk.top() << " ";
        stk.push(i);
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