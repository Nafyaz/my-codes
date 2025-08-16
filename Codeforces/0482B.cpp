#include<bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << ": " << x << "; "
#define MAXN 100005

int arr[MAXN];
int L[MAXN], R[MAXN], Q[MAXN];
int pref[32][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, pos, bit;

    cin >> n >> m;

    for(i = 1; i <= m; i++)
        cin >> L[i] >> R[i] >> Q[i];

    for(pos = 0; pos < 31; pos ++)
    {
        bit = (1 << pos);

        for(i = 1; i <= m; i++)
        {
            if(Q[i]&bit)
            {
                pref[pos][L[i]] += 1;
                pref[pos][R[i]+1] += -1;
            }
        }

        for(i = 1; i <= n; i++)
            pref[pos][i] = pref[pos][i-1] + pref[pos][i];
        
        for(i = 1; i <= n; i++)
            pref[pos][i] = pref[pos][i-1] + min(1, pref[pos][i]);

        for(i = 1; i <= m; i++)
        {
            if((Q[i]&bit) && pref[pos][R[i]] - pref[pos][L[i]-1] != R[i]-L[i]+1)
            {
                cout << "NO\n";
                return 0;
            }

            if(!(Q[i]&bit) && pref[pos][R[i]] - pref[pos][L[i]-1] == R[i]-L[i]+1)
            {
                cout << "NO\n";
                return 0;
            }
        }


        for(i = 1; i <= n; i++)
            arr[i] += bit*(pref[pos][i] - pref[pos][i-1]);
    }

    cout << "YES\n";
    for(i = 1; i <= n; i++)
        cout << arr[i] << " ";
}