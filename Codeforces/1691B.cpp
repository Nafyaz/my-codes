#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007

map<ll, vector<ll>> freq;

void solve(ll caseno)
{
    ll n, i, s;
    freq.clear();

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> s;

        freq[s].push_back(i);
    }

    for(auto u : freq)
    {
        if(u.ss.size() == 1)
        {
            cout << "-1\n";
            return;
        }
    }

    for(auto u : freq)
    {
        for(i = 0; i < u.ss.size(); i++)
        {
            cout << u.ss[(i+1)%u.ss.size()] << " ";
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