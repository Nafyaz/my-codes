#include <bits/stdc++.h>
using namespace std;

int func(int total, int target, int killParity)
{
    int willKill = (total + killParity) / 2;

    if (target <= willKill)
    {
        return target * 2 - killParity;
    }

    int newKillParity = killParity;
    if (total % 2 == 1)
        newKillParity ^= 1;

    return func(total - willKill, target - willKill, newKillParity) * 2 + killParity - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int q, n, k;
    cin >> q;

    while (q--)
    {
        cin >> n >> k;

        cout << func(n, k, 0) << "\n";
    }
}