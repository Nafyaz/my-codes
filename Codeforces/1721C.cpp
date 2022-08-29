#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

LL a[MAXN], b[MAXN];
LL pos[MAXN], mx[MAXN];

void solve(int caseno)
{
    LL n, i, last;
    bool flag;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++)
        cin >> b[i];

    for(i = 0; i < n; i++)
    {
        pos[i] = lower_bound(b, b+n, a[i]) - b;

        cout << b[pos[i]] - a[i] << " ";
    }
    cout << "\n";

    // cout << "pos: ";
    // for(i = 0; i < n; i++)
    //     cout << pos[i] << " ";
    // cout << "\n";

    flag = 0;
    for(i = n-1; i >= 0; i--)
    {
        if(flag)
            mx[i] = b[last] - a[i];
        else
            mx[i] = b[i] - a[i];

        if(i == pos[i])
            flag = 0;
        if(flag == 0 && i != pos[i])
        {
            flag = 1;
            last = i;
        }

        // show(i);
        // show(last);
        // cout << "\n";
    }

    for(i = 0; i < n; i++)
        cout << mx[i] << " ";
    cout << "\n";
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