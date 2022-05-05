#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll n;
double a[100005], pref[100005], avg;
vector<pair<ll, ll>> v;

double call(ll i)
{
    ll j;
    double ret = 0;

    if(i == n+1)
    {        
        avg = 0;
        for(j = 0; j < v.size(); j++)
        {
            // cout << v[j].first << " " << v[j].second << "; ";
            ret += (pref[v[j].ss] - pref[v[j].ff-1])/(v[j].ss - v[j].ff + 1);
        }

        // cout << "\n";
        // cout << "ret: " << ret/v.size() << "\n";

        return ret/v.size();
    }

    for(j = i; j <= n; j++)
    {
        v.push_back({i, j});
        ret = max(ret, call(j+1));
        v.pop_back();
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i, temp, k;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        sort(a+1, a+n+1);

        for(i = 1; i <= n; i++)
            pref[i] = pref[i-1] + a[i];

        // cout << "pref: " << "\n";
        // for(i = 1; i <= n; i++)
        //     cout << pref[i] << " ";
        // cout << "\n";

        cout << fixed << setprecision(7) << call(1) << "\n";
    }
}