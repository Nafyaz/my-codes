#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 1000000000000015

struct edge
{
    LL node, nxt, cap, flow = 0;
    edge(LL u, LL v, LL c) : node(u), nxt(v), cap(c) {}
};

struct Dinic
{
    vector<edge> edges;
    vector<vector<LL>> adj;
    vector<LL> level, ptr;

    LL n, m, s, t;

    Dinic(LL n, LL s, LL t) : n(n), s(s), t(t)
    {
        m = 0;
        adj.resize(n+1);
        level.resize(n+1);
        ptr.resize(n+1);
    }

    void add_edges(LL u, LL v, LL c)
    {
        edges.push_back(edge(u, v, c));
        adj[u].push_back(m);
        m++;

        edges.push_back(edge(v, u, c));
        adj[v].push_back(m);
        m++;
    }

    bool bfs(LL s)
    {
        queue<LL> q;

        level[s] = 0;
        q.push(s);

        while(!q.empty())
        {
            LL node = q.front();
            q.pop();

            for(auto id : adj[node])
            {
                LL nxt = edges[id].nxt;
                if(edges[id].cap == edges[id].flow || level[nxt] != -1)
                    continue;

                level[nxt] = level[node] + 1;
                q.push(nxt);
            }
        }

        return (level[t] != -1);
    }

    LL dfs(LL node, LL currFlow)
    {
        if(currFlow == 0)
            return 0;

        if(node == t)
            return currFlow;

        for(LL &cid = ptr[node]; cid < adj[node].size(); cid++)
        {
            LL id = adj[node][cid];
            LL nxt = edges[id].nxt;

            if(level[nxt] != level[node] + 1 || edges[id].cap == edges[id].flow)
                continue;

            LL newFlow = dfs(nxt, min(currFlow, edges[id].cap - edges[id].flow));

            if(newFlow == 0)
                continue;

            edges[id].flow += newFlow;

            return newFlow;
        }

        return 0;
    }

    LL getFlow()
    {
        LL flow = 0;

        while(1)
        {
            fill(level.begin(), level.end(), -1);
            if(!bfs(s))
                break;

            fill(ptr.begin(), ptr.end(), 0);
            while(LL newFlow = dfs(s, INF))
                flow += newFlow;
        }

        return flow;
    }
};

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    LL n, m, p, i, k, toy, l, r;

    cin >> n >> m >> p;

    Dinic dinic(n+m+p+4, 1, n+m+p+3);

    for(i = 1; i <= n; i++)
    {
        dinic.add_edges(1, i+1, 1);
        cin >> k;
        while(k--)
        {
            cin >> toy;
            dinic.add_edges(i+1, n+toy+1, 1);
        }
    }

    set<LL> toySet;
    for(i = 1; i <= m; i++)
        toySet.insert(n+i+1);

    for(i = 1; i <= p; i++)
    {
        cin >> l;
        while(l--)
        {
            cin >> toy;
            toySet.erase(n+toy+1);
            dinic.add_edges(n+toy+1, n+m+i+1, 1);
        }

        cin >> r;
        dinic.add_edges(n+m+i+1, n+m+p+3, r);
    }

    for(auto u : toySet)
        dinic.add_edges(u, n+m+p+2, 1);
    dinic.add_edges(n+m+p+2, n+m+p+3, INF);

   for(i = 0; i < dinic.adj.size(); i++)
   {
       cout << i << ": ";
       for(auto u : dinic.adj[i])
           cout << u << " ";
       cout << "\n";
   }

    cout << dinic.getFlow() << "\n";
}
