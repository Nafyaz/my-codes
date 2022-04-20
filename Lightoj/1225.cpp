#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0;
    string x, y;

    cin >> T;

    while(T--)
    {
        cin >> x;
        y = x;

        reverse(y.begin(), y.end());

        cout << "Case " << ++caseno << ": " << (x==y? "Yes\n" : "No\n");
    }
}
