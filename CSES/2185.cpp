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

LL n, a[25];
LL mulmod(LL a, LL b)
{
    LL ret = 0;
    while(b)
    {
        if(a > n)
            return -1;
        if(b&1)
            ret += a;
        if(ret > n)
            return -1;
        a += a;
        b /= 2;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL k, i, bit, cnt, mul, ans;

    cin >> n >> k;
    for(i = 0; i < k; i++)
        cin >> a[i];

    ans = 0;
    for(bit = 1; bit < (1 << k); bit++)
    {
        cnt = 0;
        mul = 1;
        for(i = 0; i < k; i++)
        {
            if(bit & (1<<i))
            {
                cnt++;
                mul = mulmod(mul, a[i]);
                if(mul == -1)
                    break;
            }
        }

        if(mul != -1)
        {
            if(cnt%2)
                ans += n/mul;
            else
                ans -= n/mul;
        }
    }

    cout << ans << "\n";
}