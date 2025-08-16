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
    int n, m, i;

    cin >> n >> m;

    if(m < n)
    {
        cout << "No\n";
        return;
    }

    if(n%2 == 0)
    {
        if(m%2 == 0)
        {
            cout << "Yes\n";
            for(i = 0; i < n-2; i++)
            {
                cout << "1 ";
                m--;
            }
            cout << m/2 << " " << m/2 << "\n";
        }
        else
            cout << "No\n";
    }
    else
    {
        cout << "Yes\n"; 
        for(i = 0; i < n-1; i++)
        {
            cout << "1 ";
            m--;
        }
        cout << m << "\n";
    }
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