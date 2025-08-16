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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i;
    long double p[102];

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> p[i];
    
    sort(p, p+n);

    if(p[n-1] > 0.5)
    {
        cout << p[n-1] << "\n";
        return 0;
    }

    for(i = 1; i < n; i++)
        p[i] = p[i]*(1 - p[i-1]) + (1 - p[i])*p[i-1];

    cout << fixed << setprecision(9) << p[n-1] << "\n";
}