#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

pair<pair<ll, ll>, pair<ll, ll> > s[4];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, j;
    for(i = 0; i < 4; i++)
        cin >> s[i].ff.ff >> s[i].ff.ss >> s[i].ss.ff >> s[i].ss.ss;

    for(i = 0; i < 4; i++)
    {
        for(j = i+1; j < 4; j++)
        {
            if(s[i].ss == s[j].ff)
            {
                swap(s[i+1], s[j]);
                break;
            }

            swap(s[j].ff, s[j].ss);

            if(s[i].ss == s[j].ff)
            {
                swap(s[i+1], s[j]);
                break;
            }
        }
    }

    ll area = 0;
    for(i = 0; i < 4; i++)
    {
        if(s[i].ff.ff != s[i].ss.ff && s[i].ff.ss != s[i].ss.ss)
        {            
            cout << " NO";
            return 0;
        }

        if(s[i].ss != s[(i+1)%4].ff)
        {
            cout << "NO";
            return 0;
        }

        area += s[i].ff.ff*s[(i+1)%4].ff.ss - s[i].ff.ss*s[(i+1)%4].ff.ff;
    }

    if(area)
        cout << "YES";
    else
        cout << "NO";
}