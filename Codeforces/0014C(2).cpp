//follow kzvd4729
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x1, y1, x2, y2, i, xParallel = 0, yParallel = 0;
    bool flag = 1;

    map<pair<ll, ll>, ll> mp;

    for(i = 0; i < 4; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        
        if(x1 == x2 && y1 == y2)
            flag = 0;
        else if(x1 == x2)
            yParallel++;
        else if(y1 == y2)
            xParallel++;
        else
            flag = 0;

        mp[{x1, y1}] ++;
        mp[{x2, y2}] ++;
    }

    if(xParallel != 2 || yParallel != 2)
        flag = 0;

    if(mp.size() != 4)
        flag = 0;
    
    for(auto u : mp)
    {
        if(u.second != 2)
            flag = 0;
    }

    cout << (flag? "YES\n" : "NO\n");
}