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

string grid[3];
LL grundy[102][102];

bool check(LL i, LL j)
{
    return (grid[j][i] == 'O' && grid[j][i+1] == 'O' && grid[j+1][i] == 'O' && grid[j+1][i+1] == 'O');
}

LL call(LL st, LL ed)
{
    // show(st);
    // show(ed) << "\n";

    if(ed - st + 1 <= 1)
        return grundy[st][ed] = 0;

    if(grundy[st][ed] != -1)
        return grundy[st][ed];

    LL i;
    set<LL> ST;

    for(i = st; i < ed; i++)
    {
        if(check(i, 0) || check(i, 1))
            ST.insert(call(st, i-1) ^ call(i+2, ed));
    }

    grundy[st][ed] = 0;
    for(auto u : ST)
    {
        if(grundy[st][ed] == u)
            grundy[st][ed]++;
        else
            break;
    }

    return grundy[st][ed];
}

void solve(int caseno)
{
    LL n, i;

    cin >> n;

    for(i = 0; i < 3; i++)
        cin >> grid[i];

    memset(grundy, -1, sizeof grundy);
    cout << "Case " << caseno << ": " << (call(0, n-1)? "Jhinuk\n" : "Grandma\n");
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}