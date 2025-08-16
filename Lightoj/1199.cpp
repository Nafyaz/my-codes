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
#define MAXN 10004

int grundy[MAXN];
bool vis[MAXN];

void solve(int caseno)
{
    int n, i, a, ans = 0;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        ans ^= grundy[a];
    }

    cout << "Case " << caseno << ": " << (ans? "Alice\n" : "Bob\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, j;
    for(i = 3; i < MAXN; i++)
    {
        memset(vis, 0, sizeof vis);
        for(j = 1; 2*j < i; j++)
            vis[grundy[j] ^ grundy[i-j]] = 1;
        
        for(j = 0; i < MAXN && vis[j]; j++);

        grundy[i] = j;
    }
    
    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}