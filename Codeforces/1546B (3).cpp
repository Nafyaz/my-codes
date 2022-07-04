#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

bool freq[MAXN][26];

void solve(ll caseno)
{
    ll n, m, i, j;
    string s;

    cin >> n >> m;

    for(i = 1; i <= 2*n-1; i++)
    {
        cin >> s;
        for(j = 0; j < m; j++)
            freq[j][s[j] - 'a'] ^= 1;
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < 26; j++)
        {
            if(freq[i][j])            
            {
                cout << (char)('a' + j);            
                freq[i][j] ^= 1;
            }
        }
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}