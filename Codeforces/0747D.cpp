#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

ll t[MAXN];

ll call(multiset<ll> ms, ll k, ll change)
{
    while(!ms.empty())
    {
        if(k >= (*ms.begin()))
        {
            k -= (*ms.begin());
            change -= 2;
        }

        ms.erase(ms.begin());
    }

    return change;
}

void solve(ll caseno)
{
    ll n, k, i, change, prev, neg, pos, ans;

    cin >> n >> k;

    neg = 0;
    for(i = 0; i < n; i++)    
    {
        cin >> t[i];
        t[i] = (t[i] >= 0);
        neg += (t[i] ^ 1);
    }    

    if(neg > k)
    {
        cout << "-1\n";
        return;
    }

    k -= neg;

    multiset<ll> ms;
    pos = change = 0;
    prev = 1;
    for(i = 0; i < n; i++)
    {
        if(t[i] && change)
            pos++;
        else if(pos != 0)
        {
            ms.insert(pos);
            pos = 0;
        }

        if(t[i] != prev)
            change++;

        prev = t[i];
    }

    ans = INT_MAX;
    if(pos > 0 && pos <= k)
    {   
        ans = min(ans, call(ms, k-pos, change-1));
    }

    ans = min(ans, call(ms, k, change));

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}