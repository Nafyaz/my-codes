#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 1000006

int n;
int p[MAXN], q[MAXN];
int vis[MAXN], cycle[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, len, c1, c2;

    cin >> n;

    for(i = 1; i <= n; i++)
        cin >> p[i];

    for(i = 1; i <= n; i++)
    {
        if(vis[i])
            continue;

        len = 0;
        for(j = p[i]; !vis[i]; j = p[j])
        {
            len++;
            vis[j] = 1;
        }

        if(len&1)
        {
            c2 = c1 = p[i];
            for(j = 0; j < len/2; j++)
                c1 = p[j];
        }
        else
        {
            if(!cycle[len])
            {
                cycle[len] = p[i];
                continue;
            }
            else
            {
                c1 = p[i];
                c2 = cycle[len];
                cycle[len] = 0;
                len *= 2;
            }
        }

        while(len--)
        {
            q[c1] = c2;
            c2 = p[c1];
            c1 = q[c1];
        }
    }

    for(i = 1; i <= n; i++)
    {
        if(cycle[i])
        {
            cout << "-1\n";
            return 0;
        }
    }

    for(i = 1; i <= n; i++)
        cout << q[i] << " ";
    cout << "\n";
}