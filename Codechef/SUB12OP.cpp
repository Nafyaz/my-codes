#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

LL arr[MAXN];

void solve(int caseno)
{
    LL n, i, ans, move;

    cin >> n;

    for(i = 0; i < n; i++)    
        cin >> arr[i];
    
    for(i = n-1; i > 0; i--)
    {
        if(arr[i] > 0)        
            move = arr[i]/2;        
        else
            move = 0;

        arr[i-1] -= move;
        arr[i] -= 2*move;
    }

    for(i = n-1; i > 0; i--)
    {
        if(arr[i-1] > 0 && arr[i] == 1)
        {
            arr[i-1] --;
            arr[i] -= 2;
        }
    }

    ans = 0;
    for(i = 0; i < n; i++)
        ans += abs(arr[i]);

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