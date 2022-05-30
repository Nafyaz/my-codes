#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, a, b, i, mx, mn;

    cin >> n >> a >> b;

    vector<ll> v;

    for(i = n; i >= 1; i--)
    {
        if(v.size() + 1 == n/2)
            v.push_back(a);
        if(v.size() + 1 == n)
            v.push_back(b);

        if(i == a || i == b)
            continue;

        v.push_back(i);
    }

    if(v.size() + 1 == n/2)
        v.push_back(a);
    if(v.size() + 1 == n)
        v.push_back(b);

    // for(i = 0; i < n; i++)
    //     cout << v[i] << " ";
    // cout << "\n";

    mn = n+1;
    for(i = 0; i < n/2; i++)    
        mn = min(mn, v[i]);

    mx = 0;
    for(i = n/2; i < n; i++)
        mx = max(mx, v[i]);

    if(mn != a || mx != b)
        cout << "-1\n";
    else
    {
        for(i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << "\n";
    }
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