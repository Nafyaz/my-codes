#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007

string s;
ll valid[4000006], opening[4000006], closing[4000006];

void Build(ll node, ll bg, ll ed)
{
    if(bg == ed)
    {
        valid[node] = 0;
        opening[node] = 0;
        closing[node] = 0;

        if(s[bg] == '(')
            opening[node]++;
        else
            closing[node]++;

        return;
    }

    ll leftNode = 2*node + 1, rightNode = 2*node + 2;
    ll mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

    valid[node] = 2*min(opening[leftNode], closing[rightNode]);
    opening[node] = opening[leftNode] + opening[rightNode] - valid[node]/2;
    closing[node] = closing[leftNode] + closing[rightNode] - valid[node]/2;

    valid[node] += valid[leftNode] + valid[rightNode];
}

pair<ll, pll> Query(ll node, ll bg, ll ed, ll l, ll r)
{


    if(bg >= l && ed <= r)
        return {valid[node], {opening[node], closing[node]}};
    if(bg > r || ed < l)
        return {0, {0, 0}};

    ll leftNode = 2*node + 1, rightNode = 2*node + 2;
    ll mid = (bg + ed)/2;

    pair<ll, pll> p = Query(leftNode, bg, mid, l, r);
    pair<ll, pll> q = Query(rightNode, mid+1, ed, l, r);

    ll val = 2*min(p.ss.ff, q.ss.ss);
    ll ope = p.ss.ff + q.ss.ff - val/2;
    ll clo = p.ss.ss + q.ss.ss - val/2;
    val += p.ff + q.ff;

    return {val, {ope, clo}};
}

void solve(ll caseno)
{
    int m, n, i, l, r;

    cin >> s >> m;

    n = s.size();
    Build(0, 0, n-1);

    for(i = 0; i < m; i++)
    {
        cin >> l >> r;
        cout << Query(0, 0, n-1, l-1, r-1).ff << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    while(T--)
    {
        solve(++caseno);
    }
}