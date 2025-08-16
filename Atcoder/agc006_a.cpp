#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j, k, ans;
    bool flag;
    string s, t;

    cin >> n >> s >> t;

    ans = 0;
    for(i = 1; i <= n; i++)
    {
        flag = 1;
        for(k = n-i, j = 0; j < i; k++, j++)
        {
            if(s[k] != t[j])
            {
                flag = 0;
                break;
            }
        }

        if(flag)
            ans = i;
    }

    cout << n+n-ans << "\n";
}