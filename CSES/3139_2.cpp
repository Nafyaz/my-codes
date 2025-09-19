#include <bits/stdc++.h>
using namespace std;

#define MAXN 1003

int a[MAXN], ans[MAXN];

bool cmp(int x, int y)
{
    string s;
    cout << "? " << x << " " << y << "\n";
    cin >> s;
    return s == "YES";
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        a[i] = i;

    stable_sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++)
        ans[a[i]] = i;

    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}