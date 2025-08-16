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

map<string, int> freq;

void solve(int caseno)
{
    int n, i;
    string s;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> s;

        if(freq.find(s) == freq.end())
            cout << s << "\n";
        else
            cout << s << "(" << freq[s] << ")\n";

        freq[s]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
