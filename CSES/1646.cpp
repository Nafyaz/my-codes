#include<bits/stdc++.h>
using namespace std;

long long pref[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, q, x;

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> x;
        pref[i] = pref[i-1] + x;
    }

    int a, b;
    while (q--) {
        cin >> a >> b;

        cout << pref[b] - pref[a-1] << "\n";
    }
}