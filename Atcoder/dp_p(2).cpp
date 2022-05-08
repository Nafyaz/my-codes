#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll n;
vector<ll> adj[100005];
ll dp[100005][2], edge[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, a, b, node, val1, val2;

    cin >> n;
    for(i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        edge[a]++;
        edge[b]++;
    }

    queue<ll> q;
    for(i = 2; i <= n; i++)
    {
        if(edge[i] == 1)
            q.push(i);
    }

    while(!q.empty())
    {
        node = q.front();
        q.pop();

        if(node != 1 && adj[node].size() == 1)
        {
            dp[node][0] = 2;
            dp[node][1] = 1;

            ll u = adj[node][0];
            edge[u]--;
            edge[node]--;

            if(edge[u] <= 1)
                q.push(u);

            continue;
        }

        val1 = val2 = 1;
        for(auto u : adj[node])
        {
            if(edge[u])
            {
                edge[u]--;
                edge[node]--;

                if(edge[u] <= 1)
                    q.push(u);

                continue;
            }
            
            val1 = (val1 * dp[u][0]) % mod;
            val2 = (val2 * dp[u][1]) % mod;
        }

        dp[node][0] = (val1 + val2) % mod;
        dp[node][1] = val1;
    }

    cout << dp[1][0];

    // for(i = 1; i <= n; i++)
    // {
    //     cout << i << ": " << dp[i][0] << ", " << dp[i][1] << "\n";
    // }
}