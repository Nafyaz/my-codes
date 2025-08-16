#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll a[202];

void solve(ll caseno)
{
    ll n, k, q, i, l;

    cin >> n >> k >> q;

    for(i = 1; i <= k; i++)
        cin >> a[i];

    while(q--)
    {
        cin >> l;
        if(a[l] != n)
        {
            if(l == k)
                a[l]++;
            else if(a[l] + 1 < a[l+1])
                a[l]++;
        }
    }

    for(i = 1; i <= k; i++)
        cout << a[i] << " ";
    cout << "\n";
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