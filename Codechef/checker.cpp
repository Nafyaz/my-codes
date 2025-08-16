#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 100005

ll arr[maxN];

void solve(ll caseno)
{
    vector<ll> v({10, 1, 10, 1, 10});
    ll i, n = v.size(), Q, k, x, idx;

    cin >> Q;

    while(Q--)
    {
        cin >> k >> x;

        for(i = 0; i < k; i++)
        {
            cin >> idx;
            v[idx - 1] += x;
        }

        for(auto u : v)
            cout << u << " ";

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