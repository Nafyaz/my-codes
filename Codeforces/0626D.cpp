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
#define MAXN 5003

int a[MAXN], suff[MAXN];
unordered_map<int, int> freq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j;
    double ans;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
            freq[abs(a[i] - a[j])]++;
    }
    
    for(i = MAXN-2; i >= 0; i--)
        suff[i] = suff[i+1] + freq[i];

    ans = 0;
    for(i = 0; i < MAXN; i++)
    {
        for(j = 0; i+j+1 < MAXN; j++)
        {
            ans += 1.0*freq[i]*freq[j]*suff[i + j + 1]/suff[0]/suff[0]/suff[0];

            // cout << i << " " << j << ": " << total << ", " << ans << "\n";
        }
    }

    cout << fixed << setprecision(10) << 1.0*ans << "\n";
}