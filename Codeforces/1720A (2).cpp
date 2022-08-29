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

void solve(int caseno)
{
    LL a, b, c, d, ad, bc;

    cin >> a >> b >> c >> d;

    ad = a*d;
    bc = b*c;

    if(ad == bc)
    {
        cout << "0\n";
        return;
    }

    if((bc != 0 && ad%bc == 0) || (ad != 0 && bc%ad == 0))
    {
        cout << "1\n";
        return;
    }

    cout << "2\n";
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

