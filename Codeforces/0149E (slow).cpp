#include <bits/stdc++.h>
#include <tuple>
using namespace std;
using LL = long long;
vector <int> prefix_function(string &s) {
    int n = s.size();
    vector <int> f(n + 1);
    for(int i = 1, j; i < n; i++) {
        for(j = f[i - 1]; j and s[i] != s[j]; j = f[j - 1]);
        f[i] = j + (s[i] == s[j]);
    }
    return f;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    string s;
    int q;
    cin >> s >> q;
    int n = s.size(), ans = 0;
    while(q--) {
        string t;
        cin >> t;
        int m = t.size();
        if(m < 2) continue;
        string L = t + '$' + s, R = s + '$' + t;
        reverse(R.begin(), R.end());
        vector <int> left = prefix_function(L), right = prefix_function(R);
        for(int i = m + 2; i < L.size(); i++) {
            left[i] = max(left[i], left[i - 1]);
            right[i] = max(right[i], right[i - 1]);
        }
        reverse(right.begin() + m + 1, right.end() - 1);
        int mx = 0;
        for(int i = m + 1; i < L.size(); i++) {
            if(left[i] and right[i + 1]) mx = max(mx, left[i] + right[i + 1]);
        }
        if(mx >= m) 
        {
            cout << q << "\n";
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
