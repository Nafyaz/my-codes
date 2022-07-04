#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1003

pair<string, string> kills[MAXN];
map<string, vector<string>> mp;

void solve(ll caseno)
{
    ll n, i;
    string a, b, nowKilling;
    bool ans;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> kills[i].ff >> kills[i].ss;
        mp[kills[i].ff].push_back(kills[i].ss);
    }

    ans = 0;
    for(auto u : mp)
    {
        map<string, ll> mp2;
        for(i = 0; i <  u.ss.size(); i++)
        {
            mp2[u.ss[i]]++;
            if(i >= 5)
            {
                mp2[u.ss[i-5]]--;
                if(mp2[u.ss[i-5]] == 0)
                    mp2.erase(u.ss[i-5]);
            }

            if(mp2.size() == 5)
                ans = 1;
        }
    }

    cout << (ans? "PENTA KILL!\n" : "SAD:(\n");
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