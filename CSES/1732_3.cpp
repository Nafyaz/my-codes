#include <bits/stdc++.h>
using namespace std;

#define BASE 31
#define MOD 1000000007
#define MAXN 1000006

long long prefHash[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;

    long long n = s.size();

    for (int i = 0; i < n; i++)
    {
        prefHash[i + 1] = (prefHash[i] * BASE) % MOD;
        prefHash[i + 1] = (prefHash[i + 1] + s[i] - 'a' + 1) % MOD;
    }

    long long mul = 1;
    long long sufHash = 0;

    vector<int> ans;
    for (int sz = 1, i = n - 1; sz < n; sz++, i--)
    {
        sufHash = (sufHash + ((s[i] - 'a' + 1) * mul) % MOD) % MOD;

        if (prefHash[sz] == sufHash)
            ans.push_back(sz);

        mul = (mul * BASE) % MOD;
    }

    for (auto u : ans)
        cout << u << " ";
}

//         a           b           b           a
// p[0]
// p[1]    1
// p[2]    1*31    +   2
// p[3]    1*31^2  +   2*31    +   2
// p[4]    1*31^3  +   2*31^2  +   2*31   +    1

// s[5]
// s[4]                                        1
// s[3]                            2*31   +    1
// s[2]                2*31^2  +   2*31   +    1
// s[1]