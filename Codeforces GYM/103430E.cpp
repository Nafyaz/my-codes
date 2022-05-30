#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

void solve()
{
    ll i, t[33], n;
    ll a, b, c, d, address, parent;
    char ch;
    bool flag;

    for(i = 0; i < 33; i++)
        cin >> t[i];

    cin >> n;

    map<pair<ll, ll>, ll> mp;
    while(n--)
    {
        cin >> a >> ch >> b >> ch >> c >> ch >> d;
        
        address = a*(1LL << 24) + b*(1LL << 16) + c*(1LL << 8) + d;
        // cout << address << endl;

        flag = 1;
        for(i = 0; i < 33; i++)
        {
            parent = ((address >> i) << i);
            if(mp.find({parent, i}) == mp.end())
                mp[{parent, i}] = t[32-i];

            if(mp[{parent, i}] == 0)
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            cout << "a\n";
            for(i = 0; i < 33; i++)
            {
                parent = ((address >> i) << i);
                mp[{parent, i}]--;
            }
        }
        else
            cout << "b\n";
    }
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