#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

int lastMultiple[MAXN];
int problems[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, i, j, a, lastZero;
    ll ans;

    cin >> n >> k;

    lastZero = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> a;

        if(a > k)
            problems[i] = max(lastMultiple[a], lastZero);

        if(a == k)
            lastZero = i;

        else if(a > k)
        {
            a -= k;

            for(j = 1; j*j <= a; j++)
            {
                if(a%j == 0)
                {
                    if(j > k)
                        lastMultiple[j] = i;
                    if(a/j > k)
                        lastMultiple[a/j] = i;
                }
            }
        }
    }

    ans = j = 0;
    for(i = 1; i <= n; i++)
    {
        j = max(j, problems[i]);
        ans += i-j;
    }

    cout << ans << "\n";
}