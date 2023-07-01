#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

bool isRBS(string s)
{
    int i, opening = 0;

    for(i = 0; i < s.size(); i++)
    {
        opening += (s[i] == '('? 1 : -1);

        if(opening < 0)
            return 0;
    }

    return (opening == 0);
}

void solve(int caseno)
{
    int i, n, opening, closing, temp;
    string s, t;
    vector<int> questions;

    cin >> s;
    n = s.size();

    opening = closing = n/2;
    for(i = 0; i < n; i++)
    {
        opening -= (s[i] == '(');
        closing -= (s[i] == ')');

        if(s[i] == '?')
            questions.push_back(i);
    }

    if(opening == 0 || closing == 0)
    {
        cout << "YES\n";
        return;
    }

    temp = opening;

    for(i = 0; i < n; i++)
    {
        if(s[i] != '?')
            t.push_back(s[i]);
        else if(opening)
        {
            t.push_back('(');
            opening--;
        }
        else
        {
            t.push_back(')');
            closing--;
        }
    }

    swap(t[questions[temp-1]], t[questions[temp]]);

    if(isRBS(t))
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}