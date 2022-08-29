#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 2000006;

LL root[MAXN], sz[MAXN];

LL Find(LL x)
{
    if (x == root[x])
        return x;
    return root[x] = Find(root[x]);
}

void Union(LL x, LL y) {
    x = Find(x);
    y = Find(y);

    if(x == y)
        return;

    if(sz[x] > sz[y])
        swap(x, y);

    root[x] = y;
    sz[y] += sz[x];
}

void solve(int caseno)
{
    LL n, m, i, x, y, ans;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        root[i] = i;
        sz[i] = 1;
    }

    for(i = 1; i <= m; i++)
    {
        cin >> x >> y;
        Union(x, y);
    }

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        if(Find(i) == i)
            ans += sz[i]*(sz[i]-1)/2;
    }

//    show(ans);
//    show(n*(n-1)/2);
//    cout << "\n";

    cout << fixed << setprecision(10) << 1.0*ans/(n*(n-1)/2) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
