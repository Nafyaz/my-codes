#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, a, z, o;

    cin >> T;

    while(T--)
    {
        cin >> n;

        z = o = 0;

        for(i = 0; i < n; i++)
        {
            cin >> a;

            z += (a == 0);
            o += (a == 1);
        }

        cout << (o >= z? "1" : "0") << "\n";
    }
}