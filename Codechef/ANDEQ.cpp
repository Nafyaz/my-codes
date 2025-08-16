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
        
        same = 0;
        for(bit = 1; bit < INT_MAX; bit *= 2)
        {
            cnt = 0;
            for(i = 0; i < n; i++)
                cnt += ((a[i] & bit) != 0);

            if(cnt == n)
                same += bit;
        }

        v.clear();
        for(i = 0; i < n; i++)
        {
            if(i == 0 || v.back() == same)
                v.push_back(a[i]);
            else
                v.back() &= a[i];

            // cout << "v: ";
            // for(auto u : v)
            //     cout << u << " ";
            // cout << "\n";
        }

        if(v.back() != same)
            cout << n - v.size() + 1 << "\n";
        else
            cout << n - v.size() << "\n";
    }
}