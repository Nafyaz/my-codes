#include<bits/stdc++.h>
using namespace std;

bool check(string s, char c)
{
    int i;
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] != c)
            return 0;
    }

    return 1;
}

string apply(string s, char c)
{
    string ret;
    int i;

    for(i = 0; i+1 < s.size(); i++)
    {
        if(s[i] == c || s[i+1] == c)
            ret.push_back(c);
        else
            ret.push_back(s[i]);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int i, j, ans, cnt;
    string s, t;

//    s = "serval";
//    cout << apply(s, 'v');

    cin >> s;

    ans = s.size();
    for(char c = 'a'; c <= 'z'; c++)
    {
        t = s;
        cnt = 0;
        while(t.size() > 1)
        {
            if(check(t, c))
                break;

            cnt++;

            t = apply(t, c);
        }

        ans = min(ans, cnt);
    }

    cout << ans << "\n";
}
