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

int getArea(vector<pii> v, int ignore)
{
    int i, ret;

    if(ignore != -1)
        v.erase(v.begin() + ignore);

    ret = 0;
    for(i = 0; i < v.size(); i++)    
        ret += v[i].ff*v[(i+1)%v.size()].ss - v[i].ss*v[(i+1)%v.size()].ff;
    
    return abs(ret);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, x, y, area, triArea;
    vector<pii> v;

    for(i = 0; i < 4; i++)
    {
        cin >> x >> y;
        v.push_back({x, y});
    }

    area = getArea(v, -1);

    for(i = 0; i < 4; i++)
    {
        triArea = getArea(v, i);

        if(triArea >= area)
        {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}