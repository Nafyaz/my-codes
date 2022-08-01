#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    ll n, m, i, j;
    string a, b;

    cin >> n >> m;
    cin >> a >> b;

    for(i = 1; i < m; i++)
    {
        if(a[n-i] != b[m-i])
        {
            cout << "NO\n";
            return;
        }
    }

    for(i = 0; i <= n-m; i++)
    {
        if(a[i] == b[0])
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

