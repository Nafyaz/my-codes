#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
typedef long double LD;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 100005
#define PI acos(-1)

pair<LD, int> points[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j, x, y;
    LD mnAng, ang;
    pii ans;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x >> y;
        points[i].ff = atan2(LD(y), LD(x));
        points[i].ss = i+1;
    }
    
    sort(points, points + n);

    mnAng = 2*PI;
    for(i = 0; i < n; i++)
    {
        j = (i+1)%n;

        ang = points[j].ff - points[i].ff;
        if(ang < 0)
            ang += 2*PI;

        if(ang < mnAng)
        {
            mnAng = ang;
            ans.ff = points[i].ss;
            ans.ss = points[j].ss;
        }
    }

    cout << ans.ff << " " << ans.ss << "\n";
}