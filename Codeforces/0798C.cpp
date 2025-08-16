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

bool arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, a, ans, g = 0, cnt;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        g = __gcd(g, a);

        arr[i] = a%2;
    }

    if(g > 1)
    {
        cout << "YES\n0\n";
        return 0;
    }

    ans = cnt = 0;
    for(i = 0; i < n; i++)
    {
        if(arr[i])
            cnt++;
        else if(cnt)
        {
            cnt = 0;
            ans += 2;
        }

        if(cnt == 2)
        {
            cnt = 0;
            ans++;
        }
    }

    if(cnt)
    {
        cnt = 0;
        ans += 2;
    }

    cout << "YES\n";
    cout << ans << "\n";
}