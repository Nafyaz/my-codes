#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll arr[3003];

void solve(int caseno)
{
    ll n, i, sum;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> arr[i];

    vector<ll> v(1);
    sum = 0;
    for(i = 1; i <= n; i++)
    {
        sum += arr[i];
        if(sum >= v.back())
        {
            v.push_back(sum);
            sum = 0;
        }
        
        // for(auto u : v)
        //     cout << u << " ";
        // cout << "\n";
    }

    cout << n - v.size() + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}