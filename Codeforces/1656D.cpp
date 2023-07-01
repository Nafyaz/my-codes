#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, k1, k2, p;

    cin >> t;

    while(t--)
    {
        cin >> n;

        if((n&(n-1)) == 0)
        {
            cout << "-1\n";
            continue;
        }

        p = __builtin_ctzll(n);
        k1 = (1LL << (p+1));
        k2 = n/(k1/2);

        if(k2 >= k1 + 1)
            cout << k1 << "\n";
        else
            cout << k2 << "\n";
    }
}
