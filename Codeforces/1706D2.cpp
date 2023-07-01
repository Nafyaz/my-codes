#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

int n, a[MAXN];

bool isOk(int mn, int mx)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(upper_bound(possible[i].begin(), possible[i].end(), mx) == lower_bound(possible[i].begin(), possible[i].end(), mn))
            return 0;
    }

    return 1;
}

void solve(int caseno)
{
    int k, i, j, mx, mxCnt, mn;
    int div, low, high, mid, ans;

    cin >> n >> k;

    for(i = 0; i < n; i++)
        cin >> a[i];

//    show(isOk(4, 6));
//    cout << "\n";

//    for(i = 0; i < n; i++)
//    {
//        cout << i << ": ";
//        for(auto u : possible[i])
//            cout << u << " ";
//        cout << "\n";
//    }

    ans = a[n-1];
    for(mx = 0; mx <= a[n-1]; mx++)
    {
        mn = -1;
        low = 0;
        high = mx;
        while(low <= high)
        {
            mid = (low + high)/2;

            if(isOk(mid, mx))
            {
                mn = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

//        show(mn);
//        show(mx);
//        cout << "\n";

        if(mn != -1)
            ans = min(ans, mx - mn);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

/*
1
5 2
4 5 6 8 11
*/

