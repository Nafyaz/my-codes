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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, a, prev, ans, dir;

    cin >> n;

    ans = dir = 0;
    prev = -1;
    for(i = 0; i < n; i++)
    {
        cin >> a;

        if(dir != 0)
        {
            if(dir == 1 && prev > a || dir == -1 && prev < a)
            {
                ans++;
                dir = 0;
            }
            prev = a;
            continue;
        }

        if(prev == -1)
            ans++;
        else
        {
            if(prev < a)
                dir = 1;
            else if(prev > a)
                dir = -1;
        }

        prev = a;
    }

    cout << ans << "\n";
}