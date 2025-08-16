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
#define MAXN 1000006

LL freq[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, x, cnt, ans;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }

    ans = 1;
    for(int i = 1; i < MAXN; i++)
    {
        cnt = 0;
        for(int j = i; j < MAXN; j += i)
            cnt += freq[j];

        if(cnt > 1)
            ans = i;
    }

    cout << ans << "\n";
}