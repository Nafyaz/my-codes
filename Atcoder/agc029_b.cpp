#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

map<ll, ll> freq;

void solve(int caseno)
{
    ll n, i, a, x, y, ans;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> a;
        freq[a]++;
    }

    ans = 0;
    for(i = 32; i >= 0; i--)
    {
        for(auto u : freq)
        {
            x = u.ff;
            y = (1LL << i) - x;

            if(x == y)
            {
                while(freq[x] > 1)
                {
                    freq[x] -= 2;
                    ans++;
                }
            }
            else if(freq.find(y) != freq.end())
            {
                while(freq[x] > 0 && freq[y] > 0)
                {
                    freq[x]--;
                    freq[y]--;

                    ans++;
                }
            }

        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}


