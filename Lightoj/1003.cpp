#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 10004

bool flag;
vector<int> adj[MAXN];
int color[MAXN];

void dfs(int v)
{
    if(flag)
        return;

    color[v] = 1;
    
    for (auto u : adj[v])
    {
        if (color[u] == 1)
        {
            flag = true;
            return;
        }

        if (color[u] == 0)
            dfs(u);
    }

    color[v] = 2;
}

void solve(int caseno)
{
    int edge, n = 0, col = 0;
    string us, vs;
    unordered_map<string, int> mp;
    cin >> edge;

    while(edge--)
    {
        cin >> us >> vs;

        if(mp.find(us) == mp.end())
        {
            n++;
            mp[us] = n;
        }

        if (mp.find(vs) == mp.end())
        {
            n++;
            mp[vs] = n;
        }

        adj[mp[us]].push_back(mp[vs]);
    }

    flag = false;
    for(int i = 1; i <= n; i++)
    {
        if(color[i] == 0)
        {
            dfs(i);
        }

        if(flag)
            break;
    }

    for(int i = 1; i <= n; i++)
    {
        adj[i].clear();
        color[i] = 0;
    }

    cout << "Case " << caseno << ": " << (flag? "No" : "Yes") << "\n";
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