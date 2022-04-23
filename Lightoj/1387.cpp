#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, n, amount, sum;
    string op;

    cin >> T;

    while(T--)
    {
        cin >> n;

        cout << "Case " << ++caseno << ":\n";

        sum = 0;

        while(n--)
        {
            cin >> op;
            if(op == "donate")
            {
                cin >> amount;
                sum += amount;
            }
            else
                cout << sum << "\n";
        }
    }
}
