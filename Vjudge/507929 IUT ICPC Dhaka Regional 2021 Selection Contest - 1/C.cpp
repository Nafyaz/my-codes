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
    string s;
    int i, left, right;

    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
            left = i;
        if(s[i] == ')')
            right = s.size() - i - 1;
    }

//    show(left);
//    show(right);
//    cout << "\n";

    cout << (left == right? "correct\n" : "fix\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
