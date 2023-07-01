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

double dp[1003][1003];

double call(LL w, LL b, LL turn)
{
    if(w == 0 && b == 0)
        return 0;

    if(dp[w][b] >= 0)
        return dp[w][b];
    
    double pW, pB, &ret = dp[w][b];

    ret = 0;

    pW = 1.0*w/(w + b);
    pB = 1.0*b/(w + b);
    
    if(turn == 0)
        ret += pW;

    if(b > 0)
    {
        b--;

        if(turn == 1)
        {
            if(w > 0)
                ret += pB*w/(w+b)*call(w-1, b, !turn);

            if(b > 0)
                ret += pB*b/(w+b)*call(w, b-1, !turn);
        }
        else
            ret += pB*call(w, b, !turn);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL w, b;

    cin >> w >> b;

    memset(dp, -1, sizeof dp);
    cout << fixed << setprecision(9) << call(w, b, 0) << "\n";
}