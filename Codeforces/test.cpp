#include<bits/stdc++.h>
#define ll long long
#define CHECK(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
// #define int ll
vector<int> tre[200005 * 4];
vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> ret;
    int l = 0, r = 0;
    while(ret.size() <= 30)
    {
        if(l == a.size() && r == b.size()) break;
        if(l == a.size()) ret.push_back(b[r++]);
        else if(r == b.size()) ret.push_back(a[l++]);
        else if(a[l] < b[r]) ret.push_back(a[l++]);
        else ret.push_back(b[r++]);
    }
    return ret;
}
int arr[200005];
void init(int n,int l,int r)
{
    tre[n].clear();
    if(l == r)
    {
        tre[n].push_back(arr[l]);
        return ;
    }
    int mid = (l + r) / 2;
    init(2 * n, l, mid );
    init(2 * n + 1, mid + 1, r);
    tre[n] = merge(tre[2 * n], tre[2 * n + 1]);
}
vector<int> query(int n,int l,int r,int i,int j)
{
    if(i > r || j < l) return vector<int> ();
    if(i <= l && j >= r) return tre[n];
    int mid = (l + r) / 2;
    return merge(query(2 *  n, l, mid, i, j), query(2 * n + 1, mid + 1, r, i, j));
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    init(1, 0, n - 1);
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        l--,r--;
        auto cur = query(1, 0, n - 1, l, r);
        int ans = 2000000000;
        for(int i = 0; i < cur.size() ; i++) for(int j = i + 1; j < cur.size(); j++) ans = min(ans, cur[i] | cur[j]);
        cout << ans << '\n';
    }

}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}
