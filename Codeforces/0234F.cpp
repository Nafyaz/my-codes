#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

int n;
int h[202];
map<pair<pair<int, bool>, pii>, int> mp;

int call(int pos, bool cur, int a, int b)
{
    if(pos == n)
        return 0;

    if(mp.find({{pos, cur}, {a, b}}) != mp.end())
        return mp[{{pos, cur}, {a, b}}];

    int ret = INT_MAX, v0 = -1, v1 = -1;

    if(cur == 0)
    {
        if(a < h[pos])
            return mp[{{pos, cur}, {a, b}}] = -1;
        v0 = call(pos+1, 0, a-h[pos], b);
        v1 = call(pos+1, 1, a-h[pos], b);
    }
    else
    {
        if(b < h[pos])
            return mp[{{pos, cur}, {a, b}}] = -1;
        v0 = call(pos+1, 0, a, b-h[pos]);
        v1 = call(pos+1, 1, a, b-h[pos]);
    }

    if(v0 == -1 && v1 == -1)
        ret = -1;

    if(v0 != -1)
        ret = min(ret, v0 + (cur == 1)*min(h[pos], h[pos+1]));
    if(v1 != -1)
        ret = min(ret, v1 + (cur == 0)*min(h[pos], h[pos+1]));

    return mp[{{pos, cur}, {a, b}}] = ret;
}

void solve(int caseno)
{
    int a, b, i, v0, v1, ans = 202;

    cin >> n >> a >> b;

    for(i = 0; i < n; i++)
        cin >> h[i];

    v0 = call(0, 0, a, b);
    v1 = call(0, 1, a, b);

//    cout << mp[{{3, 1}, {1, 1}}] << "\n";

    if(v0 == -1 && v1 == -1)
        ans = -1;

    if(v0 != -1)
        ans = min(ans, v0);
    if(v1 != -1)
        ans = min(ans, v1);

    cout << ans << "\n";

//    show(v1);
//    show(v2);
//    cout << "\n";
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
