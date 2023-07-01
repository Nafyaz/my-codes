#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

pii p[12];

double getDist(int a, int b, int c, int d)
{
    double ret = sqrt((p[a].ff - p[b].ff)*(p[a].ff - p[b].ff) + (p[a].ss - p[b].ss)*(p[a].ss - p[b].ss));
    ret += sqrt((p[b].ff - p[c].ff)*(p[b].ff - p[c].ff) + (p[b].ss - p[c].ss)*(p[b].ss - p[c].ss));
    ret += sqrt((p[c].ff - p[d].ff)*(p[c].ff - p[d].ff) + (p[c].ss - p[d].ss)*(p[c].ss - p[d].ss));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c, d, i, ans[4];
    double mx, dist;

    cin >> n >> m;

    p[0] = {0, 0};
    p[1] = {0, min(1, m)};
    p[2] = {min(1, n), 0};

    p[3] = {0, m};
    p[4] = {0, max(0, m-1)};
    p[5] = {min(1, n), m};

    p[6] = {n, m};
    p[7] = {max(0, n-1), m};
    p[8] = {n, max(0, m-1)};

    p[9] = {n, 0};
    p[10] = {max(0, n-1), 0};
    p[11] = {n, min(1, m)};

    mx = 0;
    for(a = 0; a < 12; a++)
    {
        for(b = 0; b < 12; b++)
        {
            if(p[b] == p[a])
                continue;
            for(c = 0; c < 12; c++)
            {
                if(p[c] == p[a] || p[c] == p[b])
                    continue;
                for(d = 0; d < 12; d++)
                {
                    if(p[d] == p[a] || p[d] == p[b] || p[d] == p[c])
                        continue;

                    dist = getDist(a, b, c, d);
                    if(dist > mx)
                    {
                        mx = dist;
                        // show(mx);
                        ans[0] = a;
                        ans[1] = b;
                        ans[2] = c;
                        ans[3] = d;
                    }
                }
            }
        }
    }

    for(i = 0; i < 4; i++)
        cout << p[ans[i]].ff << " " << p[ans[i]].ss << "\n";
}