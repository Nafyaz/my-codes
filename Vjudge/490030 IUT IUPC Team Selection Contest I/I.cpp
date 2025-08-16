#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, m, n;

    cin >> T;

    while(T--)
    {
        cin >> m >> n;

        if(m == 1 && n == 0)
            cout << "1\n";
        else if(m == 1)
            cout << "2\n";
        else if(n)
            cout << (1LL << m) - 1 << "\n";
        else
            cout << (1LL << m) << "\n";
    }
}
