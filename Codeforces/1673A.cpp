#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll T, i, score;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> s;

        score =0;
        for(i = 0;i < s.size(); i++)
            score += (s[i] - 'a' + 1);

        if(s.size() == 1)
            cout << "Bob " << score << "\n";
        else if(s.size() % 2 == 0)
            cout << "Alice " << score << "\n";
        else
            cout << "Alice " << score - min(2*(s[0]-'a'+1), 2*(s.back() - 'a' + 1)) << "\n";
    }
}