#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

void solve(ll caseno)
{
    ll n, i;
    bool flag;

    cin >> n;

    cout << n << "\n";

    vector<ll> v;
    for(i = 1; i <= n; i++)
        v.push_back(i);

    do
    {
        flag = 1;
        for(i = 1; i <= n; i++)
        {
            if(i&v[i-1])
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            for(auto u : v)
                cout << u << " ";

            cout << "\n";
        }

    }while(next_permutation(v.begin(), v.end()));
    cout << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}