#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    ll i;
    bool up = 0, low = 0;
    set<char> st;

    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        up |= isupper(s[i]);
        low |= islower(s[i]);

        st.insert(s[i]);
    }

    cout << ((up && low && st.size() == s.size())? "Yes" : "No");
}