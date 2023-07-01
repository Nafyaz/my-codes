#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

vector<LL> c[MAXN];
map<LL, vector<LL>> mp;

void solve(int caseno)
{
    LL n, m, i, j, k, val, sum, mx;

    cin >> n >> m;

    for(i = 0; i < n; i++)
        c[i].clear();
    mp.clear();

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            cin >> val;
            c[i].push_back(val);
        }
    }

    mx = 0;
    for(i = 0; i < n; i++)
    {
        sum = 0;
        for(j = 0; j < m; j++)   
            sum = sum + c[i][j]*j;
        
        mp[sum].push_back(i);
        mx = max(mx, sum);
    }

    for(auto u : mp)
    {
        if(u.ss.size() == 1)
            k = u.ss[0];
        else
            sum = u.ff;
    }

    cout << k+1 << " " << mx - sum << "\n";
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