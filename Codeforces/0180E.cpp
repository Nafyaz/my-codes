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

int last[MAXN];
vector<int> pref[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, i, j, c, ans, pos;

    cin >> n >> m >> k;

    for(i = 1; i <= n; i++)    
    {
        cin >> c;

        if(last[c] == 0)
            pref[c].push_back(0);
        else
            pref[c].push_back(pref[c].back() + i - 1 - last[c]);

        last[c] = i;
    }

    ans = 0;
    for(i = 1; i <= m; i++)
    {
        for(j = 0; j < pref[i].size(); j++)
        {
            pos = upper_bound(pref[i].begin(), pref[i].end(), pref[i][j] + k) - pref[i].begin();
            ans = max(ans, pos - j);
        }
    }

    cout << ans << "\n";
}