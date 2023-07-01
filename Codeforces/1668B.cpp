#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005];
ll pos[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, m, prev_gap, prev_pos, i;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;


        for(i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a+n);

        prev_gap = 0;
        prev_pos = -1;
        for(i = 0; i < n; i++)
        {
            prev_gap = max(prev_gap, a[i]);
            pos[i] = prev_pos + prev_gap + 1;

            prev_gap = a[i];
            prev_pos = pos[i];
        }

        if(pos[n-1] >= m || m-pos[n-1]-1 + a[0] < a[n-1])
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
