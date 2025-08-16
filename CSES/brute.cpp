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

    int T;
    string s, t, ans;

    cin >> T;

    while(T--)
    {
        cin >> s;

        ans = t = s;

        for(int i = 0; i < s.size(); i++)
        {
            rotate(t.begin(), t.begin() + 1, t.end());

            ans = min(ans, t);
        }

        cout << ans << "\n";
    }
}