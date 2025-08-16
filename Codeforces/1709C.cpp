#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int i, n, opening, closing, oTemp, cTemp;
    string s;

    cin >> s;
    n = s.size();

    opening = closing = n/2;
    for(i = 0; i < n; i++)
    {
        if(s[i] == '(')
            opening--;
        else if(s[i] == ')')
            closing--;
    }

    oTemp = opening;
    cTemp = closing;

    if(oTemp == 0 || cTemp == 0)
    {
        cout << "YES\n";
        return;
    }

    int fixedOpening = 0;
    for(i = 0; i < n; i++)
    {
        if(s[i] == '(')
            fixedOpening++;
        else if(s[i] == ')')
            fixedOpening--;
        else if(fixedOpening == 0)
        {
            fixedOpening++;
            oTemp--;
        }

        if(oTemp == 0 || cTemp == 0)
        {
            cout << "YES\n";
            return;
        }
    }

    oTemp = opening;
    cTemp = closing;
    int fixedClosing = 0;
    for(i = n-1; i >= 0; i--)
    {
        if(s[i] == ')')
            fixedClosing++;
        else if(s[i] == '(')
            fixedClosing--;
        else if(fixedClosing == 0)
        {
            fixedClosing++;
            cTemp--;
        }

        if(oTemp == 0 || cTemp == 0)
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

/*
7
(?))
??????
()
??
?(?)()?)
(?))??
(?))((?)
*/
/*
YES
NO
YES
YES
NO
YES
YES
*/
