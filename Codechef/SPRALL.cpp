#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll degree[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, q, i, a, b, c, d, ans, temp;

    cin >> T;

    while(T--)
    {
        cin >> n >> q;

        for(i = 1; i <= n; i++)
            degree[i] = 0;

        for(i = 1; i < n; i++)
        {
            cin >> a >> b;
            degree[a]++;
            degree[b]++;
        }

//        for(i = 1; i <= n; i++)
//            cout << degree[i] << " ";
//        cout << "\n";

        ans = 0;
        for(i = 1; i <= n; i++)
            ans += degree[i]*(degree[i]+1)/2 - 1;
        ans++;
        cout << ans << "\n";

        while(q--)
        {
            temp = ans;

            cin >> a >> b >> c >> d;

            if(degree[a] > 1)
                temp -= degree[a];
            if(degree[b] > 1)
                temp -= degree[b];

            degree[a]--;
            degree[b]--;
            degree[c]++;
            degree[d]++;

            if(degree[c] > 1)
                temp += degree[c];
            if(degree[d] > 1)
                temp += degree[d];

            degree[a]++;
            degree[b]++;
            degree[c]--;
            degree[d]--;

            cout << temp << "\n";
        }
    }
}
