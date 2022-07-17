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
    vector<ll> sOnes, tOnes;
    string s, t, s2, t2;

    cin >> n >> s >> t;

    if(s[0] != t[0] || s.back() != t.back())
    {
        cout << "-1\n";
        return;
    }

    for(i = 1; i < n; i++)
    {
        s2.push_back((s[i-1] - '0')^(s[i] - '0') + '0');
        t2.push_back((t[i-1] - '0')^(t[i] - '0') + '0');
    }

    for(i = 0; i+1 < n; i++)
    {
        if(s2[i] == '1')
            sOnes.push_back(i);
        if(t2[i] == '1')
            tOnes.push_back(i);
    }

    if(sOnes.size() != tOnes.size())
    {
        cout << "-1\n";
        return;
    }

    ans = 0;
    for(i = 0; i < sOnes.size(); i++)    
        ans += abs(sOnes[i] - tOnes[i]);
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