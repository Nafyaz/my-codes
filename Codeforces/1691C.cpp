#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007

ll f(string s)
{
    ll i, ret = 0;
    for(i = 0; i+1 < s.size(); i++)    
        ret += 10*(s[i] - '0') + (s[i+1] - '0');
    
    return ret;
}

void solve(ll caseno)
{
    ll n, k, i, first, last;
    string s;

    cin >> n >> k >> s;

    first = last = -1;
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
        {
            if(first == -1)
                first = i;
            last = i;
        }
    }

    if(first == -1 && last == -1)
        cout << "0\n";
    else if(first == last)
    {
        if(k >= n-last-1)
            cout << "1\n";
        else if(k >= first)
            cout << "10\n";
        else
            cout << "11\n";
    }
    else
    {
        if(k >= n-last-1)
        {
            swap(s[last], s[n-1]);
            k -= n-last-1;
        }

        if(k >= first)
        {
            swap(s[0], s[first]);
            k -= first;
        }

        cout << f(s) << "\n";
    }    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}