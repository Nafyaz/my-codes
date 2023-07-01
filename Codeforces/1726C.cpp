#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000005

int leader[3][MAXN];

int Find(int cnt, int x)
{
    if(leader[cnt][x] == x)
        return x;

    return leader[cnt][x] = Find(cnt, leader[cnt][x]);
}

void Union(int cnt, int x, int y)
{
    x = Find(cnt, x);
    y = Find(cnt, y);

    if(x == y)
        return;

    if(cnt == 1)
        leader[cnt][max(x, y)] = min(x, y);
    else
        leader[cnt][min(x, y)] = max(x, y);
}

void solve(int caseno)
{
    int n, i, ans;
    string s;

    cin >> n >> s;
    s = '#' + s + '#';
    
    for(i = 0; i <= 2*n+1; i++)
    {
        leader[0][i] = i;
        leader[1][i] = i;
        leader[2][i] = i;
    }

    for(i = 1; i <= 2*n; i++)
    {
        if(s[i] == '(' && s[i+1] == ')')
        {
            Union(0, i, i+2);
            Union(1, i-1, i+1);
        }
    }

    for(i = 2*n; i >= 1; i--)
    {
        if(s[i] == '(' && s[Find(0, i+1)] == ')')        
            Union(0, i, Find(0, i+1) + 1);
    }

    for(i = 1; i <= 2*n; i++)
    {
        if(s[i] == ')' && s[Find(1, i-1)] == '(')
            Union(1, i, Find(1, i-1) - 1);
    }

    for(i = 1; i <= 2*n; i++)
    {
        if(Find(0, i) != i)
            Union(2, i, Find(0, i) - 1);
        
        if(Find(1, i) != i)
            Union(2, i, Find(1, i) + 1);
    }

    ans = 0;
    for(i = 1; i <= 2*n; i += 1)
    {
        ans += (Find(2, i) == i);
        // show(i);
        // show(Find(0, i));
        // show(Find(1, i));
        // show(Find(2, i));
        // cout << "\n";
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}