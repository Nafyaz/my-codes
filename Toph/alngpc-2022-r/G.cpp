#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
const int MOD = 1000000007;
const int MAXN = 2000006;

LL conv(string x)
{
    LL i, ret = 0;

    for(i = 0; i < x.size(); i++)
    {
        if(x[i] < '7')
            ret = 9*ret + (x[i] - '0');
        else
            ret = 9*ret + (x[i] - '0' - 1);
    }

    return ret;
}

void solve(int caseno)
{
    LL n, i, sum;
    string x;

    cin >> n;

    sum = 0;
    for(i = 0; i < n; i++)
    {
        cin >> x;
//        show(x);
//        show(conv(x));
//        cout << "\n";
        sum += conv(x);
    }

    cout << sum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}

