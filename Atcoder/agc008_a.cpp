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

set<LL> st;

LL call(LL x, LL y)
{
    if(x == y)
        return 0;

    if(st.find(x) != st.end())
        return INF;
    
    st.insert(x);

    LL ret = INF;
    
    ret = min(ret, 1 + call(-x, y));

    if(abs(y) > abs(x))
        ret = min(ret, abs(y)-abs(x) + call(x + abs(y)-abs(x), y));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL x, y;

    cin >> x >> y;

    cout << call(x, y) << "\n";
}