#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

void solve(ll caseno)
{
    ll n, k, i, j, cnt, ans;
    ll x[MAXN];
    map<ll, ll> freq;

    cin >> n >> k;

    ans = cnt = 0;
    for(i = 0, j = 0; i < n; i++)
    {
        cin >> x[i];

        freq[x[i]]++;
        if(freq[x[i]] == 1)
            cnt++;

        while(cnt > k)
        {
            freq[x[j]]--;
            if(freq[x[j]] == 0)
                cnt--;

            j++;
        }

        ans += (i - j + 1);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}