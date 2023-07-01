#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "

string mul(string x, char u)
{
    reverse(x.begin(), x.end());
    string ret = "";
    ll rem = 0;

    for(ll i = 0; i < x.length(); i++)
    {
        rem = rem + (x[i] - '0') * (u - '0');
        ret.push_back('0' + (rem%10));
        rem /= 10;
    }

    while(rem)
    {
        ret.push_back('0' + (rem%10));
        rem /= 10; 
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

void solve()
{
    ll n, len, step;
    string x, val, newVal;

    cin >> n >> x;

    len = x.size();

    if(n == len)
    {
        cout << "0\n";
        return;
    }
    
    queue<string> q;
    map<string, ll> mp;

    q.push(x);
    mp[x] = 0;

    while(!q.empty())
    {
        val = q.front();
        q.pop();

        if(val.size() == n)
        {
            cout << mp[val] << "\n";
            return;
        }

        if(val.size() > n)
            break;

        for(auto u : val)        
        {
            newVal = mul(val, u);

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