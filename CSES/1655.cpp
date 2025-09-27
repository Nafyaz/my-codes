#include <bits/stdc++.h>
using namespace std;

#define MAXN 6000006

int trie[MAXN][2], maxNode = 0;

void Add(int val) {
    int node = 0;

    for (int i = (1 << 30); i > 0; i /= 2) {
        int bit = ((val & i) != 0);

        if (trie[node][bit] == 0)
        {
            maxNode++;
            trie[node][bit] = maxNode;
        }

        node = trie[node][bit];
    }
}

int getMax(int val) {
    int node = 0, ret = 0;

    for (int i = (1 << 30); i > 0; i /= 2) {
        int revBit = ((val & i) == 0);

        if (trie[node][revBit] != 0)
        {
            ret += i;
            node = trie[node][revBit];
        }
        else {
            node = trie[node][!revBit];
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, a, prefXor = 0, mx = 0;
    cin >> n;

    Add(prefXor);
    for (int i = 0; i < n; i++) {
        cin >> a;
        prefXor ^= a;        
        mx = max(mx, getMax(prefXor));
        
        Add(prefXor);
    }

    cout << mx << "\n";
}