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
    int p, q;
    string s;

    cin >> p >> q >> s;

    if(p > q)
        swap(p, q);

    if(s == "AABB")
    {
        if(q == 7)
            cout << "8 9\n";
        else
            cout << "-1\n";
    }
    else if(s == "ABAB")
    {
        if(p == 6 && q == 8)
            cout << "7 9\n";
        else
            cout << "-1\n";
    }
    else if(s == "ABBA")
    {
        if(q - p == 3)
            cout << p+1 << " " << p+2 << "\n";
        else
            cout << "-1\n";
    }
    else if(s == "BAAB")
    {
        if(p == 2 && q == 8)
            cout << "1 9\n";
        else
            cout << "-1\n";
    }
    else if(s == "BABA")
    {
        if(p == 2 && q == 4)
            cout << "1 3\n";
        else
            cout << "-1\n";
    }
    else if(s == "BBAA")
    {
        if(p == 3)
            cout << "1 2\n";
        else
            cout << "-1\n";
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
