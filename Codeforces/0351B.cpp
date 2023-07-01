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
#define MAXN 3003

LL n, p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, j, inv;

    cin >> n;

    inv = 0;
    for(i = 0; i < n; i++)
    {
        cin >> p[i];
        for(j = 0; j < i; j++)
        {
            if(p[i] < p[j])
                inv++;
        }
    }

    cout << inv/2*4 + (inv&1) << "\n";
}