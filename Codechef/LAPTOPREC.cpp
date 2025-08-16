#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, mx, a;

    cin >> T;

    while (T--)
    {
        cin >> n;

        map<ll, ll> freq;

        for(i = 0; i < n; i++)
        {
            cin >> a;
            freq[a]++;
        }

        mx = 0;
        vector<ll> ans;

        for(auto u : freq)
        {
            if(u.second > mx)
            {
                ans.clear();
                ans.push_back(u.first);
                mx = u.second;
            }
            else if(u.second == mx)
            {
                ans.push_back(u.first);
            }
        }

        if(ans.size() == 1)
            cout << ans[0] << "\n";
        else
            cout << "CONFUSED\n";
    }
}