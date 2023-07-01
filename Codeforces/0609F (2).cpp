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

LL n, m;
struct frog
{
    LL pos, reach, idx;

    bool operator<(const frog &f) const
    {
        return pos < f.pos;
    }
};

frog frogs[MAXN];
LL kills[MAXN], tounge[MAXN];
LL Tree[4*MAXN];

void Build(LL node, LL bg, LL ed)
{
    if(bg == ed)
    {
        Tree[node] = frogs[bg].reach;
        return;
    }

    LL leftNode = 2*node, rightNode = 2*node + 1;
    LL mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);

    Tree[node] = max(Tree[leftNode], Tree[rightNode]);
}

void Update(LL node, LL bg, LL ed, LL idx, LL val)
{
    if(bg == ed)
    {
        Tree[node] = val;
        return;
    }

    LL leftNode = 2*node, rightNode = 2*node + 1;
    LL mid = (bg + ed)/2;

    if(idx <= mid)
        Update(leftNode, bg, mid, idx, val);
    else
        Update(rightNode, mid+1, ed, idx, val);

    Tree[node] = max(Tree[leftNode], Tree[rightNode]);
}

LL Query(LL node, LL bg, LL ed, LL l, LL r, LL val)
{
    if(bg > r || ed < l || Tree[node] < val)
        return -1;

    if(bg == ed)
        return bg;

    LL leftNode = 2*node, rightNode = 2*node + 1;
    LL mid = (bg + ed)/2;

    LL ret = Query(leftNode, bg, mid, l, r, val);
    if(ret != -1)
        return ret;
    else
        return Query(rightNode, mid+1, ed, l, r, val);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL i, x, p, b;
    LL frogIdx, cnt, lastFrogIdx;
    multiset<pLL> mosquitoes;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        cin >> x >> tounge[i];

        frogs[i] = frog({x, x+tounge[i], i});
    }

    sort(frogs+1, frogs + n+1);

    // for(i = 1; i <= n; i++)
    //     cout << frogs[i].pos << " " << frogs[i].reach << " " << frogs[i].idx << "\n";
    // cout << "\n";

    Build(1, 1, n);

    while(m--)
    {
        cin >> p >> b;

        mosquitoes.insert({p, b});

        frogIdx = -1;
        lastFrogIdx = lower_bound(frogs+1, frogs+n+1, frog({p+1, -1, -1})) - frogs-1;

        // show(m);
        // show(high);
        // cout << "\n";

        frogIdx = Query(1, 1, n, 1, lastFrogIdx, p);

        // show(p);
        // show(b);
        // cout << "\n";
        // show(frogIdx);
        // cout << "\n\n";

        if(frogIdx == -1)
            continue;

        while(!mosquitoes.empty())
        {
            auto mosquitoeIt = mosquitoes.lower_bound({frogs[frogIdx].pos, -1});

            if(mosquitoeIt == mosquitoes.end() || (*mosquitoeIt).ff > frogs[frogIdx].reach)
                break;

            cnt = mosquitoes.count(*mosquitoeIt);

            frogs[frogIdx].reach += (*mosquitoeIt).ss * cnt;
            Update(1, 1, n, frogIdx, frogs[frogIdx].reach);

            kills[frogs[frogIdx].idx] += cnt;
            tounge[frogs[frogIdx].idx] = frogs[frogIdx].reach - frogs[frogIdx].pos;
         
            mosquitoes.erase(*mosquitoeIt);
        }

        // for(i = 1; i <= n; i++)
        //     cout << frogs[i].pos << " " << frogs[i].reach << " " << frogs[i].idx << "\n";
        // cout << "\n\n";
    }

    for(i = 1; i <= n; i++)
        cout << kills[i] << " " << tounge[i] << "\n";
}
