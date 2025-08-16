#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

int leader[MAXN];

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

    if(x == y)
        return;

    leader[min(x, y)] = max(x, y);
}

void solve(int caseno)
{
    int n, q, type, i, x, low, high, mid, ans;

    cin >> n >> q;

    for(i = 1; i <= n+1; i++)
        leader[i] = i;

    cout << "Case " << caseno << ":\n";
    while(q--)
    {
        cin >> type >> x;

        if(type == 1)        
            Union(x, x+1);
        else
            cout << Find(x) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}