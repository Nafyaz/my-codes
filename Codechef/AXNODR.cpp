#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        if(n%4 == 0)
            cout << n+3 << "\n";
        else if(n%4 == 1)
            cout << n << "\n";
        else
            cout << "3\n";
    }
}
