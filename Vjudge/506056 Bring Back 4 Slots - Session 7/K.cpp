#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000006
#define ff first
#define ss second

int n;
vector <int> adj[MAXN];
int subtree_size[MAXN];
int dist[MAXN] = {-1}, parent[MAXN];
pair<int, int> distNode[MAXN];
int val[MAXN], valRev[MAXN];
int ans[MAXN];

int get_subtree_size(int node, int p)
{
	int ret = 1;

	for (auto next : adj[node])
    {
		if (next != p)
            ret += get_subtree_size(next, node);
	}
	return subtree_size[node] = ret;
}

int get_centroid(int node, int p)
{
	for (auto next : adj[node])
    {
		if (next != p && subtree_size[next] * 2 > n)
			return get_centroid(next, node);
	}
	return node;
}

void bfs(int s)
{
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto nxt : adj[cur])
        {
            if(dist[nxt] == -1)
            {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

int main()
{
    int i, j, k, p, cur, centroid, total;
	cin >> n;
	for (i = 2; i <= n; i++)
    {
		cin >> p;

		adj[i].push_back(p);
		adj[p].push_back(i);
	}

	get_subtree_size(1, -1);
	centroid = get_centroid(1, -1);

	cout << centroid << "\n";

	memset(dist, -1, sizeof dist);
	bfs(centroid);

//	for(i = 1; i <= n; i++)
//        cout << dist[i] << " ";
//    cout << "\n";

	for(i = 1; i <= n; i++)
    {
        distNode[i].ff = dist[i];
        distNode[i].ss = i;
    }

    sort(distNode + 1, distNode + n + 1);

    for(i = 1, j = n, k = n; i < j; i++, j--, k -= 2)
    {
        val[distNode[k].ss] = i;
        val[distNode[k-1].ss] = j;

        valRev[i] = distNode[k].ss;
        valRev[j] = distNode[k-1].ss;
    }

    if(k == 1)
    {
        val[distNode[k].ss] = i;
        valRev[i] = distNode[k].ss;
    }

    total = 0;
    for(i = 1; i <= n; i++)
    {
        cur = valRev[i];

        ans[cur] = 1;
        for(auto nxt : adj[cur])
        {
            if(val[nxt] < val[cur])
                ans[cur] += ans[nxt];
        }

        total += ans[cur];
    }

    cout << total << "\n";
}
