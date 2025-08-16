#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

ll diag[MAXN], diagSq[MAXN];
ll pref[MAXN], prefSq[MAXN];

void solve(int caseno)
{
    ll n, i, x, ans, low, high, mid;

    cin >> n;

    x = 0;
    low = 1;
    high = MAXN;
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(n > mid*(mid+1)/2)
        {
            x = mid;
            low = mid + 1;;
        }
        else
            high = mid - 1;
    }

    ans = (((pref[x]*n - prefSq[x]) % MOD) + MOD) % MOD;

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    for(ll i = 1; i < MAXN; i++)
    {
        diag[i] = (i*(i+1)/2) % MOD;
        diagSq[i] = (diag[i] * diag[i]) % MOD;
        pref[i] = (pref[i-1] + diag[i]) % MOD;
        prefSq[i] = (prefSq[i-1] + diagSq[i]) % MOD;
    }

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}