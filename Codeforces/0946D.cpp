#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll n, m, skip;
vector<ll> pos[502];
ll dp1[502][502];   //dp1[i][j] = minimum hours I need to stay in ith day if I skip j lessons
ll dp2[502][502];   //dp2[i][j] = minimum hours I need to stay for upto ith day with j more skips to take

ll call(ll i, ll j)
{
    if(i == n)
        return 0;
    if(dp2[i][j] != -1)
        return dp2[i][j];

    ll ret = INT_MAX;
    for(ll k = 0; k <= j; k++)    
        ret = min(ret, call(i+1, j - k) + dp1[i][k]);
    
    return dp2[i][j] = ret;
}

void solve(ll caseno)
{
    ll i, j, k, sz;
    string s;
    
    cin >> n >> m >> skip;

    for(i = 0; i < n; i++)
    {
        cin >> s;
        for(j = 0; j < m; j++)
        {
            if(s[j] == '1')
                pos[i].push_back(j);
        }
    }

    for(i = 0; i < n; i++)
    {
        sz = pos[i].size();
        for(j = 0; j <= sz; j++)
        {
            if(j == sz)
                dp1[i][j] = 0;
            else if(j+1 == sz)
                dp1[i][j] = 1;
            else
            {
                dp1[i][j] = INT_MAX;
                for(k = 0; k <= j; k++)                
                    dp1[i][j] = min(dp1[i][j], pos[i][sz-(j-k)-1] - pos[i][k] + 1);             
            }
        }
    }

    // for(i = 0; i < n; i++)
    // {
    //     for(j = 0; j < m; j++)
    //         cout << dp1[i][j] << " ";
    //     cout << "\n";
    // }

    memset(dp2, -1, sizeof dp2);
    cout << call(0, skip) << "\n";
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