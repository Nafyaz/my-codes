#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    ll T, n, m, i, j;
    string s, a, ans;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;
        cin >> s >> a;

        ans = "";

        i = 0;
        j = 0;
        while(i < n)
        {
            if(j == m)
            {
                ans = "-1";
                break;
            }

            if(s[i] == a[j])
            {
                ans.push_back(s[i]);
                i++;
                j++;
            }
            else if(s[i] == '?')
            {
                if(a[j] == 'a')
                    ans.push_back('b');
                else
                    ans.push_back('a');

                i++;
            }
            else
            {
                ans.push_back(s[i]);
                i++;
            }
        }

        if(j == m)
            ans = "-1";

        cout << ans << "\n";
    }
}
