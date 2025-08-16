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

string grid[502];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL i, j, n;

    cin >> n;

    for(i = 0; i < n; i++)
        grid[i] = string(n, '.');

    for(i = 0; i < n; i++)
    {
        for(j = i*3; j < (i+1)*3; j++)
            grid[i][j%n] = '#';
    }

    if(n%3 != 0)
    {
        swap(grid[0], grid[n/3]);
        swap(grid[n-1], grid[n-1-n/3]);
    }

    for(i = 0; i < n; i++)
        cout << grid[i] << "\n";
}