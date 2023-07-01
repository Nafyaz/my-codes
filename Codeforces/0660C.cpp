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
#define MAXN 300005

LL a[MAXN], pref[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, k, i, ans, ansIdx;
    LL low, high, mid;
    LL zeros;

    cin >> n >> k;

    ans = -1;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];

        low = 0;
        high = i;
        while(low <= high)
        {
            mid = (low + high)/2;

            zeros = mid - (pref[i] - pref[i-mid]);
            if(zeros <= k)
            {
                if(ans < mid)
                {
                    ans = mid;
                    ansIdx = i;
                }

                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }

    for(i = ansIdx; i > ansIdx-ans; i--)
        a[i] = 1;

    cout << ans << "\n";
    for(i = 1; i <= n; i++)
        cout << a[i] << " ";
}