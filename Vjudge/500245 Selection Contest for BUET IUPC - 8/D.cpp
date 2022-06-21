#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1300

ll a[MAXN];

void solve(ll caseno)
{
    ll n, i, diff, div;

    cin >> n;

    for(i = 0; i < MAXN; i++)
    {
        div = MAXN - i;
        a[i] = n / div;
        n -= a[i] * div;
    }

    // for(i = 0; i < MAXN; i++)
    // {
    //     if(a[i] > 0)
    //     {
    //         show(i);
    //         show(a[i]);
    //         cout << "\n";
    //     }
    // }

    cout << "nunhehhe";
    for(i = MAXN-1; i >= 0; i--)
    {
        cout << "h";
        while(a[i])
        {
            cout << "a";
            a[i]--;
        }
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}