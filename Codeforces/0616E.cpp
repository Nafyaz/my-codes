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

    LL n, m, i, ans, cnt;
    LL modLow, modHigh, nLow, nHigh;
    LL low, high, mid, nMid, foundN, foundMod;

    cin >> n >> m;

    ans = ((max(0LL, m-n)%MOD) * (n%MOD)) % MOD;

    modLow = 1;
    modHigh = min(m, n-1);
    nLow = n - modHigh;
    nHigh = n - 1;

    for(i = 1; modHigh > max(LL(MAXN), LL(sqrt(m))); i++)
    {
        // show(i);
        // show(modLow);
        // show(modHigh);
        // show(nLow);
        // show(nHigh) << "\n";

        foundN = -1;
        foundMod = -1;

        low = modLow;
        high = modHigh;

        // cout << "(Before BS)";
        // show(i);
        // show(foundN);
        // show(foundMod);
        // show(low);
        // show(high) << "\n";

        while(low <= high)
        {
            mid = (low + high) / 2;
            nMid = nLow + (modHigh - mid) * i;

            if(nMid < mid)
            {
                foundN = nMid;
                foundMod = mid;

                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        // cout << "(After BS) ";
        // show(i);
        // show(foundN);
        // show(foundMod);
        // show(low);
        // show(high);

        if(foundN != -1)
        {
            cnt = ((foundN - nLow)/i)%MOD;
            ans += ((cnt+1)*(nLow%MOD))%MOD + ((((cnt*(cnt+1)/2)%MOD))*i)%MOD;
            ans %= MOD;

            // show(ans);

            nLow = (foundN+i) - (foundMod-1);
            nHigh = nHigh - 1;
            modHigh = foundMod - 1;
        }
        else
        {
            nLow = nLow - modHigh;
            nHigh = nHigh - 1;
        }

        cout << "\n\n";
    }

    while(modHigh > 1)
    {
        ans = (ans + n%modHigh) % MOD;
        modHigh--;
    }

    cout << ans << "\n";
}