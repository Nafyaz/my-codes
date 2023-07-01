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
#define MAXN 100005

LL a[MAXN], pref[MAXN];
LL Log[MAXN], sparse[MAXN][21];

LL getMin(LL i, LL j)
{
    LL k = Log[j-i+1];

    return min(sparse[i][k], sparse[j-(1LL<<k)+1][k]);
}

bool check1(LL i, LL j, LL req)
{
    LL sum = pref[j] - pref[i-1];

    return (sum >= req);
}

bool check2(LL i, LL j, LL req)
{
    LL sum = pref[j] - pref[i-1];
    LL mn = getMin(i, j);

    return (sum-mn >= req);
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    LL n, i, j, low, high, mid, ans, total, req;

    Log[1] = 0;
    for(i = 2; i < MAXN; i++)
        Log[i] = Log[i/2] + 1;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
        sparse[i][0] = a[i];
    }

    total = pref[n];
    req = (total + 1)/2;

    for(j = 1; j < 21; j++)
    {
        for(i = 1; i + (1LL << j) - 1 <= n; i++)
        {
            // show(i);
            // show(j) << "\n";
            sparse[i][j] = min(sparse[i][j-1], sparse[i + (1LL << (j-1))][j-1]);
        }
    }

    // for(i = 1; i <= n; i++)
    // {
    //     for(j = 0; j <= 3; j++)
    //         cout << sparse[i][j] << " ";
    //     cout << "\n";
    // }

    ans = n;
    for(i = 1; i <= n; i++)
    {
        low = i;
        high = n;
        while(low <= high)
        {
            mid = (low + high)/2;

            if(check1(i, mid, req))
            {
                ans = min(ans, mid-i+1);
                high = mid-1;
            }
            else
                low = mid+1;
        }

        low = i;
        high = n;
        while(low <= high)
        {
            mid = (low + high)/2;

            if(check2(i, mid, req))
            {
                ans = min(ans, mid-i);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
    }

    cout << ans << "\n";
}