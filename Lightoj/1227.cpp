#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, n, p, q, w, i, ans, sum;

    cin >> T;

    while(T--)
    {
        cin >> n >> p >> q;

        ans = sum = 0;
        for(i = 0; i < n; i++)
        {
            cin >> w;

            if(ans < p && sum + w <= q)
            {
                ans++;
                sum += w;
            }
        }

        cout << "Case " << ++caseno << ": " << ans << "\n";
    }
}
