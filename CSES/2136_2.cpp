#include <bits/stdc++.h>
using namespace std;

int trie[6000006][2], lastNode, ans;
int a[200005], k;

void add(int num)
{
    int node = 0;

    for (int i = 0; i < k; i++)
    {
        int bit = ((num & (1 << i)) == 0);
        if (trie[node][bit] == 0)
        {
            lastNode++;
            trie[node][bit] = lastNode;
        }

        node = trie[node][bit];
    }
}

void query(int num, int node, int idx, int mismatch)
{
    if (mismatch > ans)
        return;

    if (idx == k)
    {
        ans = min(ans, mismatch);
        return;
    }

    int bit = ((num & (1 << idx)) == 0);

    if (trie[node][bit] != 0)
        query(num, trie[node][bit], idx + 1, mismatch);

    if (trie[node][!bit] != 0)
        query(num, trie[node][!bit], idx + 1, mismatch + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n >> k;

    ans = k;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;

        for (int j = 0; j < k; j++)
        {
            if (s[j] == '1')
                a[i] |= (1 << j);
        }
    }

    sort(a, a + n);

    // for (int i = 0; i < n; i++)
    //     cout << a[i] << ";\n";

    add(a[0]);
    for (int i = 1; i < n; i++)
    {
        query(a[i], 0, 0, 0);
        add(a[i]);
    }

    cout << ans;
}