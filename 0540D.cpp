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

tuple<double, double, double> dp[102][102][102];
bool vis[102][102][102];

tuple<double, double, double> call(LL r, LL s, LL p)
{
    if(r < 0 || s < 0 || p < 0)
        return {0, 0, 0};
    if(r == 0 && s == 0)
        return {0, 0, 1};
    if(r == 0 && p == 0)
        return {0, 1, 0};
    if(s == 0 && p == 0)
        return {1, 0, 0};

    if(vis[r][s][p])
        return dp[r][s][p];

    double rP, sP, pP, tempR, tempS, tempP;
    LL denom = r*s + s*p + p*r;
    
    rP = sP = pP = 0;
    
    {
        auto [tempR, tempS, tempP] = call(r, s-1, p);
        rP += tempR * r * s / denom;
        sP += tempS * r * s / denom;
        pP += tempP * r * s / denom;
    }

    {
        auto [tempR, tempS, tempP] = call(r, s, p-1);
        rP += tempR * s * p / denom;
        sP += tempS * s * p / denom;
        pP += tempP * s * p / denom;
    }

    {

        auto [tempR, tempS, tempP] = call(r-1, s, p);
        rP += tempR * p * r / denom;
        sP += tempS * p * r / denom;
        pP += tempP * p * r / denom;
    }

    vis[r][s][p] = 1;
    return dp[r][s][p] = {rP, sP, pP};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL r, s, p;
    cin >> r >> s >> p;

    auto [rP, sP, pP] = call(r, s, p);

    cout << fixed << setprecision(12) << rP << " " << sP << " " << pP << "\n";
}