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
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    LL len1, len2;

    for(LL i = 2; i <= 26; i++)
    {
        cout << "? 1 " << i << "\n";
        cin >> len1;
        if(len1 == -1)
        {
            cout << "! " << i-1 << "\n";
            return 0;
        }

        cout << "? " << i << " " << 1 << "\n";
        cin >> len2;

        if(len1 != len2)
        {
            cout << "! " << len1 + len2 << "\n";
            return 0;
        }
    }
}