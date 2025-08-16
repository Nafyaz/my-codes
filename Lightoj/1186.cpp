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
#define MAXN 2000006

LL w[102], b[102];

void solve(int caseno)
{
    LL n, i, cnt;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> w[i];
    
    cnt = 0;
    for(i = 0; i < n; i++)
    {
        cin >> b[i];
        cnt ^= (b[i] - w[i] - 1);
    }

    cout << "Case " << caseno << ": " << (cnt == 0? "black" : "white") << " wins\n";
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