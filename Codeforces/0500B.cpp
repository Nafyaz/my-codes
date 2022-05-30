#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "

ll perm[302];
ll parent[302];
vector<ll> GroupsVal[302], GroupsIdx[302];

ll ans[302];

ll Find(ll x)
{
    if(parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(ll x, ll y)
{
    x = Find(x);
    y = Find(y);

    if(x == y)
        return;
    
    parent[max(x, y)] = min(x, y);
}

void solve()
{
    ll n, i, j;
    string s;
    cin >> n;
    // cout << "n: " << n << "\n";

    for(i = 0; i < n; i++)
    {
        cin >> perm[i];
        parent[i] = i;

        // show(i);
        // show(perm[i]);
        // cout << "\n";
    }

    for(i = 0; i < n; i++)
    {
        cin >> s;
        // cout << "s: " << s << "\n";
        for(j = 0; j < n; j++)
        {
            if(s[j] == '1')
                Union(i, j);
        }
    }

    for(i = 0; i < n; i++)
    {
        GroupsVal[Find(i)].push_back(perm[i]);
        GroupsIdx[Find(i)].push_back(i);
    }

    for(i = 0; i < n; i++)
    {
        sort(GroupsVal[i].begin(), GroupsVal[i].end());
        sort(GroupsIdx[i].begin(), GroupsIdx[i].end());

        for(j = 0; j < GroupsVal[i].size(); j++)        
            ans[GroupsIdx[i][j]] = GroupsVal[i][j];        
    }

    // cout << "ans:\n";
    for(i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    T = 1;

    while(T--)
    {
        solve();
    }
}