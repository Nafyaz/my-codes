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

void solve(int caseno)
{
    ll n, i, swaps, ans;
    vector<pll> sOnes, tOnes;

    string s, t;

    cin >> n >> s >> t;

    if(s[0] != t[0] || s.back() != t.back())
    {
        cout << "-1\n";
        return;
    }

    swaps = 0;
    for(i = 1; i < n; i++)
    {        
        if(s[i] != s[i-1])
            swaps++;
        if(t[i] != t[i-1])
            swaps--;
    }

    if(swaps != 0)
    {
        cout << "-1\n";
        return;
    }

    for(i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            if(i == 0 || s[i-1] == '0')
                sOnes.push_back({i, i});
            else
                sOnes.back().ss++;
        }

        if(t[i] == '1')
        {
            if(i == 0 || t[i-1] == '0')
                tOnes.push_back({i, i});
            else
                tOnes.back().ss++;
        }
    }

    ans = 0;
    for(i = 0; i < sOnes.size(); i++)    
        ans += abs(sOnes[i].ff - tOnes[i].ff) + abs(sOnes[i].ss - tOnes[i].ss);
    
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}