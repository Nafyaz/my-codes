#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 100005

ll arr[MAXN];

void solve(int caseno)
{
    ll n, x, i, mask, ans, ansMask, sum, bit;

    cin >> n >> x;

    for(i = 0; i < n; i++)
        cin >> arr[i];

    ans = 0;
    for(mask = 0; mask < (1LL << n); mask++)
    {
        sum = 0;
        for(i = 1, bit = 2; i < n; i++, bit *= 2)
        {
            if(!(mask&(bit/2)) && !(mask&bit))
                sum += arr[i-1] ^ arr[i];
            else if(!(mask&(bit/2)) && (mask&bit))
                sum += arr[i-1] ^ (arr[i]+x);
            else if((mask&(bit/2)) && !(mask&bit))
                sum += (arr[i-1]+x) ^ arr[i];
            else
                sum += (arr[i-1]+x) ^ (arr[i]+x);
        }

        if(sum > ans)
        {
            ans = sum;
            ansMask = mask;
        }
    }

    cout << ans << "; " << ansMask << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}


