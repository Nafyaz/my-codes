#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

void solve()
{
    ll n, i, j;
    vector<pair<ll, ll>> v(100);

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> v[i].ff;
    for(i = 0; i < n; i++)
        cin >> v[i].ss;

    vector<pair<ll, ll>> ans;
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(v[i] > v[j])
            {
                swap(v[i], v[j]);
                ans.push_back({i+1, j+1});
            }
        }
    }

    bool flag = 1;
    for(i = 1; i < n; i++)
    {
        if(v[i-1].ss > v[i].ss)
            flag = 0;
    }

    if(!flag)
    {
        cout << "-1\n";
        return;
    }

    cout << ans.size() << "\n";
    for(auto u : ans)
        cout << u.ff << " " << u.ss << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}