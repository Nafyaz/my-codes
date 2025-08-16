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

map<LL, LL> ans;

LL bigmod(LL a, LL p)
{
    LL ret = 1;

    while(p)
    {
        if(p&1)
            ret = (ret * a) % MOD;
        
        a = (a*a) % MOD;
        p /= 2;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL x, y, i, j, d, d2;

    cin >> x >> y;

    if(y%x != 0)
    {
        cout << "0\n";
        return 0;
    }

    y /= x;

    vector<LL> div;
    for(i = 1; i*i <= y; i++)
    {
        if(y%i == 0)
        {
            div.push_back(i);

            if(i*i != y)
                div.push_back(y/i);
        }
    }

    sort(div.begin(), div.end());

    for(i = 0; i < div.size(); i++)
    {
        d = div[i];

        ans[d] = bigmod(2, d-1);
        for(j = 0; j < i; j++)
        {
            d2 = div[j];
            if(d%d2 != 0)
                continue;
                
            ans[d] = (ans[d] - ans[d2] + MOD) % MOD;
        }
    }

    cout << ans[y];
}