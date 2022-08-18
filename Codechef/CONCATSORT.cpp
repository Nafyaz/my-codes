#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005


void solve(int caseno)
{
    int n, i, arr, prevLast;
    bool allPrev;
    map<int, vector<int>> pos;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> arr;

        pos[arr].push_back(i);
    }

    vector<pll> P, Q;

    prevLast = -1;
    allPrev = 1;
    for(auto [u, v] : pos)
    {
        // cout << u << ": ";
        // for(auto w : v)
        //     cout << w << " ";
        // cout << "\n";

        if(allPrev == 0)
        {
            for(auto w : v)
                Q.push_back({u, w});
            continue;
        }

        for(auto w : v)
        {
            if(w > prevLast)
            {
                P.push_back({u, w});
                prevLast = w;
            }
            else
            {
                Q.push_back({u, w});
                allPrev = 0;
            }
        }
    }

    // for(auto u : P)
    //     cout << u.ff << " " << u.ss << "; ";
    // cout << "\n";
    // for(auto u : Q)
    //     cout << u.ff << " " << u.ss << "; ";
    // cout << "\n";

    for(i = 1; i < P.size(); i++)
    {
        if(P[i-1].ss > P[i].ss)
        {
            cout << "NO\n";
            return;
        }
    }

    // if(!P.empty() && !Q.empty() && P.back().ss > Q[0].ss)
    // {
    //     cout << "NO\n";
    //     return;
    // }

    for(i = 1; i < Q.size(); i++)
    {
        if(Q[i-1].ss > Q[i].ss)
        {
            cout << "NO\n";
            return;
        }
    }


    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
