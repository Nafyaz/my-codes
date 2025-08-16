#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

long long a[102][102][102];
long long pref[102][102][102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                cin >> a[i][j][k];
                pref[i][j][k] = (pref[i - 1][j][k] + pref[i][j - 1][k] + pref[i][j][k - 1]) -
                                (pref[i - 1][j - 1][k] + pref[i - 1][j][k - 1] + pref[i][j - 1][k - 1]) +
                                (pref[i - 1][j - 1][k - 1]) +
                                a[i][j][k];
            }
        }
    }

    int q;
    int Lx, Rx, Ly, Ry, Lz, Rz;
    cin >> q;
    while (q--)
    {
        cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
        cout << (pref[Rx][Ry][Rz]) -
                    (pref[Lx - 1][Ry][Rz] + pref[Rx][Ly - 1][Rz] + pref[Rx][Ry][Lz - 1]) +
                    (pref[Lx - 1][Ly - 1][Rz] + pref[Lx - 1][Ry][Lz - 1] + pref[Rx][Ly - 1][Lz - 1]) -
                    (pref[Lx - 1][Ly - 1][Lz - 1])
             << "\n";
    }
}