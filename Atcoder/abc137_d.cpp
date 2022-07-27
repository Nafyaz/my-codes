#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int m;
pair<int, int> work[100005];
int arr[100005], Tree[4*100005];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.ff != b.ff)
        return a.ff > b.ff;
    return a.ss < b.ss;
}

void Update(int node, int bg, int ed, int idx)
{
    if(bg == ed)
    {
        arr[bg] = 1;
        Tree[node] = 1;
        return;
    }

    int leftNode = 2*node+1, rightNode = 2*node+2;
    int mid = (bg + ed) / 2;

    if(idx <= mid)
        Update(leftNode, bg, mid, idx);
    else
        Update(rightNode, mid+1, ed, idx);

    Tree[node] = Tree[leftNode] + Tree[rightNode];
}

int Query(int node, int bg, int ed, int l, int r)
{
    if(l > ed || r < bg)
        return 0;
    if(l <= bg && ed <= r)
        return Tree[node];

    int leftNode = 2*node + 1, rightNode = 2*node+2;
    int mid = (bg + ed) / 2;

    return Query(leftNode, bg, mid, l, r) + Query(rightNode, mid+1, ed, l, r);
}

int getRightMost(int r)
{
    int low = 0, high = r, mid, ret = -1;

    if(Query(0, 0, m-1, 0, r) == r+1)
        return -1;

    while(low <= high)
    {
        if(low == high)
            return low;

        mid = (low + high) / 2;

        if(Query(0, 0, m-1, mid+1, high) < high - mid)
            low = mid + 1;
        else
            high = mid;
    }

    return -1;
}

int main()
{
    int n, i, ans, pos;

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> work[i].ss >> work[i].ff;

    sort(work, work+n, cmp);

//    cout << "work:\n";
//    for(i = 0; i < n; i++)
//        cout << work[i].ff << " " << work[i].ss << "\n";
//    cout << "\n";

    ans = 0;
    for(i = 0; i < n; i++)
    {
        pos = getRightMost(m - work[i].ss);

        if(pos != -1)
        {
            ans += work[i].ff;
            Update(0, 0, m-1, pos);
        }

//        cout << "Tree:\n";
//        for(i = 0; i )
    }

    cout << ans << "\n";
}