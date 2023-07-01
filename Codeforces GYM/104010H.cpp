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
#define MAXN 200005

LL ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, cntA, x, val;
    string s;

    cin >> n >> s;

    cntA = 0;
    for(i = 0; i < n; i++)
        cntA += (s[i] == 'A');

    val = x = 0;
    for(i = 0; i < n; i++)
    {
        x += (s[i] == 'A');
        if(x > cntA/2)
        {
            ans[i] = ++val;
        }
    }

    ans[i] = ++val;
    for(i = n; i >= 0; i--)
    {
        if(ans[i] == 0)
            ans[i] = ++val;
    }

    for(i = 0; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}