#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, a, odd, even, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        odd = even = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;

            if(a&1)
                odd++;
            else
                even++;
        }

        ans = n-1;

        if(odd%2 == 0)
            ans = min(ans, odd/2);

        if(odd)
            ans = min(ans, even);

        cout << ans << "\n";
    }
}
