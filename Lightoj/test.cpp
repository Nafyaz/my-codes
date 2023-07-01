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
#define MAXN 2000006

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, j, k, g[100];

    g[0] = g[1] = g[2] = 0;
    for(i = 3; i < 100; i++)
    {
        set<LL> st;

        for(j = 1; 2*j < i; j++)
            st.insert(g[j] ^ g[i-j]);

        g[i] = 0;
        for(auto u : st)
        {
            if(g[i] == u)
                g[i]++;
            else
                break;
        }
    }
    for(i = 0; i < 20; i++)
        cout << setw(3) << i;
    cout << "\n";
    for(i = 0; i < 20; i++)
        cout << setw(3) << g[i];
    cout << "\n";
}