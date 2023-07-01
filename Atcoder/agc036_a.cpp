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

    LL s, a = 1000000000, x, y;

    cin >> s;

    cout << "0 0 ";
    cout << a <<" 1 ";
    y = (s + a - 1)/a;
    x = a*y - s;
    cout << x << " " << y << "\n";
}