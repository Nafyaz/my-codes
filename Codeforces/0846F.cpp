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
#define MAXN 1000006

LL a[MAXN];
LL last[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, ans;

    cin >> n;
    ans = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];

        ans += 2*(i - last[a[i]]) * (n-i+1) - 1;
        last[a[i]] = i;
    }

    cout << fixed << setprecision(6) << 1.0*ans/(n*n) << "\n";
}