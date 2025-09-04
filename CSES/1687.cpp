#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int ancestor[MAXN][20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, q, e, x, k;

    cin >> n >> q;

    memset(ancestor, -1, sizeof ancestor);
    for (int i = 2; i <= n; i++) {
        cin >> e;
        ancestor[i][0] = e;
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (ancestor[i][j-1] != -1)
                ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = 0; j < 6; j++)
            cout << ancestor[i][j] << "   ";
        cout << "\n";
    }

    while (q--) {
        cin >> x >> k;

        for (int i = 19; i >= 0 && k > 0 && x != -1; i--) {                
            if ((1<<i) <= k) {
                x = ancestor[x][i];
                k -= (1<<i);
            }
        }

        cout << x << "\n";
    }
}