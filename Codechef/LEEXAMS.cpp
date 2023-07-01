#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
double p[51];
ll a[51], b[51];
bool vis[200005];
double dp[200005];

double call(ll mask)
{
    // cout << "mask: " << mask << "; vis: " << vis[mask] << "\n";
    if(vis[mask])
        return dp[mask];
    
    ll i = __builtin_popcountll(mask);
    if(i == n)
        return dp[mask] = 1;

    double ret = 0;

    if((mask & (1LL << a[i])) == 0)
        ret += p[i]*call(mask | (1LL << a[i]));
    if((mask & (1LL << b[i])) == 0)
        ret += (1 - p[i])*call(mask | (1LL << b[i]));

    vis[mask] = 1;
    return dp[mask] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)        
        {
            cin >> p[i] >> a[i] >> b[i];
            p[i] /= 100;
        }

        // for(i = 0; i < n; i++)
        //     cout << p[i] << " " << a[i] << " " << b[i] << "\n";
        
        memset(vis, 0, sizeof vis);
        // call(0);
        // for(i = 0; i < 8; i++)
        //     cout << dp[i] << " ";
        // cout << endl;
        cout << call(0) << "\n";
    }
}