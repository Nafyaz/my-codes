#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[1000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, bit, same, cnt;
    vector<ll> v;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)        
            cin >> a[i];
        
        same = INT_MAX;
        
        for(i = 0; i < n; i++)
            same &= a[i];


        v.clear();
        for(i = 0; i < n; i++)
        {
            if(i == 0 || v.back() == same)
                v.push_back(a[i]);
            else
                v.back() &= a[i];
        }

        if(v.back() != same)
            cout << n - v.size() + 1 << "\n";
        else
            cout << n - v.size() << "\n";
    }
}