#include<bits/stdc++.h>
using namespace std;

long long n, t;
long long k[200005];

bool isPossible(long long limit) {
    long long total = 0;

    for (int i = 0; i < n; i++) {
        total += limit / k[i];

        if (total >= t)
            return true;
    }

    return false;
}

int main() {    
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    long long low = 1, high = 1e18, mid;
    long long ans = -1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (isPossible(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
}