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

        if(x < y)
            cout << "FIRST\n";
        else if(y < x)
            cout << "SECOND\n";
        else
            cout << "ANY\n";
    }
}
