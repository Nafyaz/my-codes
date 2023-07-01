#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, caseno = 0;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;

        cout << "Case " << ++caseno << ": ";

        if(s.substr(0, 5) == "http:")
            cout << s.substr(0, 4) << "s" << s.substr(4) << "\n";
        else
            cout << s << "\n";
    }
}
