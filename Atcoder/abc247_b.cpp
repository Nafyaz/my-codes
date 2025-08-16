#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, flag;
    map<string, ll> freq;
    pair<string, string> names[102];

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> names[i].ff >> names[i].ss;

        freq[names[i].ff]++;
        if(names[i].ff != names[i].ss)
            freq[names[i].ss]++;
    }

    flag = 1;
    for(i = 0; i < n; i++)
    {
        if(freq[names[i].ff] > 1 && freq[names[i].ss] > 1)
            flag = 0;
    }

    cout << (flag? "Yes" : "No");
}
