#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll base = 31, p[102];
ll n, m, x, y;
string s[1003], t[1003];
ll HashS[1003][1003], HashT[102][102];

void solve(ll caseno)
{
    ll i, j, k, ans;
    bool flag;

    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        cin >> s[i];
        for(j = 1; j <= m; j++)        
            HashS[i][j] = (HashS[i][j-1] * base + (s[i][j-1] - 'a' + 1)) % MOD;        
    }

    cin >> x >> y;
    for(i = 0; i < x; i++)
    {
        cin >> t[i];
        for(j = 1; j <= y; j++)
            HashT[i][j] = (HashT[i][j-1] * base + (t[i][j-1] - 'a' + 1)) % MOD;
    }

    ans = 0;
    for(i = 0; i+x-1 < n; i++)
    {
        for(j = 0; j+y-1 < m; j++)
        {
            flag = 1;
            for(k = 0; k < x; k++)
            {
                // if(i == 0 && j == 1)
                // {
                //     show(k);
                //     cout << "\n";
                // }

                if((HashS[i+k][j]*p[y] + HashT[k][y]) % MOD != HashS[i+k][j+y])
                {
                    flag = 0;
                    break;
                }
            }

            ans += flag;
        }
    }

    cout << ans << "\n";    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    p[0] = 1;
    for(int i = 1; i < 102; i++)
        p[i] = (p[i-1] * base) % MOD;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}