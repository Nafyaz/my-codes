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

    int i, n, m, mn, a[102];

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n, greater<int>());

    for(i = 0; i < n; i++)
    {
        mn = min(m, a[i]);

        m -= mn;

        if(m == 0)
        {
            cout << i+1 << "\n";
            return 0;
        }
    }
}