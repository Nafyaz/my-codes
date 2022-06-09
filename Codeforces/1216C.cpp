#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007

struct rect
{
    ll x1, y1;
    ll x2, y2;

    rect() : x1(0), y1(0), x2(0), y2(0) {}
};

rect intersect(rect a, rect b)
{
    rect ret;

    if(a.x1 > b.x2 || a.x2 < b.x1)
        return ret;
    if(a.y1 > b.y2 || a.y2 < b.y1)
        return ret;

    ret.x1 = max(a.x1, b.x1);
    ret.y1 = max(a.y1, b.y1);
    ret.x2 = min(a.x2, b.x2);
    ret.y2 = min(a.y2, b.y2);

    return ret;
}

ll getArea(rect a)
{
    return (a.x2 - a.x1)*(a.y2 - a.y1);
}

void solve(ll caseno)
{
    rect w, b1, b2;
    ll wArea, b1Area, b2Area;

    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
    wArea = getArea(w);
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    b1Area = getArea(b1);
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    b2Area = getArea(b2);

    rect wb1 = intersect(w, b1);
    ll wb1Area = getArea(wb1);

    rect wb2 = intersect(w, b2);
    ll wb2Area = getArea(wb2);

    rect b1b2 = intersect(b1, b2);  
    ll b1b2Area = getArea(b1b2);

    rect wb1b2 = intersect(w, b1b2);
    ll wb1b2Area = getArea(wb1b2);

    ll total = wArea + b1Area + b2Area - wb1Area - wb2Area - b1b2Area + wb1b2Area;
    ll bTotal = b1Area + b2Area - b1b2Area;

    cout << (total > bTotal? "YES" : "NO");    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}