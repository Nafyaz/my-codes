#include <bits/stdc++.h>
using namespace std;

int n;
int a[2][100005];

int get(int i, int j)
{
    if (j <= 0)
        return INT_MAX;
    if (j > n)
        return 0;

    if (a[i][j] != 0)
        return a[i][j];

    cout << (i == 0 ? "F " : "S ") << j << "\n";
    cin >> a[i][j];

    return a[i][j];
}

int main()
{
    int k;
    cin >> n >> k;

    int F1 = n + 1, F2 = 0;

    int low = 1, high = n, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (get(1, k - mid) > get(0, mid))
        {
            F1 = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    low = 1;
    high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (get(0, mid) > get(1, k - mid + 1))
        {
            F2 = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (F1 <= F2)
    {
        cout << "! " << a[0][F1] << "\n";
        return 0;
    }

    int S1 = n + 1, S2 = 0;

    low = 1;
    high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (get(0, k - mid) > get(1, mid))
        {
            S1 = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    low = 1;
    high = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (get(1, mid) > get(0, k - mid + 1))
        {
            S2 = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (S1 <= S2)
    {
        cout << "! " << a[1][S1] << "\n";
        return 0;
    }
}