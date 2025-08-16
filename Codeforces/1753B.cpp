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
#define MAXN 500005

int freq[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, x, i, a;

    cin >> n >> x;

    for(i = 0; i < n; i++)
    {
        cin >> a;

        freq[a]++;
    }

    for(i = 1; i < x; i++)
    {
        freq[i+1] += freq[i] / (i+1);
        // show(i);
        // show(freq[i]) << "\n";

        if(freq[i] % (i+1))
        {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}