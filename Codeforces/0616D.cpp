#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 500005

ll a[MAXN];
map<ll, ll> freq;

void solve(ll caseno)
{
    ll n, k, i, j, mx, l, r;

    cin >> n >> k;

    mx = 0;
    for(i = 0, j = 0; i < n; i++)
    {
        cin >> a[i];

        freq[a[i]]++;
        while(freq.size() > k)
        {
            freq[a[j]]--;
            if(freq[a[j]] == 0)
                freq.erase(a[j]);

            j++;
        }

        if(i - j + 1 > mx)
        {
            mx = i - j + 1;
            l = j+1;
            r = i+1;
        }
    }

    cout << l << " " << r << "\n";
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