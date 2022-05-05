#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i, j, val;
    string s;
    map<string, ll> mp;

    val = 1;
    for(i = 0; i < 26; i++)
    {
        for(j = 0; j < 26; j++)
        {
            if(i != j)
            {
                s = "";
                s.push_back('a'+i);
                s.push_back('a'+j);

                mp[s] = val++;
            }
        }
    }

    cin >> T;

    while(T--)
    {
        cin >> s;
        cout << mp[s] << "\n";
    }
}