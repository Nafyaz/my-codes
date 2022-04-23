#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, flag;
    string s[2][21];

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> s[0][i];
        for(i = 0; i < n; i++)
            cin >> s[1][i];

        flag = 1;
        for(i = 0; i < n && flag; i++)
        {
            if(s[0][i].back() <= '2' && s[1][i].back() <= '2')
                flag = 0;
            if(s[0][i].back() >= '3' && s[1][i].back() >= '3')
                flag = 0;
        }

        if(s[0][n-1].back() <= '2')
            flag = 0;

        cout << (flag? "YES\n" : "NO\n");
    }
}
