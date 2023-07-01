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
#define MAXN 100005

LL leader[MAXN], sz[MAXN];

bool isLucky(LL x)
{
    while(x)
    {
        if(x%10 != 4 && x%10 != 7)
            return 0;

        x /= 10;
    }

    return 1;
}

LL Find(LL x)
{
    if(leader[x] == x)
        return x;
    
    return leader[x] = Find(leader[x]);
}

void Union(LL x, LL y)
{
    x = Find(x);
    y = Find(y);

    if(x == y)
        return;

    if(sz[x] > sz[y])
        swap(x, y);

    sz[y] += sz[x];
    leader[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, a, b, w, ans;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        leader[i] = i;
        sz[i] = 1;
    }

    for(i = 1; i < n; i++)
    {
        cin >> a >> b >> w;

        if(!isLucky(w))
            Union(a, b);
    }

    ans = 0;
    for(i = 1; i <= n; i++)    
    {
        if(leader[i] == i)
            ans += sz[i]*(n-sz[i])*(n-sz[i]-1);
    }
    
    cout << ans << "\n";
}