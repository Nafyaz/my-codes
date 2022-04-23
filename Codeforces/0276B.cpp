#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, oddCount = 0;
    string s;
    map<char, ll> mp;

    cin >> s;

    for(i = 0; i < s.size(); i++)
        mp[s[i]]++;

    for(auto u : mp)
        oddCount += (u.ss&1);

    cout << ((oddCount%2 == 1 || !oddCount)? "First" : "Second");
}
