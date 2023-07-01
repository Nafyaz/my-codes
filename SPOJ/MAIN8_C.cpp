#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 500004

ll arr[MAXN];

void solve(ll caseno)
{
    ll n, k, i, low, high, mid, cnt, ans;

    cin >> n >> k;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n, greater<ll>());

    low = 1;
    high = arr[0];
    ans = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        cnt = 0;
        for(i = 0; i < n && arr[i] >= mid; i++)        
            cnt += (arr[i] /mid);
        
        if(cnt >= k)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}