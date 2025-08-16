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

bool isPrime(LL x)
{
    for(LL i = 2; i*i <= x; i++)
    {
        if(x%i == 0)
            return 0;
    }

    return 1;
}

void solve(int caseno)
{
    LL x, d, dCnt;

    cin >> x >> d;

    y = x;

    for(dCnt = 0; y%d == 0; dCnt++)
        y /= d;

    show(x);
    show(y);
    show(dCnt) << "\n";

    if(dCnt == 1)
    {
        cout << "NO\n";
        return;
    }

    if(!isPrime(y))
    {
        cout << "YES\n";
        return;
    }
    
    if(d == 1 || isPrime(d))
    {
        cout << "NO\n";
        return;
    }

    if(dCnt == 2)
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