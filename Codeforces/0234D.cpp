#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006

set<int> fav;
pair<pii, int> movies[102];
int ans[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, i, j, k, a, b, d, mx, mn;
    string s;

    cin >> m >> k;

    for(i = 0; i < k; i++)
    {
        cin >> a;
        fav.insert(a);
    }

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> s >> d;

        movies[i].ff.ff = movies[i].ff.ss = 0;
        movies[i].ss = i;
        for(j = 0; j < d; j++)
        {
            cin >> b;

            if(b == 0)
                movies[i].ff.ff++;
            else if(fav.find(b) != fav.end())
            {
                movies[i].ff.ff++;
                movies[i].ff.ss++;
            }
        }
    }

    if(n == 1)
    {
        cout << "0\n";
        return 0;
    }

    sort(movies, movies+n, greater<pair<pii, int>>());

    for(i = 0; i < n; i++)
    {
        cout << movies[i].ss << ": " << movies[i].ff.ff << " " << movies[i].ff.ss << "\n";
    }

    mx = movies[0].ff.ff;
    mn = movies[0].ff.ss;

    if(mx == mn)
    {
        for(i = 0; i < n && movies[i].ff.ff == movies[i].ff.ss; i++)        
            ans[movies[i].ss] = 0;
        for(; i < n && movies[i].ff.ff >= mn; i++)
            ans[movies[i].ss] = 1;
        for(; i < n; i++)
            ans[movies[i].ss] = 2;
    }
    else
    {
        if(movies[1].ff.ff <= mn)
        {
            ans[movies[0].ss] = 0;
            for(i = 1; i < n && movies[i].ff.ff >= mn; i++)
                ans[movies[i].ss] = 1;
            for(; i < n; i++)
                ans[movies[i].ss] = 2;
        }
        else
        {
            ans[movies[0].ss] = 1;
            for(i = 1; i < n && movies[i].ff.ff >= mn; i++)
                ans[movies[i].ss] = 1;
            for(; i < n; i++)
                ans[movies[i].ss] = 2;
        }
    }

    for(i = 0; i < n; i++)
        cout << ans[i] << "\n";
}