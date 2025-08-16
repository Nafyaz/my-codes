#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

vector<pair<int, int>> blocks[MAXN];
int layerMax[MAXN], layerCount[MAXN], layerNo[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w;
    cin >> n >> w;

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        blocks[x].push_back({y, i});
    }

    for (int x = 1; x <= w; x++)
    {
        sort(blocks[x].begin(), blocks[x].end());
        for (int i = 0; i < blocks[x].size(); i++)
        {
            layerMax[i] = max(layerMax[i], blocks[x][i].first);
            layerCount[i]++;
            layerNo[blocks[x][i].second] = i;
        }
    }

    int q, t, a;
    cin >> q;
    while (q--)
    {
        cin >> t >> a;

        int lNo = layerNo[a];
        cout << (layerCount[lNo] == w && layerMax[lNo] <= t ? "No" : "Yes") << "\n";
    }
}