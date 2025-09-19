#include <bits/stdc++.h>
using namespace std;

#define MAXN 20004

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k, ans = 30;
    char s[31];
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);

        for (int j = 0; j < k; j++)
        {
            if (s[j] == '1')
                a[i] |= 1 << j;
        }

        for (int j = 0; j < i; j++)
        {
            ans = min(ans, __builtin_popcount(a[i] ^ a[j]));
        }
    }

    printf("%d\n", ans);
}