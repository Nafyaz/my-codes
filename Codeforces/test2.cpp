#include<bits/stdc++.h>
#define ll long long
#define CHECK(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
// #define int ll
vector<int> adj[200005];
set<int> st[200005];
int arr[200005], xr[200005];
int dfs(int u,int par = 0){
	int ret = 0;
	int bigchild = 0,sz = 0;
	xr[u] = arr[u] ^ xr[par];
	for(auto &v : adj[u]){
		if(v == par) continue;
		ret += dfs(v , u);
		if(st[v].size() > sz){
			sz = st[v].size(), bigchild = v;
		}
	}
	if(sz) swap(st[u] , st[bigchild]);
	int flag = 0;
	for(auto &v : adj[u]){
		if(v == par) continue;
		if(v == bigchild) continue;
		for(auto &cv : st[v]){
			if(st[u].count(cv ^ arr[u])){
				flag = 1;
			}
		}
		for(auto &cv : st[v]) st[u].insert(cv);
		st[v].clear();
	}
	if(st[u].count(arr[u] ^ xr[u])) flag = 1;
	else st[u].insert(xr[u]);
	if(flag) st[u].clear();
	return ret + flag;
}
void solve()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout << dfs(1) << '\n';

}
int32_t main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--) solve();
}