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

int Div[MAXN], freq[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x, ans = 0;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
        if(freq[x] > 1)
            ans = max(ans, x);
    }

    for(int i = ans+1; i < MAXN; i++)
    {
        if(freq[i] == 0)
            continue;
        for(int j = 1; j*j <= i; j++)
        {
            if(i%j == 0)
            {
                Div[j]++;

                if(Div[j] > 1)
                    ans = max(ans, j);

                if(j*j != i)
                {
                    Div[i/j]++;

                    if(Div[i/j] > 1)
                        ans = max(ans, i/j);
                }
            }
            
        }
    }

    cout << ans << "\n";
}