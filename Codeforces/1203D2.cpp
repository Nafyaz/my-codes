#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200005

int pref[MAXN], suff[MAXN];

void solve(int caseno)
{
    int i, j, n, m, ans;
    string s, t;

    cin >> s >> t;
    n = s.size();
    m = t.size();

    for(i = 0, j = 0; i < m; i++)
    {
        while(s[j] != t[i])        
            j++;
        
        pref[i] = j;
        j++;
    }

    for(i = m-1, j = n-1; i >= 0; i--)
    {
        while(s[j] != t[i])
            j--;

        suff[i] = j;
        j--;
    }

    // cout << "pref: ";
    // for(i = 0; i < m; i++)
    //     cout << pref[i] << " ";
    // cout << "\nSuff: ";
    // for(i = 0; i < m; i++)
    //     cout << suff[i] << " ";
    // cout << "\n";

    ans = max(suff[0], n - pref[m-1] - 1);
    for(i = 0; i+1 < m; i++)    
        ans = max(ans, suff[i+1] - pref[i] - 1);
    
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}