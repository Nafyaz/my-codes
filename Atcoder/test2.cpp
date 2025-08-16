#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 200005

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    freopen("output.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    vector<pair<int, int>> v;
    while (cin >> l)
    {
        cin >> r;

        v.push_back({l, r});
    }

    sort(v.begin(), v.end());

    for (auto u : v)
    {
        cout << u.first << " " << u.second << "\n";
    }
}