#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int n, m;
string grid[1009];
map<pair<int, int>, int> mp;
map<pair<int, int>, pair<int, int>> par;
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};

pair<int, int> Find(pair<int, int> a)
{
    if(par.find(a) == par.end() || par[a] == a)
        return par[a] = a;
    return par[a] = Find(par[a]);
}

void Union(pair<int, int> a, pair<int, int> b)
{
    a = Find(a);
    b = Find(b);
    if(a != b)
        par[a] = b;
}

int check(pair<int, int> a)
{
    if(a.ff < 0 || a.ff >= n || a.ss < 0 || a.ss >= m || grid[a.ff][a.ss] == '*')
        return 0;
    return 1;
}

int dfs(pair<int, int> v)
{
    if(mp.find(v) != mp.end())
        return mp[Find(v)];
    mp[v] = 0;
    int i;
    pair<int, int> u;
    for(i = 0; i < 4; i++)
    {
        u = {v.ff+dirx[i], v.ss+diry[i]};
        if(check(u))
        {
            Union(u, v);
            dfs(u);
        }
        else
            mp[Find(v)]++;
    }
    return mp[Find(v)];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, i, a, b;
    cin >> n >> m >> k;
    for(i = 0; i < n; i++)
        cin >> grid[i];

    for(i = 0; i < k; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        pair<int, int> v = {a, b};
        cout << dfs(v) << endl;
    }
}
