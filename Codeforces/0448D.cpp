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

void solve(int caseno)
{
    ll n, m, k, d, x, y, nums;

    cin >> n >> m >> k;

    for(d = 1; ; d++)
    {
        nums = d - max(0LL, d - n) - max(0LL, d - m);

        if(nums < k)
            k-= nums;
        else
        {
            vector<ll> v;

            for(x = 1, y = d; d >= 1; d--, x++, y--)
            {
                if(x <= n && y <= m)
                    v.push_back(x*y);
            }

            sort(v.begin(), v.end());

            cout << v[k-1] << "\n";
            return;
        }
    }
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
