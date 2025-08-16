#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "

set<ll> getDigits(string x)
{
    set<ll> st;

    for(auto u : x)
        st.insert(u);

    return st;
}

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
    
    queue<pair<string, ll>> q;
    set<string> foundBefore;

    q.push({x, 0});
    foundBefore.insert(x);

    while(!q.empty())
    {
        val = q.front().ff;
        step = q.front().ss;
        q.pop();

        if(step > 50)
            break;

        if(val.size() == n)
        {
            cout << step;
            return;
        }

        set<ll> st = getDigits(val);
        for(auto u : st)        
        {
            newVal = mul(val, u);
            // show(val);
            // show(u);
            // show(newVal);
            // cout << "\n";

            if(foundBefore.find(newVal) == foundBefore.end())
            {
                q.push({newVal, step+1});        
                foundBefore.insert(newVal);
            }
        }
    }

    cout << -1;
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