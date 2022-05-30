#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll v[2003], cSum[2003];

ll color[2003][2003];
double dp[2003][2003];

double call(ll bg, ll ed, ll c)
{
    // cout << bg << " " << ed << endl;
    if(color[bg][ed] == c)
        return dp[bg][ed];
    
    color[bg][ed] = 1;

    if(bg == ed)
        return dp[bg][ed] = v[bg];

    double left, right;
    left = cSum[ed] - cSum[bg-1] - call(bg+1, ed, c);
    right = cSum[ed] - cSum[bg-1] - call(bg, ed-1, c);

    return dp[bg][ed] = 0.5*left + 0.5*right;
}

void solve(ll caseno)
{
    ll n, i;
    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> v[i];
        cSum[i] = cSum[i-1] + v[i];
    }

    cout << call(1, n, caseno) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}