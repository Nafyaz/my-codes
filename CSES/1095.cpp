#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long bigmod(long long a, long long p) {
    if (p == 0)
        return 1;
    
    long long ret = bigmod(a, p/2);
    ret = (ret * ret) % MOD;
    if (p%2 == 1)
        ret = (ret * a) % MOD;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        long long a, b;
        cin >> a >> b;

        cout << bigmod(a, b) << "\n";
    }
}