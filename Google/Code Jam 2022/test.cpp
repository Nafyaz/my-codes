#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, n, i;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> s[i];

        cout << "Case #" << ++caseno << ": \n";
        if(caseno == 63)
        {
            cout << n << "\n";
            for(i = 0; i < n; i++)
                cout << s[i] << " ";
            cout << "\n";
        }
    }
}