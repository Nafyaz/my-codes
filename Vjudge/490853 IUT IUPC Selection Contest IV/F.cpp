#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, k, i, oddCount, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> k;

        ans = 0;
        for(i = 0; ; i++, n /= 2)
        {
            oddCount = (n+1)/2;

            if(!oddCount)
                break;

            if(i <= k)
                ans += oddCount * oddCount;
            else
                ans += (1LL << (i-k)) * oddCount * oddCount;
        }

        cout << ans << "\n";
    }
}
