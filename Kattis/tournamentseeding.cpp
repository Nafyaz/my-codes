#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 300005

ll arr[MAXN];

void solve(int caseno)
{
    ll n, k, i, j, pos, half, total, ans;

    cin >> n >> k;
    total = (1LL << n);

    for(i = 0; i < total; i++)
        cin >> arr[i];

    sort(arr, arr+total);

    ans = 0;
    while(total > 1)
    {
        half = total/2;

        j = half;
        for(i = 0; i < half; i++)
        {
            pos = upper_bound(arr, arr+total, arr[i] + k) - arr;
            pos--;

            if(j <= pos)
            {
                ans++;
                j++;
            }
        }

        for(i = 0; i < half; i++)
            arr[i] = arr[i+half];

        total /= 2;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
