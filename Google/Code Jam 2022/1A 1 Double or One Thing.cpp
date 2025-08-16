#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, i, cnt;
    string s;
    char prev;

    cin >> T;

    while(T--)
    {
        cin >> s;

        cout << "Case #" << ++caseno << ": ";

        prev = '.';
        cnt = 0;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == prev)
            {
                cout << s[i];
                cnt++;
                continue;
            }

            if(s[i] > prev)
            {
                while(cnt)
                {
                    cnt--;
                    cout << prev;
                }
            }

            cout << s[i];
            cnt = 1;
            prev = s[i];
        }

        cout << "\n";
    }
}
