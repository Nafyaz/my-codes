#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 502;

string grid[MAXN];

void solve(int caseno)
{
    int n, m, i, j, ones, cnt;
    bool flag;

    cin >> n >> m;

    ones = 0;
    for(i = 0; i < n; i++)
    {
        cin >> grid[i];
        for(j = 0; j < m; j++)
            ones += (grid[i][j] == '1');
    }

    if(ones == n*m)
    {
        cout << ones - 2 << "\n";
        return;
    }

    flag = 0;
    for(i = 1; i < n; i++)
    {
        for(j = 1; j < m; j++)
        {
            cnt = 0;
            cnt += (grid[i-1][j-1] == '1');
            cnt += (grid[i][j-1] == '1');
            cnt += (grid[i-1][j] == '1');
            cnt += (grid[i][j] == '1');

            if(cnt < 3)
            {
                flag = 1;
                break;
            }
        }
    }

    cout << (flag? ones : ones - 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

