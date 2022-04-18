#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, ans;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n >> s;

        if(s.find('1') == -1)
        {
            cout << "0\n";
            continue;
        }

        ans = 1;
        for(i = 1; i < n; i++)
        {
            if(s[i-1] == '1' && s[i] == '1')
                ans = 2;
        }

        cout << ans << "\n";
    }
}
