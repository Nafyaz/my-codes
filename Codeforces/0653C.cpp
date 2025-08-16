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
#define MAXN 150005

LL a[MAXN], b[MAXN];

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    LL n, i, j, k, flag, ans;
    set<int> posSet;
    vector<int> pos;

    cin >> n;

    for(i = 1; i <= n; i++)    
    {
        cin >> a[i];

        if(i > 1)
        {
            if(i%2 == 0 && a[i-1] >= a[i])
            {
                posSet.insert(i-1);
                posSet.insert(i);
            }
            if(i%2 == 1 && a[i-1] <= a[i])
            {
                posSet.insert(i-1);
                posSet.insert(i);
            }
        }
    }

    for(auto p : posSet)
        pos.push_back(p);

    // for(auto u : pos)
    //     cout << u << " ";
    // cout << "\n";
    // return 0;

    if(pos.size() > 8)
    {
        cout << "0\n";
        return 0;
    }

    ans = 0;
    for(i = 0; i < pos.size(); i++)
    {
        for(j = 0; j < i; j++)
        {
            flag = 1;

            for(k = 1; k <= n; k++)
                b[k] = a[k];

            swap(b[pos[i]], b[pos[j]]);

            for(k = 2; k <= n; k++)
            {
                if(k%2 == 0 && b[k-1] >= b[k])
                    flag = 0;
                if(k%2 == 1 && b[k-1] <= b[k])
                    flag = 0;
            }

            ans += flag;
        }
    }

    for(i = 1; i <= n; i++)
        b[i] = a[i];

    for(auto p : pos)
    {
        for(i = 1; i <= n; i++)
        {
            if(posSet.find(i) != posSet.end())
                continue;

            swap(b[i], b[p]);

            // show(i);
            // show(p);

            flag = 1;

            if(i != 1)
            {
                if(i%2 == 0 && b[i-1] >= b[i])
                    flag = 0;
                if(i%2 == 1 && b[i-1] <= b[i])
                    flag = 0;
            }

            // show(flag);

            if(i != n)
            {
                if((i+1)%2 == 0 && b[i] >= b[i+1])
                    flag = 0;
                if((i+1)%2 == 1 && b[i] <= b[i+1])
                    flag = 0;
            }

            // show(flag);

            if(p != 1)
            {
                if(p%2 == 0 && b[p-1] >= b[p])
                    flag = 0;
                if(p%2 == 1 && b[p-1] <= b[p])
                    flag = 0;
            }

            // show(flag);

            if(p != n)
            {
                if((p+1)%2 == 0 && b[p] >= b[p+1])
                    flag = 0;
                if((p+1)%2 == 1 && b[p] <= b[p+1])
                    flag = 0;
            }

            // show(flag) << "\n";

            ans += flag;

            swap(b[i], b[p]);
        }
    }

    cout << ans << "\n";
}