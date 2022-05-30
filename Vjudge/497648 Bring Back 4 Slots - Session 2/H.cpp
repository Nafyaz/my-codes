#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "

void solve()
{
    ll n, i, a, ans = 0;
    map<ll, ll> freq;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;

        // show(i);
        // show(a);
        // cout << "\n";

        for(auto u : freq)
        {
            if(u.ff < a-u.ff)
            {
                if(freq.find(a-u.ff) != freq.end())
                    ans += u.ss * freq[a-u.ff];
            }
            else
                break;
        }

        if(a%2 == 0 && freq.find(a/2) != freq.end())
            ans += freq[a/2]*(freq[a/2] - 1)/2;

        freq[a]++;
    }

    cout << ans << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}