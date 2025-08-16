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

int n, l, k;
int p[202], c[202];
unordered_map<int, double> dp[202][202];

double call(int pos, int win, int prize, int bags)
{
    if(pos == n)
    {
        // show(pos);
        // show(win);
        // show(prize);
        // show(bags);
        // cout << "\n";
        // show(n);
        // show(l);
        // show(k);
        // cout << "\n";

        if(win < l || prize > bags + k)
            return 0;
        else
            return 1;
    }

    if(dp[pos][win].find(prize - bags) != dp[pos][win].end())
        return dp[pos][win][prize - bags];

    double ret = (100 - p[pos])/100.0 * call(pos+1, win, prize, bags);

    if(c[pos] == -1)
        ret += p[pos]/100.0 * call(pos+1, win+1, prize + 1, bags);
    else
        ret += p[pos]/100.0 * call(pos+1, win+1, prize, min(200, bags + c[pos]));

    return dp[pos][win][prize - bags] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i;

    cin >> n >> l >> k;

    for(i = 0; i < n; i++)
        cin >> p[i];

    for(i = 0; i < n; i++)
        cin >> c[i];

    cout << fixed << setprecision(12) << call(0, 0, 0, 0) << "\n";
}