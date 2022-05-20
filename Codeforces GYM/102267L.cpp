#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

void solve()
{
    ll i, aCnt = 0, bCnt = 0, T;
    vector<pair<ll, ll>> ans;
    string s, t;

    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        aCnt += (s[i] == 'a');
        bCnt += (s[i] == 'b');

        if(aCnt < bCnt)
        {
            cout << "-1";
            return;
        }
    }

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] != 'a')
        {
            cout << "-1";
            return;
        }

        if(i + 2 < s.size() && s.substr(i, 3) == "abc")
        {
            ans.push_back({1, 4});
            i += 2;
        }

        else if(i+2 < s.size() && (s.substr(i, 3) == "acb" || s.substr(i, 3) == "acc"))
        {
            ans.push_back({3, 2});
            ans.push_back({2, 2});
            ans.push_back({4, 1});
            s[i+1] = 'a';            
        }

        else if(i+1 < s.size())
        {
            t = s.substr(i, 2);
            if(t == "aa")
            {
                ans.push_back({1, 1});
                ans.push_back({2, 2});
                ans.push_back({4, 1});
            }
            else if(t == "ab")
            {
                ans.push_back({2, 2});
                ans.push_back({4, 1});
                i++;
            }
            else
            {
                ans.push_back({1, 1});
                ans.push_back({4, 1});
                i++;
            }
        }

        else
        {
            ans.push_back({1, 1});
            ans.push_back({2, 2});
            ans.push_back({4, 1});
        }
    }

    cout << ans.size() << "\n";
    for(auto u : ans)
    {
        cout << u.ff << " " << u.ss << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1;

    // cin >> T;

    while(T--)
    {
        solve();
    }
    
}