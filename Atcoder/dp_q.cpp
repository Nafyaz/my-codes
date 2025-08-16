#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 200005

LL h[MAXN], a[MAXN];
LL BIT[MAXN];

void update(LL idx, LL x)
{
    for(; idx < MAXN; idx += idx & (-idx))
        BIT[idx] = max(BIT[idx], x);
}

LL query(LL idx)
{
    LL ret = 0;
    for(; idx > 0; idx -= idx & (-idx))
        ret = max(ret, BIT[idx]);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> h[i];
    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++)
        update(h[i], query(h[i]-1)+a[i]);

    cout << query(n) << "\n";
}