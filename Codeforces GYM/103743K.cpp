#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1300

ll calc(ll n)
{
    ll sum = 0;

    while(n > (1LL << sum) - 1)
        sum++;
    
    return sum-1;
}

void solve(ll caseno)
{
    ll n, i, temp;

    cin >> n;

    vector<ll> v;

    while(n > 1)
    {
        // show(n);
        temp = calc(n);
        v.push_back(temp);
        n -= (1LL << temp) - 1;
    }
    if(n)
        v.push_back(1);
    v.push_back(0);

    cout << "nunhehhe";
    for(i = 0; i+1 < v.size(); i++)
    {
        cout << "h";
        while(v[i] > v[i+1])
        {
            cout << "a";
            v[i]--;
        }
    }
    cout << "\n";
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