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

map<LL, LL> freq;

LL nCr(LL n, LL r)
{
    LL i, j = 1, ret = 1;
    for(i = n; i >= n-r+1; i--)
    {
        ret *= i;

        if(j <= r && ret%j == 0)
        {
            ret /= j;
            j++;
        }
    }
    return ret;
}

LL call(LL pos, LL rem)
{
    // show(pos);
    // show(rem) << "\n";

    if(rem == 0)
        return 2;
    if(pos == 11)
        return 0;

    LL i, ret;

    ret = call(pos+1, rem);
    for(i = 1; i <= freq[pos] && i*pos <= rem; i++)
        ret += call(pos+1, rem-i*pos) * nCr(freq[pos], i);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, ans, cnt, mul, sum, mask;
    string s;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> s;

        if('0' <= s[0] && s[0] <= '9')
            freq[s[0] - '0'] ++;
        else if(s == "T")
            freq[10]++;
        else if(s == "A")
            freq[1]++;
        else if(s == "J")
            freq[11]++;
        else if(s == "Q")
            freq[12]++;
        else if(s == "K")
            freq[13]++;
    }

    ans = 0;
    for(i = 1; i <= 13; i++)
        ans += (freq[i]*(freq[i]-1));

    // show(ans);

    cnt = 0;
    mul = 1;
    for(i = 1; i <= 14; i++)
    {
        if(!freq[i])
        {
            if(cnt >= 3)
                ans += cnt*mul;
            cnt = 0;
            mul = 1;
            continue;
        }

        cnt++;
        mul *= freq[i];
    }

    // show(ans);

    freq[10] += freq[11] + freq[12] + freq[13];

    ans += call(1, 15);

    // show(ans) << "\n";

    cout << ans << "\n";
}