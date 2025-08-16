#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, a, b;

    cin >> T;

    while(T--)
    {
        cin >> n >> a >> b;

        if(a > b)
            swap(a, b);

        if(b-a == 1)
        {
            if(a > 1 && b < n)
                cout << "2\n";
            else if(a > 1 || b < n)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if(b - a == 2)
            cout << "1\n";
        else
            cout << "0\n";
    }
}
