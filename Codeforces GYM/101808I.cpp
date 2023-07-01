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

map<pLL, LL> dp;

bool call(LL full, LL rest)
{
    if
}

void solve(int caseno)
{
    LL n, i, mn, total;

    cin >> n;

    mn = INF;
    total = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];

        mn = min(mn, a[i]);
        total += a[i];
    }   

    dp.clear();
    
    if(call(mn, total - mn*n))
        cout <<< "Yalalov\n";
    else
        cout << "Shin\n";
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