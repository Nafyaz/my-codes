#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int n, m;
vector<vector<int>> p;

bool calc(int x)
{
    int i, j, satCount, maxSatCount, satShop;
    int taken[n];
    set<int> shops;

    // show(x);

    maxSatCount = 0;
    for(i = 0; i < m; i++)
    {
        satCount = 0;
        for(j = 0; j < n; j++)
        {
            if(p[i][j] >= x)
                satCount++;
        }

        if(satCount > maxSatCount)
        {
            maxSatCount = satCount;
            satShop = i;
        }
    }

    memset(taken, -1, sizeof taken);
    for(j = 0; j < n; j++)
    {
        if(p[satShop][j] >= x)
            taken[j] = satShop;
    }

    // cout << "taken: ";
    // for(j = 0; j < n; j++)
    //     cout << taken[j] << " ";
    // cout << "\n";

    for(j = 0; j < n; j++)
    {
        if(taken[j] != -1)
            continue;

        for(i = 0; i < m; i++)
        {
            if(p[i][j] >= x)
            {
                taken[j] = i;
                break;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(taken[i] != -1)   
            shops.insert(taken[i]);
        else
            return 0;
    }

    return (shops.size() <= n-1);
}

void solve(int caseno)
{
    int i, j, low, high, mid, ans;

    cin >> m >> n;

    p = vector<vector<int>>(m, vector<int>(n, 0));

    low = INT_MAX;
    high = 0;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> p[i][j];

            low = min(low, p[i][j]);
            high = max(high, p[i][j]);
        }
    }

    // for(i = 0; i < m; i++)
    // {
    //     for(j = 0; j < n; j++)
    //         cout << p[i][j] << " ";
    //     cout << "\n";
    // }

    // cout << calc(9) << "\n";

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(calc(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << ans << "\n";
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