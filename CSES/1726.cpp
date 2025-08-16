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

double dp[102][8][8];
int dirR[4] = {-1, 0, 1, 0};
int dirC[4] = {0, 1, 0, -1};

bool isValid(int i, int j)
{
    if(i >= 0 && i < 8 && j >= 0 && j < 8)
        return 1;
    return 0;
}

int getTotal(int i, int j)
{
    if(i == 0 && j == 0)
        return 2;
    if(i == 0 && j == 7)
        return 2;
    if(i == 7 && j == 0)
        return 2;
    if(i == 7 && j == 7)
        return 2;

    if(i == 0 || i == 7 || j == 0 || j == 7)
        return 3;
    
    return 4;
}

void solve(int caseno)
{
    int n, step, i, j, i2, j2, k, total;
    double ans;

    cin >> n;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
            dp[0][i][j] = 1;
    }

    for(step = 1; step <= n; step++)
    {
        for(i = 0; i < 8; i++)
        {
            for(j = 0; j < 8; j++)
            {
                total = getTotal(i, j);
                for(k = 0; k < 4; k++)
                {
                    i2 = i + dirR[k];
                    j2 = j + dirC[k];
                
                    if(isValid(i2, j2))
                        dp[step][i2][j2] += dp[step-1][i][j]/total;
                }
            }
        }
    }

    ans = 1;
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            ans *= (1 - dp[n][i][j]);
            // cout << fixed << setprecision(2) << dp[n][i][j] << " ";
        }
        cout << "\n";
    }

    cout << fixed << setprecision(8) << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}