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

int a[MAXN], leader[MAXN];

int Find(int x)
{
    if(leader[x] == x)
        return x;

    return leader[x] = Find(leader[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    leader[min(x, y)] = max(x, y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, j;
    int l, r, x;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        leader[i] = i;
    }

    for(i = 1; i <= n; i++)
    {
        if(a[i] == a[i+1])
            Union(i, i+1);
    }

    while(m--)
    {
        cin >> l >> r >> x;

        if(a[l] != x)
        {
            cout << l << "\n";
            continue;
        }

        if(Find(l) >= r)
        {
            cout << "-1\n";
            continue;
        }

        cout << Find(l) + 1 << "\n";
    }
}