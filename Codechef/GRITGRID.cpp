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
    ll n, m, x, y;

    cin >> n >> m >> x >> y;

    if(x%2 != y%2)
    {
        cout << "Yes\n";
        return;
    }
    else if(x%2 == 0 && y%2 == 0)
    {
        if((n+m-2)%2 == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
        return;
    }
    else
    {
        if((n+m-2)%2 == 0)
            cout << "No\n";
        else
            cout << "Yes\n";
        return;
    }
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
