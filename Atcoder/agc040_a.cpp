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
#define MAXN 500005

LL nxt[MAXN], a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL i, sum;
    string s;

    cin >> s;

    for(i = s.size()-1; i >= 0; i--)
    {
        if(s[i] == '>')
            a[i] = a[i+1] + 1;
    }

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == '<')
            a[i+1] = max(a[i+1], a[i] + 1);
    }

    sum = 0;
    for(i = 0; i <= s.size(); i++)
    {
        // cout << a[i] << " ";
        sum += a[i];
    }

    cout << sum << "\n";
}