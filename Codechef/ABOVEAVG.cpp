#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, m, x, i, total;

    cin >> T;

    while(T--)
    {
        cin >> n >> m >> x;

        total = n*x;

        if(m == x)
            cout << "0\n";
        else
            cout << total / (x+1) << "\n";
    }
}