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

        if(a+1 == b)
            cout << "-1\n";
        else if(__gcd(a, a+2) > 1)
            cout << a << " " << a+2 << "\n";
        else if(a+2 == b)
            cout << "-1\n";
        else if(__gcd(a, a+3) > 1)
            cout << a << " " << a+3 << "\n";
        else
            cout << a+1 << " " << a+3 << "\n";
    }
}
