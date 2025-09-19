#include <bits/stdc++.h>
using namespace std;

#define MAXN 1003

int n;
set<int> adj[MAXN];
int par[MAXN], ans[MAXN];

pair<int, int> findNext(int node)
{
    if (adj[node].size() == 0)
        return {-1, -1};

    if (adj[node].size() == 1)
        return findNext(*adj[node].begin());

    pair<int, int> p = {0, 0};
    for (auto u : adj[node])
    {
        if (p.first == 0 || adj[u].size() < adj[p.first].size())
        {
            p.second = p.first;
            p.first = u;
        }
        else if (p.second == 0 || adj[u].size() < adj[p.second].size())
        {
            p.second = u;
        }
    }

    return p;
}

void unify(int x, int y)
{
    int p = par[y];
    adj[p].erase(y);
    par[y] = x;
    adj[x].insert(y);
}

void Print()
{
    for (int i = 0; i <= n; i++)
    {
        cout << i << ": ";
        for (auto u : adj[i])
            cout << u << " ";
        cout << "\n";
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        adj[0].insert(i);
        par[i] = 0;
    }

    string s;
    while (1)
    {
        pair<int, int> p = findNext(0);

        if (p == make_pair(-1, -1))
            break;

        cout << "? " << p.first << " " << p.second << "\n";
        cin >> s;
        if (s == "YES")
        {
            unify(p.first, p.second);
        }
        else
        {
            unify(p.second, p.first);
        }

        // Print();
    }

    int val = 1, node = *adj[0].begin();
    while (1) 
    {
        ans[node] = val;

        if (adj[node].size() == 0)
            break;

        node = *adj[node].begin();
        val++;
    }

    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    cout << "\n";
}