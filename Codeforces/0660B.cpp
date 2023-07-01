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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, m, i, j;
    pair<pLL, pLL> rows;

    cin >> n >> m;


    for(i = 0; i < n; i++)
    {
        rows.ff.ff = rows.ff.ss = rows.ss.ff = rows.ss.ss = -1;

        if(2*i+1 <= m)
            rows.ff.ff = 2*i+1;
        if(2*n + 2*i+1 <= m)
            rows.ff.ss = 2*n + 2*i+1;
        if(2*n + 2*i+2 <= m)
            rows.ss.ff = 2*n + 2*i+2;
        if(2*i+2 <= m)
            rows.ss.ss = 2*i+2;

        if(rows.ff.ss != -1)
            cout << rows.ff.ss << " ";
        if(rows.ff.ff != -1)
            cout << rows.ff.ff << " ";
        if(rows.ss.ff != -1)
            cout << rows.ss.ff << " ";
        if(rows.ss.ss != -1)
            cout << rows.ss.ss << " ";
    }
}