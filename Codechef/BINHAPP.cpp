#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

struct info
{
    int sum, left, right, left_right, ans;

    info()
    {
        sum = left = right = left_right = ans = 0;
    }
};

vector<info> arr(MAXN), Tree(4*MAXN);

info getInfo(string s)
{
    info ret;
    int i, mnSum, suff;

    mnSum = 0;
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
            ret.sum++;
        else
            ret.sum--;

        ret.ans = max(ret.ans, ret.sum - mnSum);
        ret.left = max(ret.left, ret.sum);
        mnSum = min(mnSum, ret.sum);
    }

    suff = 0;
    for(i = s.size() - 1; i >= 0; i--)
    {
        if(s[i] == '1')
            suff++;
        else
            suff--;

        ret.right = max(ret.right, suff);
    }

    ret.left_right = max(ret.left, ret.right);

    return ret;
}

info combine(info a, info b)
{
    info ret;

    ret.sum = a.sum + b.sum;

    ret.left = max(a.left+b.sum, a.sum+b.left);

    ret.right = max(a.right+b.sum, a.sum+b.right);

    ret.left_right = max({a.left_right+b.sum, a.sum+b.left_right, a.left+b.right, a.right+b.left});

    ret.ans = max({a.ans, b.ans, ret.left, ret.right, ret.left_right, a.left+b.right, a.right+b.left});

    return ret;
}

void Build(int node, int bg, int ed)
{
    if(bg == ed)
    {
        Tree[node] = arr[bg];
        Tree[node].sum = max(0, Tree[node].sum);
        return;
    }

    int leftNode = 2*node, rightNode = 2*node+1;
    int mid = (bg + ed)/2;

    Build(leftNode, bg, mid);
    Build(rightNode, mid+1, ed);
    
    Tree[node] = combine(Tree[leftNode], Tree[rightNode]);
}

info Query(int node, int bg, int ed, int l, int r)
{
    if(l > ed || r < bg)
    {
        info ret;
        return ret;
    }

    if(l <= bg && ed <= r)
        return Tree[node];

    int leftNode = 2*node, rightNode = 2*node+1;
    int mid = (bg + ed)/2;

    info p1 = Query(leftNode, bg, mid, l, r);
    info p2 = Query(rightNode, mid+1, ed, l, r);

    return combine(p1, p2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, i, len, l, r;
    string s;

    cin >> n >> q;

    for(i = 1; i <= n; i++)    
    {
        cin >> len >> s;
        arr[i] = getInfo(s);
    }

    Build(1, 1, n);
    
    while(q--)
    {
        cin >> l >> r;

        cout << Query(1, 1, n, l, r).ans << "\n";
    }
}