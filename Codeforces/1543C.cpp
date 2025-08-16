#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
typedef pair<double, double> pD;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006
#define EPS 1e-9

double v;
double call(double c, double m)
{
    // show(c);
    // show(m) << "\n";
    if(c < EPS && m < EPS)
        return 1;

    double mn, ret = 0;

    if(c > EPS)
    {
        mn = min(c, v);
        if(m > EPS)
            ret += c*(1 + call(c-mn, m+mn/2));
        else
            ret += c*(1 + call(c-mn, m));
    }

    if(m > EPS)
    {
        mn = min(m, v);
        if(c > EPS)
            ret += m*(1 + call(c+mn/2, m-mn));
        else
            ret += m*(1 + call(c, m-mn));
    }

    ret += 1-c-m;

    return ret;
}

void solve(int caseno)
{
    double c, m, p;

    cin >> c >> m >> p >> v;

    cout << fixed << setprecision(12) << call(c, m) << "\n";
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