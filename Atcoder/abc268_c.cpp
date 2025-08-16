#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

int pos[MAXN];
int sat[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, p, ans;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> p;
        pos[p] = i;
    }

    for(i = 0; i < n; i++)
    {
        sat[(i - pos[i] + n)%n] ++;
        sat[(i - pos[i] + n - 1)%n] ++;
        sat[(i - pos[i] + n + 1)%n] ++;
    }

    ans = 0;
    for(i = 0; i < n; i++)
        ans = max(ans, sat[i]);

    cout << ans << "\n";
}