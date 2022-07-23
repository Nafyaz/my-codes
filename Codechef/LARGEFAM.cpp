#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 300005

ll arr[MAXN];

void solve(ll caseno)
{
    ll n, i, ans, cnt;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    ans = 0;
    cnt = 1;
    for(i = 0; i < n; i++)
    {
        cnt += arr[i];
        if(cnt <= n)
            ans++;
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
