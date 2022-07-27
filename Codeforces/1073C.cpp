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
    int n, i, x, y;
    int U, D, L, R;
    vector<int> uPos, dPos, lPos, rPos;
    string s;

    cin >> n >> s >> x >> y;

    if(abs(x) + abs(y) < n)
    {
        cout << "-1\n";
        return;
    }

    U = D = L = R = 0;
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == 'U')
        {
            U++;
            uPos.push_back(i);
        }

        if(s[i] == 'D')
        {
            D++;
            dPos.push_back(i);
        }
        if(s[i] == 'L')
        {
            L++;
            lPos.push_back(i);
        }
        if(s[i] == 'R')
        {
            R++;
            rPos.push_back(i);
        }
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
