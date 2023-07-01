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

LL conv(LL n)
{
    string s = iota(n), ret;

    for(LL i = 0; i < s.size(); i++)
    {
        if(s[i] == '0')
            ret.push_back('4');
        else
            ret.push_back('7');
    }

    return atoi(s);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL i;
    vector<LL> lucky;
    lucky.push_back(0);
    for(i = 0; i < (1 << 10); i++)
        lucky.push_back(conv(i));

    LL pL, pR, vL, vR, k;

    cin >> pL >> pR >> vL >> vR;
    cin >> k;

    for(i = 1; i + k-1 < v.size(); i++)
    {
        
    }
}