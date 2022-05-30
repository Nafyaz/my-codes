#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "

void solve()
{
    ll n, len, step;
    ll x, val, newVal;
    string valStr;

    cin >> n >> x;
    
    queue<ll> q;
    map<ll, ll> mp;

    q.push(x);
    mp[x] = 0;

    while(!q.empty())
    {
        val = q.front();
        valStr = to_string(val);
        q.pop();

        if(valStr.size() == n)
        {
            cout << mp[val] << "\n";
            return;
        }

        if(valStr.size() > n)
            break;

        for(auto u : valStr)        
        {
            newVal = val * (u - '0');

            if(mp.find(newVal) == mp.end())
            {
                q.push(newVal);        
                mp[newVal] = mp[val] + 1;
            }
        }
    }

    cout << "-1\n";
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