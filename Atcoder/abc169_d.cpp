#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

ll calc(ll sum)
{
    ll i;
    for(i = 1; i*(i+1)/2 <= sum; i++);

    return i-1;
}

void solve(ll caseno)
{
    ll n, ans = 0, i, p, cnt;

    cin >> n;

    for(i = 2; i*i <= n; i++)
    {
        for(cnt = 0; n%i == 0; cnt++)        
            n /= i;
        
        ans += calc(cnt);
    }

    if(n > 1)
        ans++;

    cout << ans << "\n";
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