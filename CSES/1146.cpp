#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    long long n, ans = 0;
    cin >> n;

    for (long long pos = 1; pos <= n; pos *= 2) {
        ans += (n+1)/(pos*2) * pos;

        if ((n+1)%pos != 0 && ((n+1)/pos)%2 == 1)
            ans += (n+1)%pos;
    }

    cout << ans << "\n";
}