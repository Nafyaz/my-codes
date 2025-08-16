#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

pair<ll, bool> W[MAXN];

void solve(ll caseno)
{
    ll n, i, temp, ans, child, adult, totalChild, totalAdult;
    string s;

    cin >> n >> s;

    totalChild = totalAdult = 0;
    for(i = 0; i < n; i++)
    {
        if(s[i] == '0')
            totalChild++;
        else
            totalAdult++;
    }

    for(i = 0; i < n; i++)
    {
        cin >> W[i].ff;
        W[i].ss = (s[i] == '1');
    }

    sort(W, W+n);

    ans = 0;
    child = 0;
    adult = totalAdult;

    ans = max(ans, child + adult);
    
    for(i = 0; i < n; i++)
    {       
        child += (W[i].ss == 0);
        adult -= (W[i].ss == 1);
        
        if(i+1 < n && W[i].ff == W[i+1].ff)
            continue;
        else
            ans = max(ans, child + adult);
    }

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