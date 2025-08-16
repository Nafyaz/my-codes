#include<bits/stdc++.h>
using namespace std;

int main() {
    int i, a;
    map<int, int> mp;

    for (i = 0; i < 5000; i++) {
        cin >> a;
        mp[a]++;
    }

    cout << mp.size() << "\n";
    
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }
}