#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int n, m, sx, sy, d;

    cin >> n >> m >> sx >> sy >> d;

    if(sx - d > 1 && sy + d < m)
        cout << n+m-2 << "\n";
    else if(sx + d < n && sy - d > 1)
        cout << n+m-2 << "\n";
    else
        cout << "-1\n";
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