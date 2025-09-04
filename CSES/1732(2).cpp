#include<bits/stdc++.h>
using namespace std;

#define BASE 31
#define MOD 1000000007
#define MAXN 1000006

long long prefHash[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string s;

    cin >> s;
    long long n = s.size();

    for (int i = 0; i < n; i++) {
        prefHash[i+1] = (prefHash[i] * BASE) % MOD;
        prefHash[i+1] = (prefHash[i+1] + s[i] - 'a' + 1) % MOD;
    }

    long long mul = BASE;
    vector<int> ans;
    for (int sz = 1; sz < n; sz ++) {
        long long left = prefHash[sz];
        long long right = (((prefHash[n] - (prefHash[n-sz] * mul) % MOD) % MOD) + MOD) % MOD;

        if (left == right)
            ans.push_back(sz);

        mul = (mul * BASE) % MOD;
    }

    for (auto a : ans) {
        cout << a << " ";
    }
}