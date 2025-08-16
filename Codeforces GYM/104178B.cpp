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

LL w[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, m, i, g = 0, total;

    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> w[i];
        g = __gcd(g, w[i]);
    }

    total = 0;
    for(i = 0; i < n; i++)
        total += w[i]/g;
    
    cout << m/total*total << "\n";
}