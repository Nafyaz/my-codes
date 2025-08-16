#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 2000006

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    LL i, k, op1, op2;
    bool changedLast, changedFirst;

    cin >> s >> k;

    op1 = changedLast = 0;
    for(i = 0; i+1 < s.size(); i++)
    {
        if(s[i] == s[i+1])
        {
            op1 += k;
            i++;

            if(i+1 == s.size())
                changedLast = 1;
        }
    }

    if(!changedLast && s[0] == s.back())
        op1 += k-1;

    op2 = changedFirst = 0;
    for(i = 0; i+1 < s.size(); i++)
    {
        if(s[i] == s[i+1])
        {
            op2 += k;

            if(i == 0)
                changedFirst = 1;

            i++;
        }
    }

    if(!changedFirst && s[0] == s.back())
        op2 += k-1;

    cout << min(op1, op2) << "\n";
}