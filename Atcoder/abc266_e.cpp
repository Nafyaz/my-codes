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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j, cnt;
    double ans[102], sum;

    cin >> n;

    ans[1] = 3.5;
    for(i = 2; i <= n; i++)
    {
        sum = cnt = 0;

        for(j = 1; j <= 6; j++)
        {
            if(j > ans[i-1])
            {
                sum += j;
                cnt++;
            }
        }

        ans[i] = sum/6 + double(6-cnt)/6*ans[i-1];
    }

    cout << fixed << setprecision(10) <<  ans[n] << "\n";
}