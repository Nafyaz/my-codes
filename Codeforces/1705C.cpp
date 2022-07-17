#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "

ll l[42], r[42];
ll bg[42];

void solve()
{
    ll n, c, q, i, k, pos, last;
    string s;

    cin >> n >> c >> q;
    cin >> s;

    last = n;
    for(i = 0; i < c; i++)
    {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
        bg[i] = last;
        last = last + r[i] - l[i] + 1;
    }

    while(q--)
    {
        cin >> k;
        k--;

        while(k >= n)
        {
            pos = upper_bound(bg, bg+c, k) - bg - 1;

//            show(k);
//            show(pos);
//            cout << "\n";

            k = k - bg[pos] + l[pos];
        }

        cout << s[k] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, caseno = 0;

    cin >> t;

    while(t--)
    {
        solve();
    }
}
