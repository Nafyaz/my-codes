#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int rmq[MAXN][20], Log[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, q;

    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        Log[i] = Log[i/2] + 1;
    }

    for (int i = 1; i <= n; i++) {
        cin >> rmq[i][0];
    }

    for (int j = 1; j < 20; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            rmq[i][j] = min(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
        }
    }

    int a, b, logDiff;
    while (q--) {
        cin >> a >> b;

        logDiff = Log[b-a+1];

        cout << min(rmq[a][logDiff], rmq[b - (1 << logDiff) + 1][logDiff]) << "\n";
    }

    cout << "\n";
}