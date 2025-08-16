#include<bits/stdc++.h>
using namespace std;
#define ll long long

double a[100005];
double pref[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, k;
    double ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            cin >> a[i];

        sort(a+1, a+n+1);        

        for(i = 1; i <= n; i++)
            pref[i] = pref[i-1] + a[i];

        ans = pref[n]/n;
        for(k = 1; k <= n; k++)
        {
            ans = max(ans, (pref[k]/k + pref[n]-pref[k]) / (n-k+1));
            // cout << k << ": " << (pref[k]/k + pref[n]-pref[k]) / (n-k+1) << "\n";
        }

        cout << fixed << setprecision(7) << ans << "\n";
    }
}