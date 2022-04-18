#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);

    ll i;
    string s;

    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] < '0' || s[i] > '9')
            cout << s[i];
    }
}
