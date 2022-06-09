#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007

ll cSum[100005];

ll Delete(vector<ll> v)
{
    ll i, j, ret = 0;
    for(i = 0; i < v.size(); i++)
    {
        ret += v[i];
        for(j = i+1; j < v.size(); j++)
            v[j] += v[i];
    }

    return ret;
}

void solve(ll caseno)
{
    ll n, q, i, l, r, ones, zeros, ans, temp;
    string s;

    cin >> n >> q;

    cin >> s;
    for(i = 1; i <= n; i++)
        cSum[i] = cSum[i-1] + (s[i-1] == '1');

    while(q--)
    {
        cin >> l >> r;
        
        ones = cSum[r] - cSum[l-1];
        zeros = r-l+1 - ones;

        vector<ll> v(ones, 1);
        v.insert(v.end(), zeros, 0);

        sort(v.begin(), v.end());

        // for(auto u : v)
        //     cout << u << " ";
        // cout << "\n";

        ans = 0;
        do
        {
            ans = max(ans, Delete(v));
        }while(next_permutation(v.begin(), v.end()));

        cout << ans << "\n";
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}