#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

LL a[MAXN], b[MAXN];

void solve(int caseno)
{
    LL n, i, sumA, sumB, ans;

    cin >> n;

    sumA = sumB = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        sumA += a[i];
    }
    for(i = 0; i < n; i++)
    {
        cin >> b[i];
        sumB += b[i];
    }
    
    if(sumA != sumB)
    {
        cout << "-1\n";
        return;
    }

    ans = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i] > b[i])
            ans += a[i] - b[i];
    }

    cout << ans << "\n";
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