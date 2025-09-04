#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int desired[MAXN], actual[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> desired[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> actual[i];
    }

    sort(desired, desired + n);
    sort(actual, actual + m);

    int ans = 0, i = 0, j = 0;
    while (i < n && j < m)
    {
        while (i < n && desired[i] + k < actual[j])
            i++;

        while (j < m && desired[i] - k > actual[j])
            j++;

        while (i < n && j < m && desired[i] - k <= actual[j] && actual[j] <= desired[i] + k)
        {
            ans++;

            i++;
            j++;
        }
    }

    cout << ans << "\n";
}