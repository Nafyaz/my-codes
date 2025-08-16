#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 5203

ll n;
bool grid[maxN][maxN];
ll preSum[maxN][maxN];

bool allEqual(ll r, ll c, ll x)
{
    ll sum = preSum[r+x-1][c+x-1] - preSum[r-1][c+x-1] - preSum[r+x-1][c-1] + preSum[r-1][c-1];

    return (sum == 0 || sum == x*x);
}

bool check(ll x)
{
    ll i, j;
    for(i = 1; i <= n; i += x)
    {
        for(j = 1; j <= n; j += x)
        {
            if(!allEqual(i, j, x))
                return 0;
        }
    }

    return 1;
}

void solve(ll caseno)
{
    ll i, j, k, val;
    string str;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> str;

        for(j = 1; j <= n/4; j++)
        {
            val = 0;
            if(str[j-1] >= 'A')
                val = str[j-1] - 'A' + 10;
            else
                val = str[j-1] - '0';

            for(k = 3; k >= 0; k--)
            {
                grid[i][j*4+k-3] = val%2;
                val /= 2;
            }
        }

        for(j = 1; j <= n; j++)
            preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + grid[i][j];
    }

    // for(i = 1; i <= n; i++)
    // {
    //     for(j = 1; j <= n; j++)
    //         cout << setw(4) << grid[i][j];
    //     cout << "\n";
    // }
    // cout << "\n\n";

    // for(i = 1; i <= n; i++)
    // {
    //     for(j = 1; j <= n; j++)
    //         cout << setw(4) << preSum[i][j];
    //     cout << "\n";
    // }

    vector<ll> divisors;
    for(i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            divisors.push_back(i);
            if(n/i != i)
                divisors.push_back(n/i);
        }
    }

    sort(divisors.begin(), divisors.end(), greater<ll>());

    for(auto x : divisors)
    {
        if(check(x))
        {
            cout << x << "\n";
            return;
        }
    }
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