#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

pll grades[MAXN];
vector<pair<pll, ll>> theory, pract, same;
ll ans[MAXN];

bool cmp(pair<pll, ll> a, pair<pll, ll> b)
{
    return abs(a.ff.ff - a.ff.ss) > abs(b.ff.ff - b.ff.ss);
}

void solve(ll caseno)
{
    ll n, a, b, total, i, j;

    cin >> n >> a >> b;

    for(i = 0; i < n; i++)    
        cin >> grades[i].ff;
    for(i = 0; i < n; i++)
        cin >> grades[i].ss;

    for(i = 0; i < n; i++)
    {
        if(grades[i].ff > grades[i].ss)
            theory.push_back({{grades[i].ff, grades[i].ss}, i});
        else if(grades[i].ff < grades[i].ss)
            pract.push_back({{grades[i].ff, grades[i].ss}, i});
        else
            same.push_back({{grades[i].ff, grades[i].ss}, i});
    }

    sort(theory.begin(), theory.end(), cmp);
    sort(pract.begin(), pract.end(), cmp);

    memset(ans, -1, sizeof ans);
    reverse(pract.begin(), pract.end());
    for(i = 0; i < a; i++)
    {
        if(i < theory.size())
            ans[theory[i].ss] = 0;
        else if(i < theory.size() + same.size())
            ans[same[i - theory.size()].ss] = 0;
        else
            ans[pract[i - theory.size() - same.size()].ss] = 0;
    }

    reverse(pract.begin(), pract.end());
    reverse(theory.begin(), theory.end());
    reverse(same.begin(), same.end());
    for(i = 0; i < b; i++)
    {
        if(i < pract.size())
            ans[pract[i].ss] = 1;
        else if(i < pract.size() + same.size())
            ans[same[i - pract.size()].ss] = 1;
        else
            ans[theory[i - pract.size() - same.size()].ss] = 1;
    }

    total = 0;
    for(i = 0; i < n; i++)
    {
        if(ans[i] == -1)
        {
            if(grades[i].ff > grades[i].ss)
                ans[i] = 0;
            else
                ans[i] = 1;
        }

        total += (ans[i]? grades[i].ss : grades[i].ff);
    }

    cout << total << "\n";
    for(i = 0; i < n; i++)    
        cout << (ans[i]? "P" : "T") << " ";
    cout << "\n";
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