#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, j, ans, div1, div2, div1Cnt, div2Cnt;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);

    ans = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 1; j*j <= a[i]; j++)
        {
            if(a[i] % j == 0)
            {
                div1 = j;
                div2 = a[i] / j;

                div1Cnt = upper_bound(a, a+n, div1) - lower_bound(a, a+n, div1);
                div2Cnt = upper_bound(a, a+n, div2) - lower_bound(a, a+n, div2);

                if(div1 == div2)                
                    ans += div1Cnt * div1Cnt;
                else
                    ans += 2 * div1Cnt * div2Cnt;
            }
        }

        // cout << ans << "\n";
    }

    cout << ans;
}