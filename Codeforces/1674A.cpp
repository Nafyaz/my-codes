#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, x, y;

    cin >> T;

    while(T--)
    {
        cin >> x >> y;

        if(y%x != 0)
            cout << "0 0\n";
        else
            cout << "1 " << y/x << "\n";
    }
}