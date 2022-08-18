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
    ll x, y, i, l, r;

    cin >> x >> y;

    for(i = 1; i*i <= y; i++)
    {
        if(y%i == 0)
        {
            l = i;
            r = y/i;

            if(r < x/2)
            {
                cout << l << " " << r << "\n";
                cout << x/2 << " " << (x+1)/2 << "\n";
                return;
            }

            if(l > (x+1)/2)
            {
                cout << l << " " << r << "\n";
                cout << x/2 << " " << (x+1)/2 << "\n";
                return;
            }
        }
    }

    cout << "-1\n";
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

