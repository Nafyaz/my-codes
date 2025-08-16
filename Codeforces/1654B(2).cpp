#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, i, x;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> s;

        set<char> st;

        for(i = s.size()-1; i >= 0; i--)
        {
            if(st.find(s[i]) == st.end())
                x = i;
            st.insert(s[i]);
        }

        cout << s.substr(x) << "\n";
    }
}
