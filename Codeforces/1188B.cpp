#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cerr << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 300005

map<LL, LL> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, p, k, i, x, y, z, ans;

    cin >> n >> p >> k;

    for(i = 0; i < n; i++)
    {
        cin >> x;

        y = x;
        x = (x*x)%p;
        x = (x*x)%p;

        z = ((x - k*y)%p + p) % p;

        // show(x);
        // show(y);
        // show(z) << "\n";

        mp[z]++;
    }

    ans = 0;
    for(auto [val, cnt] : mp)
        ans += cnt*(cnt-1)/2;

    cout << ans << "\n";
}