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

    int i;
    string s, t, ans;

    cin >> s;

    ans = "0";
    for(mask = 1; mask < (1 << 9); mask++)
    {
        t = call(mask);
        if(t != "" && isSmall(t, ans))
            ans = t;
    }

    cout << ans;
}