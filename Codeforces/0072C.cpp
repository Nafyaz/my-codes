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
    ll x, i;
    vector<ll> even, odd;

    cin >> x;

    for(i = 1; i <= x; i++)
    {
        if(x%i == 0)
        {
            if(i%2 == 0)
                even.push_back(i);
            else
                odd.push_back(i);
        }
    }

    cout << (even.size() == odd.size()? "yes\n" : "no\n") << "\n";
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