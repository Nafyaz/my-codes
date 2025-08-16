#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, k, a, b, mn, mx, i;
    char chA = 'G', chB = 'B';

    cin >> n >> k >> a >> b;

    if(a > b)
    {
        swap(a, b);
        swap(chA, chB);
    }

    if((b+k-1)/k - 1 > a)
    {
        cout << "NO\n";
        return;
    }

    while(a || b)
    {
        // cout << a << " " << b << "\n";
        for(i = 0; i < k && a < b; i++)
        {
            cout << chB;
            b--;
        }

        if(a)
        {
            cout << chA;
            a--;
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll T;

    T = 1;

    while(T--)
    {
        solve();
    }
}