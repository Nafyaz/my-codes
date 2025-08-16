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
#define MAXN 1003

struct target
{
    LL x, y, t;
    double p;

    target() {}

    target(LL x, LL y, LL t, double p) : x(x), y(y), t(t), p(p) {}

    bool operator<(target T)
    {
        return t < T.t;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, j, x, y, t, cnt;
    double p, ans[MAXN], mx;
    target T[MAXN];

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x >> y >> t >> p;

        T[i] = target(x, y, t, p);
    }

    sort(T, T+n);
    
    mx = 0;
    for(i = 0; i < n; i++)
    {
        ans[i] = T[i].p;
        for(j = 0; j < i; j++)
        {
            if((T[i].x - T[j].x)*(T[i].x - T[j].x) + (T[i].y - T[j].y)*(T[i].y - T[j].y) <= (T[i].t - T[j].t)*(T[i].t - T[j].t))
                ans[i] = max(ans[i], ans[j] + T[i].p);
        }
        mx = max(mx, ans[i]);
    }

    cout << fixed << setprecision(10) << mx << "\n";
}