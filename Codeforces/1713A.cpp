#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

void solve(int caseno)
{
    int n, i, x, y, minX, maxX, minY, maxY;

    cin >> n;

    minX = minY = 0;
    maxX = maxY = 0;
    for(i = 0; i < n; i++)
    {
        cin >> x >> y;

        minX = min(minX, x);
        maxX = max(maxX, x);

        minY = min(minY, y);
        maxY = max(maxY, y);
    }

    minX = abs(minX);
    minY = abs(minY);

    cout << 2*minX + 2*minY + 2*maxX + 2*maxY << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}