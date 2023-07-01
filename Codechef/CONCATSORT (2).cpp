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

pll arr[MAXN];

void solve(int caseno)
{
    ll n, i, flag;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> arr[i].ff;
        arr[i].ss = i;
    }

    sort(arr, arr+n);

    vector<pll> P, Q;
    flag = 0;
    for(i = 0; i < n; i++)
    {
        if(P.empty() || (flag == 0 && P.back().ss < arr[i].ss))
            P.push_back(arr[i]);
        else
        {
            Q.push_back(arr[i]);
            flag = 1;
        }
    }

    for(i = 1; i < Q.size(); i++)
    {
        if(Q[i-1].ss > Q[i].ss)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

    // cout << "P: ";
    // for(auto u : P)
    //     cout << u.ff << " ";
    // cout << "\n";
    // cout << "Q: ";
    // for(auto u : Q)
    //     cout << u.ff << " ";
    // cout << "\n";

    // if(Q.empty() || P.back().ff <= Q[0].ff)
    //     cout << "YES\n";
    // else
    //     cout << "NO\n";
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