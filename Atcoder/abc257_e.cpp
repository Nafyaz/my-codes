#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

string dp[MAXN];
string c[9];

bool isGE(string a, string b)
{
    if(a.size() != b.size())
        return (a.size() >= b.size());

    for(ll i = 0; i < a.size(); i++)
    {
        if(a[i] > b[i])
            return 1;
        else if(a[i] < b[i])
            return 0;
    }

    return 1;
}

string add(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string ret = "0";
    ll sum;
    for(ll i = 0; i < max(a.size(), b.size()); i++)
    {
        sum = 0;
        if(i < a.size())
            sum += a[i]- '0';
        if(i < b.size())
            sum += b[i] - '0';
        
        if(sum > 9)
        {
            ret.back() += sum - 10;
            ret.push_back('1');
        }
        else
        {
            ret.back() += sum;
            ret.push_back('0');
        }
    }

    if(ret.back() == '0')
        ret.pop_back();
    
    reverse(ret.begin(), ret.end());
    return ret;
}

string neg(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string ret = "0";
    ll carry = 0, x, y, val;
    for(ll i = 0; i < a.size(); i++)
    {
        x = a[i] - '0';
        if(i < b.size())
            y = carry + b[i] - '0';
        else
            y = carry;

        val = x - y;
        if(val < 0)
        {
            carry = 1;
            val += 10;
        }

        
    }
}

string call(ll n)
{
    if(n == 0)
        return "0";
    
    if(dp[n] != "")
        return dp[n];

    ll i;
    string ret = "0", val;
    for(i = 0; i < 9; i++)
    {
        if(isGE(n, c[i]))
        {
            val = call(neg(n, c[i]));
            val.push_back('0');
            val = add(val, c[i]);

            if(isGE(val, ret))
                ret = val;
        }
    }

    return dp[n] = ret;
}

void solve(ll caseno)
{
    ll n, i;

    cin >> n;

    for(i = 0; i < 9; i++)
        cin >> c[i];

    cout << call(n) << "\n";
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