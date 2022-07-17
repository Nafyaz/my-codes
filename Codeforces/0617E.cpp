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

ll n, sq;
ll arr[MAXN], pref[MAXN], ans[MAXN];
pair<pll, ll> query[MAXN];
unordered_map<ll, ll> freq;

bool cmp(pair<pll, ll> x, pair<pll, ll> y)
{
    if(x.ff.ff/sq != y.ff.ff/sq)
        return x.ff.ff < y.ff.ff;
    return x.ff.ss < y.ff.ss;
}

void solve(ll caseno)
{
    ll m, k, i, bg, ed, valid;

    cin >> n >> m >> k;
    sq = sqrt(n);

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pref[i] = pref[i-1] ^ arr[i];
    }

    for(i = 0; i < m; i++)
    {
        cin >> query[i].ff.ff >> query[i].ff.ss;
        query[i].ff.ff--;
        query[i].ss = i;
    }

    sort(query, query + m, cmp);

    valid = 0;
    freq[0] = 1;
    for(i = 0, bg = 0, ed = 0; i < m; i++)
    {
        while(ed < query[i].ff.ss)
        {
            ed++;
            valid += freq[pref[ed] ^ k];
            freq[pref[ed]]++;
        }

        while(bg > query[i].ff.ff)
        {
            bg--;
            valid += freq[pref[bg] ^ k];
            freq[pref[bg]]++;
        }

        while(bg < query[i].ff.ff)
        {
            freq[pref[bg]]--;
            valid -= freq[pref[bg] ^ k];
            bg++;
        }

        while(ed > query[i].ff.ss)
        {
            freq[pref[ed]]--;
            valid -= freq[pref[ed] ^ k];
            ed--;
        }
        
        ans[query[i].ss] = valid;
    }

    for(i = 0; i < m; i++)
        cout << ans[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}