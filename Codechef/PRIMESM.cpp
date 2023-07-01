#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, a, b;

    cin >> T;

    while(T--)
    {
        cin >> a >> b;

        if(a == 1 || b == 1)
            cout << "-1\n";
        else if(__gcd(a, b) > 1)
            cout << "0\n";
        else
            cout << "1\n";
    }
}
