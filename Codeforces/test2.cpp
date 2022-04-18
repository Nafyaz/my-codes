#include<bits/stdc++.h>
#define ll long long
#define CHECK(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
#define int ll
int lg[200005];
void pre()
{
    for(int i = 2; i <= 200000; i++) lg[i] = lg[i / 2] + 1;
    for(int i = 2; i<= 200000; i++) lg[i] += i != (1 << lg[i]);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v,pre;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
    {
        pre.push_back(i ? (v[i - 1] == v[i] ? pre.back() : i - 1) : -1);
    }
    pre.push_back(n - 1);
    int ans = (1 << lg[n]) - n + 2;
    for(int i = 0; i < n; i++)
    {
        if(i + 1 < n && v[i + 1] == v[i]) continue;
        for(int mid = 1; mid <= n ; mid += mid)
        {
            int nibo = pre[min(i + mid + 1,n)];
            if(nibo <= i) continue;
            int cur = (1 << lg[i + 1]) - i - 1;
            cur += (1 << lg[nibo - i]) - nibo + i;
            cur += (1 << lg[n -1  - nibo]) - n + 1 + nibo;
            ans = min(ans,cur);
        }
    }
    cout << ans << '\n';

}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    pre();
    while(t--) solve();
}
