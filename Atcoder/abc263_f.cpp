#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

LL C[MAXN][20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, j, k, l;

    cin >> n;

    for(i = 0; i < (1LL << n); i++)
    {
        for(j = 1; j <= n; j++)
            cin >> C[i][j];
    }
}