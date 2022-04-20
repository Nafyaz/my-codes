#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    map<string, ll> mp;
    string country, name;

    cin >> n;

    while(n--)
    {
        cin >> country;
        getline(cin, name);

        mp[country]++;
    }

    for(auto u : mp)
        cout << u.first << " " << u.second << "\n";
}
