#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll x[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, total, low, high, cnt[3] = {0}, ans[3], mnSame, same;

    cin >> n;

    low = INT_MAX;
    high = INT_MIN;
    for(i = 0; i < n; i++)
    {
        cin >> x[i];
        low = min(low, x[i]);
        high = max(high, x[i]);
    }

    if(high - low <= 1)
    {
        cout << n << "\n";
        for(i = 0; i < n; i++)
            cout << x[i] << " ";
        cout << "\n";

        return 0;
    }
    
    total = 0;
    for(i = 0; i < n; i++)
    {
        x[i] -= low;
        cnt[x[i]]++;
        total += x[i];
    }

    mnSame = INT_MAX;
    for(i = 0; i <= n; i++)
    {
        if(total < 2*i || total - 2*i > n-i)
            continue;
        
        same = min(cnt[0], n - i - (total - 2*i)) + min(cnt[1], (total - 2*i)) + min(cnt[2], i);

        if(same < mnSame)
        {
            mnSame = same;
            ans[0] = n - i - (total - 2*i);
            ans[1] = total - 2*i;
            ans[2] = i;
        }
    }

    cout << mnSame << "\n";
    for(i = 0; i < ans[0]; i++)
        cout << low << " ";
    for(i = 0; i < ans[1]; i++)
        cout << low + 1 << " ";
    for(i = 0; i < ans[2]; i++)
        cout << low + 2 << " ";
}