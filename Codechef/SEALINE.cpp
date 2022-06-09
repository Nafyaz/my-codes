#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "

ll pos[102];

void solve(ll caseno)
{
    ll n, i, j, a, ans = 0;

    cin >> n;

    for(i = 1; i <= n; i++)    
    {
        cin >> a;        
        ans += min(pos[a], i-pos[a]-1);

        for(j = 1; j <= n; j++)
            pos[j] += (pos[j] > pos[a]);
        pos[i] = pos[a] + 1;
    }
    
    cout << ans << "\n";
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