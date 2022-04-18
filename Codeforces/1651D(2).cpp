#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, j, x, y, xNew, yNew, dist;

    ll dx[4] = {1, 0, -1, 0};
    ll dy[4] = {0, 1, 0, -1};

    map<pll, ll> given;
    queue<pll> q;

    map<pll, ll> bestDist;
    map<pll, pll> bestPoint;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> x >> y;
        given[{x, y}] = i;
        bestDist[{x, y}] = INT_MAX;
    }

//    cout << "Given Points:\n";
//    for(auto u : given)
//        cout << u.ff.ff << " " << u.ff.ss << "; " << u.ss << "\n";
//    cout << "\n";

//    cout << "bestDist:\n";
//    for(auto u : bestDist)
//        cout << u.ff.ff << " " << u.ff.ss << "; " << u.ss << "\n";
//    cout << "\n";

    for(auto u : given)
    {
        for(j = 0; j < 4; j++)
        {
            xNew = u.ff.ff + dx[j];
            yNew = u.ff.ss + dy[j];

            if(given.find({xNew, yNew}) == given.end())
            {
                q.push({xNew, yNew});
                bestDist[{xNew, yNew}] = 0;
                bestPoint[{xNew, yNew}] = {xNew, yNew};
            }
        }
    }

//    cout << "bestDist:\n";
//    for(auto u : bestDist)
//        cout << u.ff.ff << " " << u.ff.ss << "; " << u.ss << "\n";
//    cout << "\n";

//    cout << "bestPoint:\n";
//    for(auto u : bestPoint)
//        cout << u.ff.ff << " " << u.ff.ss << "; " << u.ss.ff << " " << u.ss.ss << "\n";
//    cout << "\n";

//    cout << "queue: " << q.fff << " " << q.ss << "\n";

    while(!q.empty())
    {
        x = q.front().ff;
        y = q.front().ss;
        dist = bestDist[{x, y}];

        q.pop();

        for(j = 0; j < 4; j++)
        {
            xNew = x + dx[j];
            yNew = y + dy[j];

            if(given.find({xNew, yNew}) == given.end())
                continue;

            if(bestDist[{xNew, yNew}] > dist + 1)
            {
                bestDist[{xNew, yNew}] = dist + 1;
                bestPoint[{xNew, yNew}] = bestPoint[{x, y}];
                q.push({xNew, yNew});
            }
        }
    }

    vector<pll> ans(n);
    for(auto u : given)
        ans[u.ss] = bestPoint[u.ff];

    for(auto u : ans)
        cout << u.ff << " " << u.ss << "\n";
}
