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

map<char, LL> f1, f2;

void solve(int caseno)
{
    LL i, check1, check2;
    string s;
    map<char, LL> freq;

    getline(cin, s);

    for(i = 0; i < s.size(); i++)
        freq[s[i]]++;

    check1 = check2 = 1;
    for(auto [c, cnt] : f1)
    {
        if(freq[c] < cnt)
            check1 = 0;
    }
    for(auto [c, cnt] : f2)
    {
        if(freq[c] < cnt)
            check2 = 0;
    }

    cout << "Case " << caseno << ": ";

    if(check1 && check2)
        cout << "BOTH\n";
    else if(check1)
        cout << "SELISE\n";
    else if(check2)
        cout << "SELISE Digital Platforms\n";
    else
        cout << "NONE\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;
    string s, s1 = "SELISE", s2 = "SELISE Digital Platforms";

    for(LL i = 0; i < s1.size(); i++)
        f1[s1[i]]++;
    for(LL i = 0 ;i < s2.size(); i++)
        f2[s2[i]]++;

    cin >> T;
    getline(cin, s);

    while(T--)
    {
        solve(++caseno);
    }
}