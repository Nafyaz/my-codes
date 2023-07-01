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

vector<double> p(300);

vector<double> Unite(vector<double> a, vector<double> b)
{
    LL i, j;
    vector<double> ret(a.size(), 0);
    for(i = 0; i < 128; i++)
    {
        for(j = 0; j < 128; j++)
            ret[i^j] += a[i]*b[j];
    }

    return ret;
}

vector<double> expo(LL n)
{
    if(n == 1)
        return p;

    vector<double> ret = expo(n/2);
    ret = Unite(ret, ret);

    if(n%2)
        ret = Unite(ret, p);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, x, i;

    cin >> n >> x;

    for(i = 0; i <= x; i++)
        cin >> p[i];

    cout << fixed << setprecision(8) << 1 - expo(n)[0] << '\n';
}