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

bool allEqual(ll r, ll c, ll x)
{
    ll i, j, val = grid[r][c];
    for(i = r; i < r+x; i++)
    {
        for(j = c; j < c+x; j++)
        {
            if(grid[i][j] != grid[r][c])
                return 0;
        }
    }

    return 1;
}

bool check(ll x)
{
    ll i, j;
    for(i = 0; i < n; i += x)
    {
        for(j = 0; j < n; j += x)
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

    for(i = 0; i < n; i++)
    {
        cin >> str;

        for(j = 0; j < n/4; j++)
        {
            val = 0;
            if(str[j] >= 'A')
                val = str[j] - 'A' + 10;
            else
                val = str[j] - '0';

            for(k = 3; k >= 0; k--)
            {
                grid[i][j*4+k] = val%2;
                val /= 2;
            }
        }
    }

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