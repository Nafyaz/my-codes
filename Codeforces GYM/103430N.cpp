#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll i, j, n[3], v, y;
    string s;

    bool ans = 1;

    cin >> n[0] >> n[1] >> n[2];

    getline(cin, s);

    for(i = 0; i < 3; i++)
    {
        getline(cin, s);

        v = y = 0;

        for(j = 0; j < s.size(); j++)
        {
            s[j] = tolower(s[j]);

            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                v++;
            if(s[j] == 'y')
                y++;
        }

        // cout << "s: " << s << "\n";
        // cout << "v: " << v << "; y: " << y << endl;

        if((i == 0 || i == 2) && (v > 5 || v+y < 5))        
            ans = 0;
        else if(i == 1 && (v > 7 || v+y < 7))
            ans = 0;
    }

    cout << (ans? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}