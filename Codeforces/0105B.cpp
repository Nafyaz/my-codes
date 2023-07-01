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

int n, k, a;
int sLevel[10], sLoyalty[10];
bool vis[10][10][10][300];
double dp[10][10][10][300];

double call(int pos, int voted, int rem, int mask)
{
    int i, b;
    if(pos == n)
    {
        if(2*voted > n)
            return 1;
        
        b = 0;
        for(i = 0; i < n; i++)
        {
            if(mask&(1 << i))            
                b += sLevel[i];            
        }

        return double(a)/(a+b);
    }

    if(vis[pos][voted][rem][mask])
        return dp[pos][voted][rem][mask];

    vis[pos][voted][rem][mask] = 1;

    double ret = 0, val;

    for(i = 0; i <= rem; i++)
    {
        val = (min(sLoyalty[pos] + 10*i, 100)/100.0 * call(pos+1, voted+1, rem - i, mask));
        val +=  (100 - min(sLoyalty[pos] + 10*i, 100))/100.0 * call(pos+1, voted, rem - i, mask | (1<<pos));

        ret = max(ret, val);
    }

    return dp[pos][voted][rem][mask] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i;

    cin >> n >> k >> a;

    for(i = 0; i < n; i++)
    {
        cin >> sLevel[i] >> sLoyalty[i];
    }

    cout << fixed << setprecision(10) <<  call(0, 0, k, 0) << "\n";
}