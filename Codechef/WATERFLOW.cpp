#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, w, x, y, z;

    cin >> T;

    while(T--)
    {
        cin >> w >> x >> y >> z;

        if(w + y*z > x)
            cout << "overflow\n";
        else if(w + y*z == x)
            cout << "filled\n";
        else
            cout << "unfilled\n";
    }
}