#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 50004

ll arr[maxN], blocks[maxN];


void solve(ll caseno)
{
    ll n, i, len, q;
    string type;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> arr[i];

    len = sqrt(n);
    

    cin >> q;

    while(q--)
    {
        cin >> type;

        if(type == "Q")
        {
            cin >> l >> r;
            cout << Query(1, 1, n, l, r) << "\n";
        }
        else
        {
            cin >> i >> v;
            Update(1, 1, n, i, v);
        }
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