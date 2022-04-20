#include<bits/stdc++.h>
#define ll long long
#define CHECK(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
#define int ll
int cnt[200005];
vector<int> v;
int chk(int x)
{
    int laagbe = 0;
    int ext = 1;
    for(int i = 0; i < v.size(); i++)
    {
        laagbe++;
        if(x - i - 1 < v[i] - 1) ext += (v[i] - 1 ) - (x - i - 1);
    }
    return laagbe + ext <= x;

}
void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cnt[i] = 0;
    for(int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    v.clear();
    for(int i = 1; i<= n; i++) if(cnt[i]) v.push_back(cnt[i]);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int ans = n;
    int sz = v.size();
    for(int j = 20; j >= 0; j--)
    {
        if(ans - (1 << j) > sz && chk(ans - (1 << j)))
        {
            ans -= (1 << j);
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
    while(t--) solve();
}
