#include<bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << ": " << x << "; "
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define MAXN 100005

pii Tree[4*MAXN];
ll h[MAXN];
map<ll, int> id;

int dp[MAXN], parent[MAXN];

void Update(int node, int bg, int ed, int idx, pii val)
{
	if(bg == ed)
	{
		Tree[node] = val;
		return;
	}

	int leftNode = 2*node, rightNode = 2*node+1;
	int mid = (bg+ed)/2;

	if(idx <= mid)
		Update(leftNode, bg, mid, idx, val);
	else
		Update(rightNode, mid+1, ed, idx, val);

	Tree[node] = max(Tree[leftNode], Tree[rightNode]);
}

pii Query(int node, int bg, int ed, int l, int r)
{
	if(l > ed || r < bg)
		return {0, 0};
	else if(l <= bg && ed <= r)
		return Tree[node];

	int leftNode = 2*node, rightNode = 2*node+1;
	int mid = (bg+ed)/2;

	return max(Query(leftNode, bg, mid, l, r), Query(rightNode, mid+1, ed, l, r));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, d, i, j, l, r, cnt, last;
	vector<int> ans;

	cin >> n >> d;

	for(i = 1; i <= n; i++)
	{
		cin >> h[i];
		id[h[i]] = 0;
	}

	cnt = 0;
	for(auto &u : id)
		u.ss = ++cnt;

	id[LLONG_MIN] = 0;
	id[LLONG_MAX] = cnt+1;

	// cout << "id:\n";
	// for(auto u : id)
	// 	cout << u.ff << " " << u.ss << "\n";
	// cout << "\n";

	for(i = 1; i <= n; i++)
	{
		l = (--id.upper_bound(h[i] - d)) -> ss;
		r = id.lower_bound(h[i] + d) -> ss;

		pii pr = {0, 0};
		if(l >= 1)
			pr = max(pr, Query(1, 1, n, 1, l));
		if(r <= n)
			pr = max(pr, Query(1, 1, n, r, n));

		// show(i);
		// show(l);
		// show(r);
		// show(pr.ff);
		// show(pr.ss);
		// cout << "\n";

		dp[i] = 1 + pr.ff;
		parent[i] = pr.ss;

		Update(1, 1, n, id[h[i]], {dp[i], i});

        // cout << "Tree:\n";
        // for(j = 1; j <= 9; j++)
        //     cout << "(" << j << ") " << Tree[j].ff << " " << Tree[j].ss << "; ";
        // cout << "\n\n";
	}

	cnt = 0;
	for(i = 1; i <= n; i++)
	{
		if(dp[i] > cnt)
		{
			cnt = dp[i];
			last = i;
		}
	}

	while(last > 0)
	{
		ans.push_back(last);
		last = parent[last];
	}

	reverse(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for(auto u : ans)
		cout << u << " ";
	cout << "\n";
}