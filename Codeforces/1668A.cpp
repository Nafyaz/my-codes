#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, m;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;

        if(n == 1 || m == 1)
        {
            if(n == 1 && m == 1)
                cout << "0\n";
            else if(n == 2 || m == 2)
                cout << "1\n";
            else
                cout << "-1\n";
            continue;
        }

        if(n > m)
            swap(n, m);

        cout << 2*(n-1) + (m-n)/2*4 + (m-n)%2 << "\n";
    }
}
