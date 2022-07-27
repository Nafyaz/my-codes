#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

#define inf (1 << 30) - 1
pair<pii, int> limits[MAXN];
int ans[MAXN];

void solve(int caseno)
{
    int n, m, i, prevR;

    cin >> n >> m;

    for(i = 0; i < m; i++)
        cin >> limits[i].ff.ff >> limits[i].ff.ss >> limits[i].ss;

    sort(limits, limits+m);

    prevR = 0;
    ans[0] = inf;
    for(i = 0; i+1 < m; i++)
    {
        if(i == 0 || limits[i-1].ff.ss < limits[i].ff.ff)
        {
            ans[limits[i].ff.ff] = limits[i].ss;
        }
        else
        {

        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
