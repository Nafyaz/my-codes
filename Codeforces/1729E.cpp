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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    LL low, high, mid, ans;
    LL len;

    low = 3;
    high = 1e18;

    ans = 3;
    while(low < high)
    {
        mid = (low + high) / 2;

        // show(low);
        // show(high);
        // show(mid) << "\n";

        cout << "? " << mid << " " << mid+1 << "\n";
        cin >> len;

        if(len == -1)
            high = mid;
        else
        {
            // show(ans);
            // show(low);
            ans = max({low, mid+1, len+1, ans-len+1});
            // show(ans);
            // show(low);
            low = max({low, mid+1, len+1, ans-len+1});
            // show(ans);
            // show(low) << "\n";
            ans = max({low, mid+1, len+1, ans-len+1});
        }
    }

    cout << "! " << ans << "\n";
}