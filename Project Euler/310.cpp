#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

int g[MAXN];

int get_mex(vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] != i)
            return i;
    }

    return v.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, j, n, ans;
    g[1] = 1;

    n = MAXN;
    for(i = 3; i <= n; i++)
    {
        // if(i > 100)
        // {
        //     g[i] = g[i - 34];
        //     continue;
        // }

        vector<int> v;
        for(j = 1; j*j <= i; j++)        
            v.push_back(g[i - j]); 

        sort(v. begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        // cout << i << "; v: ";
        // for(auto u : v)
        //     cout << u << " ";
        // cout << "\n";

        g[i] = get_mex(v);
    }

    ans = 0;
    for(i = 0; i <= 15; i++)
    {
        cout << g[i] << " ";
        ans += (g[i] != 0);
    }
    
    // cout << ans << "\n";
}