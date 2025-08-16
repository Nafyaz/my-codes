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

void solve(int caseno)
{
    string a, b;
    int i, j, len, ans;

    cin >> a >> b;

    len = a.size();

    ans = 0;
    for(i = 0, j = len-1; i <= j; i++, j--)
    {
        if(a[i] == a[j] && b[i] == b[j])
        {
            if(a[i] == b[i])
                continue;
            
            cout << "-1\n";
            return;
        }

        if(a[i] == b[i] && a[j] == b[j])
        {
            if(ans%2 == 1)
                ans++;
            continue;
        }

        if(a[i] == b[j] && a[j] == b[i])
        {
            if(ans%2 == 0)
                ans++;
            continue;
        }

        cout << "-1\n";
        return;
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