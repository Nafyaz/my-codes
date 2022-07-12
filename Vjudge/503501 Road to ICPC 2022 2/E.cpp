#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 1000006

int LPS[MAXN], n;
string s;

void KMP()
{
    int i, j;
    n = s.length();

    LPS[0]=0;

    for (i = 1; i < n; i++)
    {
        j = LPS[i-1];

        while (j > 0 && s[i] != s[j])
            j = LPS[j-1];

        if (s[i] == s[j])
            j++;

        LPS[i] = j;
    }
}


void solve(int caseno)
{
    KMP();

    cout << n / (n-LPS[n-1]) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(1)
    {
        cin >> s;

        if(s == ".")
            break;

        solve(++caseno);
    }
}