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

void solve(int caseno)
{
    int i;
    string s;
    char c;
    bool isBig = 0;

    cin >> s;
    c = s[0];

    for(i = 0; i+1 < s.size(); i++)
    {
        if(s[i] > s[i+1])
        {
            isBig = 1;
            break;
        }
        else if(s[i] < s[i+1])
            break;
    }

    if(isBig || i+1 == s.size())
        cout << string(s.size(), c) << "\n";
    else
        cout << string(s.size(), c+1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}