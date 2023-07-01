#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

ll arr[MAXN];

ll call(ll bg, ll ed)
{
    while(bg <= ed && arr[bg] == -1)
        bg++;
    while(bg <= ed && arr[ed] == -1)
        ed--;

    if(bg > ed)
        return 0;

    ll i, temp, correct, mid, ret;

    mid = (bg + ed) / 2;

    cout << "? " << bg << " " << mid << "\n";    

    vector<ll> v;
    for(i = 0; i < mid - bg + 1; i++)
    {
        cin >> temp;
        if(bg <= temp && temp <= mid)
            v.push_back(temp);
        else
            arr[temp] = -1;
    }

    correct = v.size();
    for(auto u : v)
    {
        if(arr[u] == -1)
            correct--;
    }
    for(i = bg; i <= mid; i++)
    {
        if(find(v.begin(), v.end(), i) == v.end())
            arr[i] = -1;
    }

    if(correct % 2 == 0)
    {
        return call(mid+1, ed);
    }
    else if(correct == 1)
    {
        for(auto u : v)
        {
            if(arr[u] != -1)
                return u;
        }
    }

    return call(bg, mid);
}

void solve(ll caseno)
{
    ll n, i, ans;

    cin >> n;

    for(i = 1; i <= n; i++)
        arr[i] = i;

    ans = call(1, n);

    cout << "! " << ans << "\n";
}

int main()
{
    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}