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

void solve(int caseno)
{
    int n, k, i;

    cin >> n >> k;

    if(k%4 == 0)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    
    if(k%4 == 2)
    {
    
        for(i = 1; i <= n; i += 2)
        {
            if(i%4 == 1)
                cout << i+1 << " " << i << "\n";
            else
                cout << i << " " << i+1 << "\n";
        }

        return;
    }


    for(i = 1; i <= n; i += 2)    
        cout << i << " " << i+1 << "\n";
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