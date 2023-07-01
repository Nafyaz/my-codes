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

    LL H, W, a, b, i, j;

    cin >> H >> W >> a >> b;

    for(i = 0; i < b; i++)
    {
        for(j = 0; j < a; j++)
            cout << "0";
        for(j = a; j < W; j++)
            cout << "1";
        cout << "\n";
    }

    for(i = b; i < H; i++)
    {
        for(j = 0; j < a; j++)
            cout << "1";
        for(j = a; j < W; j++)
            cout << "0";
        cout << "\n";
    }
}