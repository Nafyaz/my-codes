#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(ll caseno)
{
    ll n, m, k, i, j;

    cin >> n >> m >> k;

    if(k > min(n, m))
    {
        cout << "Impossible\n";
        return;
    }

    cout << "Possible\n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(i == j && i < k)
                cout << "*";
            else
                cout << ".";
        }

        cout << "\n";
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