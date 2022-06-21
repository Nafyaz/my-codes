#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll arr[MAXN];
ll sparse[MAXN][20], Log[MAXN];

ll query(ll bg, ll ed)
{
    ll k = Log[ed-bg+1];
    return min(sparse[bg][k], sparse[ed - (1 << k) + 1][k]);
}

void solve(ll caseno)
{
    ll n, i, j, ans, low, high, mid, left, right;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        sparse[i][0] = arr[i];
    }

    for(j = 1; j < 20; j++)
    {
        for(i = 0; i + (1LL << j) -1 < n; i++)        
            sparse[i][j] = min(sparse[i][j-1], sparse[i + (1LL << (j-1))][j-1]);        
    }

    // for(i = 0; i < n; i++)
    // {
    //     for(j = 0; j < 3; j++)
    //         cout << sparse[i][j] << " ";
    //     cout << "\n";
    // }

    ans = 0;
    for(i = 0; i < n; i++)
    {
        low = 0;
        high = i;
        while(low <= high)
        {
            mid = (low + high)/2;
            if(query(mid, i) == arr[i])
            {
                left = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        low = i;
        high = n-1;
        while(low <= high)
        {
            mid = (low + high)/2;
            if(query(i, mid) == arr[i])
            {
                right = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        // show(i);
        // show(left);
        // show(right); 
        // cout << "\n";

        ans += arr[i]*(i-left+1)*(right-i+1);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    Log[1] = 0;
    for(ll i = 2; i < MAXN; i++)
        Log[i] = Log[i/2] + 1;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}