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

    LL n, i, a, ans, sum;

    cin >> n;

    ans = sum = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a;

        sum += a;

        if(a == 0)
        {
            ans += sum/2;
            sum = 0;
        }
    }

    cout << ans + sum/2 << "\n";
}