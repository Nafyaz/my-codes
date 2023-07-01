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
    int i, j;
    bool hasDecreased;
    string s;

    cin >> s;

    cout << s[0];
    hasDecreased = 0;
    for(i = 1; i < s.size(); i++)
    {
        if(s[i-1] > s[i])
            hasDecreased = 1;

        if(hasDecreased && s[i-1] < s[i])
        {
            for(j = i; j < s.size(); j++)
                cout << s[i-1];
            cout << "\n";
            return;
        }

        cout << s[i];
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

