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

    LL n, p, q, i, j;
    string s;

    cin >> n >> p >> q;
    cin >> s;

    for(i = 0; p*i <= n; i++)
    {
        if((n - p*i)%q == 0)
        {
            cout << i + (n-p*i)/q << "\n";
            for(j = 0; j < p*i; j++)
            {
                cout << s[j];

                if((j+1)%p == 0)
                    cout << "\n";
            }

            for(j = p*i; j < n; j++)
            {
                cout << s[j];

                if((j+1 - p*i)%q == 0)
                    cout << "\n";
            }
            return 0;
        }
    }

    cout << "-1\n";
}