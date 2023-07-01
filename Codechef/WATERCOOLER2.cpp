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
        cout << (y-1)/x << "\n";
    }
}
