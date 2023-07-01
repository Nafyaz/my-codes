#include<bits/stdc++.h>
using namespace std;

int trie[6000006][2], len[6000006];
int id;

void Add(int a)
{
    int i, r = 0;

    for(i = 20; i >= 0; i--)
    {
        int bit = ((a & (1<<i)) >> i);

        if(trie[r][bit] == 0)
            trie[r][bit] = ++id;

        r = trie[r][bit];
        len[r]++;
    }
}

int mex(int curr)
{
    int i, r = 0, ret = 0;

    for(i = 20; i >= 0; i--)
    {
        int bit = ((curr & (1<<i)) >> i);

        if(trie[r][bit] != 0)
        {
            if(len[trie[r][bit]] == (1<<i))
            {
                ret += (1 << i);
                if(trie[r][bit^1] != 0)
                    r = trie[r][bit^1];
                else
                    return ret;
            }
            else
            {
                r = trie[r][bit];
            }
        }
        else
            return ret;
    }

    return ret;
}

int main()
{
    int i, n, m, a, x, curr;
    cin >> n >> m;

    set<int> s;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        s.insert(a);
    }

    for(auto u : s)
        Add(u);

    curr = 0;
    while(m--)
    {
        cin >> x;
        curr ^= x;

        cout << mex(curr) << "\n";
    }
}
