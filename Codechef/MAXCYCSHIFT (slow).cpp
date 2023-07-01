#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll arr[MAXN], brr[MAXN];

void solve(ll caseno)
{
    ll n, i, shift, mx;

    cin >> n;

    for(i = 1; i <= n; i++)    
        cin >> arr[i];
    
    mx = 0;
    for(shift = 0; shift < n; shift++)
    {
        map<ll, ll> mp;
        for(i = 1; i <= n; i++)
        {
            brr[i] = brr[i-1] ^ arr[(i+shift-1)%n+1];
            mp[brr[i]]++;
        }

        mx = max(mx, (ll)mp.size());
    }    

    cout << mx << "\n";
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