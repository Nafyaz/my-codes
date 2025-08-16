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
#define MAXN 200005

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

pLL segments[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, l, r;
    LL leftInter, rightInter, leftMiddle, rightMiddle;
    LL bothInter, inter;
    LL endLeft, startRight, ans;
    ordered_set<LL> OSL, OSR;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> segments[i].ff >> segments[i].ss;

        OSL.insert(segments[i].ff);
        OSR.insert(segments[i].ss);
    }

    for(i = 0; i < n; i++)
    {
        l = segments[i].ff;
        r = segments[i].ss;

        leftInter = (n-1 - OSR.order_of_key(l)) - (n-1 - OSL.order_of_key(l));
        rightInter = (n-1 - OSR.order_of_key(r)) - (n - OSL.order_of_key(r));
        
        endLeft = OSR.order_of_key(l);
        startRight = n - OSL.order_of_key(r);

        bothInter = OSL.order_of_key(l) - endLeft

        leftMiddle = OSR.order_of_key(r);
        rightMiddle = n-1-OSL.order_of_key(l);


        ans = leftMiddle - endLeft - leftInter;

        show(leftInter);
        show(rightInter);

        show(leftMiddle);
        show(rightMiddle);

        show(endLeft);
        show(startRight);

        show(ans);

        cout << "\n";

        cout << ans << "\n";
    }
}