#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define leftest -1000000009

ll l[200005];
ll r[200005];

ll prefL[200005];
ll prefR[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll  n, i, dist, ans, x, left, right, cnt;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> l[i] >> r[i];

    sort(l+1, l+n+1);
    sort(r+1, r+n+1);

    for(i = 1; i <= n; i++)
    {
        dist = l[i] - leftest;
        prefL[i] = prefL[i-1] + dist;

        dist = r[i] - leftest;
        prefR[i] = prefR[i-1] + dist;
    }

    ans = LLONG_MAX;
    for(i = 1; i <= n; i++)
    {
        x = l[i];
        cnt = lower_bound(r+1, r+n+1, x) -r-1;
        left = cnt*(x - leftest) - prefR[cnt];

        cnt = upper_bound(l+1, l+n+1, x) -l-1;
        right = prefL[n]-prefL[cnt-1] - (n-cnt)*(x-leftest);

        ans = min(ans, left + right);
    }

    cout << ans;
}
