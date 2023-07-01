#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll best[1000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, C, m, c, d, h, D, H, i, x, mn;

    cin >> n >> C;

    for(i = 0; i < n; i++)
    {
        cin >> c >> d >> h;
        best[c] = max(best[c], d*h);
    }

    for(c = 1; c <= C; c++)
    {
        for(x = 1; c*x <= C; x++)
            best[c*x] = max(best[c*x], best[c]*x);
    }

    for(c = 1; c <= C; c++)
        best[c] = max(best[c], best[c-1]);

    cin >> m;
    while(m--)
    {
        cin >> D >> H;

        mn = upper_bound(best, best + C + 1, D*H) - best;

        if(mn == C+1)
            cout << "-1 ";
        else
            cout << mn << " ";
    }
}
