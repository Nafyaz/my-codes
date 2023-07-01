#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

ll arr[maxN];

void solve(ll caseno)
{
    bool type;
    ll n, c, p, q, v, i;

    cin >> n >> c;

    fill(arr+1, arr+n+1, 0);    

    while(c--)
    {
        cin >> type;

        if(type)
        {
            cin >> p >> q;
            v = 0;
            for(i = p; i <= q; i++)
                v += arr[i];

            cout << v << "\n";            
        }
        else
        {
            cin >> p >> q >> v;
            
            for(i = p; i <= q; i++)
                arr[i] += v;
        }
    }
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