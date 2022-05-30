#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "

ll a[200005];

void solve()
{
    ll l, r, i, bit, cntA, cnt, x;

    cin >> l >> r;

    for(i = 0; i <= r; i++)
        cin >> a[i];

    x = 0;
    for(bit = 1; bit < (1LL << 17); bit *= 2)
    {
        cntA = cnt = 0;
        for(i = 0; i <= r; i++)
        {
            cntA += ((a[i] & bit) != 0);
            cnt += ((i & bit) != 0);
        }

        if(cnt != cntA)
            x += bit;

        // show(bit);
        // show(cnt);
        // show(cntA);
        // cout << "\n";
    }

    cout << x << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}
