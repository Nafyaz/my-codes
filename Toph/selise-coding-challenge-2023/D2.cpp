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

    LL i, n, ans;
    string s;

    while(cin >> s)
    {
        n = s.size();
        ans = 0;
        for(i = (n+1)/2; i < n; i++)
        {
            s[i] = (s[i] - 'a' + ans)%26 + 'a';
            if(s[i] <= s[n-i-1])
                ans += s[n-i-1] - s[i];
            else
                ans += 26 - s[i] + s[n-i-1];
        }

        cout << ans << "\n";
    }   
}