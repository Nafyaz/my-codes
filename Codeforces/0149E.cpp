#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

vector<int> z_function(string s)
{
    int i, l, r, n = s.size();
    vector<int> Z(n);
    Z[0] = 0;
    for(i = 1, l = 0, r = 0; i < n; i++)
    {
        if(i <= r) //This condition is false when i=1
            Z[i] = min(r-i+1, Z[i-l]);
        while(i+Z[i] < n && s[Z[i]] == s[i+Z[i]])
            Z[i]++; //if Z[1] has previous value, it will cause problem here

        if(i+Z[i] - 1 > r)
        {
            l = i;
            r = i+Z[i]-1;
        }
    }

    return Z;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, j, n, ans;
    string s, sRev, t, tRev, total;

    cin >> s >> n;
    
    sRev = s;
    reverse(sRev.begin(), sRev.end());

    ans = 0;

    while(n--)
    {
        cin >> t;

        if(t.size() == 1)
            continue;

        tRev = t;
        reverse(tRev.begin(), tRev.end());

        total = t + '#' + s;
        vector<int> Z = z_function(total);

        // cout << "Z: ";
        // for(i = 0; i < Z.size(); i++)
        //     cout << Z[i] << " ";
        // cout << "\n";

        total = tRev + '#' + sRev;
        vector<int> Z_rev = z_function(total);

        // cout << "Z_rev: ";
        // for(i = 0; i < Z_rev.size(); i++)
        //     cout << Z_rev[i] << " ";
        // cout << "\n";

        for(i = 0; i < Z.size(); i++)        
        {
            if(i <= t.size())
                Z[i] = 0;
            else
                Z[i] = max(Z[i-1], Z[i]);
        }

        // cout << "Z: ";
        // for(i = 0; i < Z.size(); i++)
        //     cout << Z[i] << " ";
        // cout << "\n";
        // cout << "\n";

        
        for(i = t.size() + 1; i < Z_rev.size(); i++)
        {
            int len = i-t.size()-1 + Z_rev[i];
            int rem = t.size() - Z_rev[i];
            if(Z[Z.size() - len - rem] + Z_rev[i] >= t.size())
            {
                // show(i);
                // show(len);
                // show(rem);
                cout << "\n";
                ans++;
                break;
            }
        }
    }

    cout << ans << "\n";
}