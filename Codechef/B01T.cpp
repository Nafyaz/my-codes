#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll a[300005];
ll parent[300005], level[300005];
vector<ll> adj[300005];

void bfs(ll st)
{
    queue<ll> q;
    ll node;

    q.push(st);
    while(!q.empty())
    {
        node = q.front();
        q.pop();

        for(auto child : adj[node])
        {
            if(child != parent[node])
            {
                level[child] = level[node] + 1;
                parent[child] = node;
                q.push(child);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, u, v, diff, m;
    vector<pair<ll, ll>> nodes;
    set<ll> st;
    queue<ll> q;

    cin >> T;

    while(T--)
    {
        cin >> n;

        diff = 0;
        for(i = 1; i <= n; i++)
        {
            cin >> a[i];

            diff += (a[i]? 1 : -1);

            adj[i].clear();
            level[i] = parent[i] = 0;
        }

        for(i = 1; i < n; i++)
        {
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(1);

        nodes.clear();
        for(i = 1; i <= n; i++)        
            nodes.push_back({level[i], i});
        
        sort(nodes.begin(), nodes.end(), greater<pair<ll, ll>>());

        m = 0;
        for(i = 0; i < n; i++)
        {
            diff += (a[nodes[i].ss]? -2 : 2);
            if(diff == 0)
            {
                m = i+1;
                break;
            }
        }

        st.clear();
        for(i = 0; i < m; i++)
            st.insert(nodes[i].ss);
        
        for(auto u : st)
        {
            if(st.find(parent[u]) != st.end())
                q.push(u);
        }

        while(!q.empty())
        {
            st.erase(q.front());
            q.pop();
        }

        cout << st.size() << "\n";
        for(auto u : st)
            cout << u << " ";
        cout << "\n";
    }
}