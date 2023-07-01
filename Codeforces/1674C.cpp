#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll q;
    string s, t;

    cin >> q;

    while(q--)
    {
        cin >> s >> t;

        if(t.find('a') != -1)
        {
            if(t.size() == 1)
                cout << "1\n";
            else
                cout << "-1\n";
        }
        else
            cout << (1LL << s.size()) << "\n";

    }
}