#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005], Tree[4*200005];

void build(int node, int s, int e)
{
    if(s == e)
    {
        Tree[node] = a[s];
        return;
    }

    int mid = (s+e)/2, left = 2*node+1, right = 2*node+2;

    build(left, s, mid);
    build(right, mid+1, e);

    Tree[node] = min(Tree[left], Tree[right]);
}

void update(int node, int s, int e, int idx, int val)
{
    if(s == e)
    {
        Tree[node] = val;
        return;
    }

    int mid = (s+e)/2, left = 2*node+1, right = 2*node+2;

    if(idx <= mid)
        update(left, s, mid, idx, val);
    else
        update(right, mid+1, e, idx, val);

    Tree[node] = min(Tree[left], Tree[right]);
}

int query(int node, int s, int e, int l, int r)
{
    if(l > e || r < s)
        return INT_MAX;

    if(l <= s && r >= e)
        return Tree[node];

    int mid = (s+e)/2, left = 2*node+1, right = 2*node+2;
    int p1 = query(left, s, mid, l, r);
    int p2 = query(right, mid+1, e, l, r);

    return min(p1, p2);
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    ll n, i, ans, shots, temp1, temp2, x, y;
    cin >> n;
    for(i = 2; i <= n+1; i++)
        cin >> a[i];

    a[0] = a[1] = INT_MAX;
    a[n+2] = a[n+3] = INT_MAX;

    ans = INT_MAX;
    for(i = 2; i < n+1; i++)
    {
        x = a[i];
        y = a[i+1];

        shots = (2*x-y + 2)/3;
        x = max(0LL, x - 2*shots);
        y = max(0LL, y - shots);
        
        shots += (y+1)/2;
        ans = min(ans, shots);

        x = a[i+1];
        y = a[i];

        shots = (2*x-y + 2)/3;
        x = max(0LL, x - 2*shots);
        y = max(0LL, y - shots);
        
        shots += (y+1)/2;
        ans = min(ans, shots);
    }


    build(0, 0, n+3);

    for(i = 2; i <= n+1; i++)
    {
        shots = a[i]/2;
        update(0, 0, n+3, i, a[i] - 2*shots);
        update(0, 0, n+3, i-1, max(0LL, a[i-1] - shots));
        update(0, 0, n+3, i+1, max(0LL, a[i+1] - shots));

        if(a[i] & 1)
        {
            shots++;

            temp1 = query(0, 0, n+3, i-1, i-1);
            temp2 = query(0, 0, n+3, i-2, i-2);
            update(0, 0, n+3, i-1, max(0LL, a[i-1] - 2));
            update(0, 0, n+3, i-2, max(0ll, a[i-2] - 1));
            update(0, 0, n+3, i, INT_MAX);
            ans = min(ans, shots + (query(0, 0, n+3, 0, n+3) + 1) / 2);

            update(0, 0, n+3, i-1, temp1);
            update(0, 0, n+3, i-2, temp2);

            temp1 = query(0, 0, n+3, i+1, i+1);
            temp2 = query(0, 0, n+3, i+2, i+2);
            update(0, 0, n+3, i+1, max(0LL, a[i+1] - 2));
            update(0, 0, n+3, i+2, max(0ll, a[i+2] - 1));
            update(0, 0, n+3, i, INT_MAX);
            ans = min(ans, shots + (query(0, 0, n+3, 0, n+3) + 1) / 2);
        }
        else
        {
            update(0, 0, n+3, i, INT_MAX);
            ans = min(ans, shots + (query(0, 0, n+3, 0, n+3) + 1) / 2);
        }

        update(0, 0, n+3, i, a[i]);
        update(0, 0, n+3, i-1, a[i-1]);
        update(0, 0, n+3, i-2, a[i-2]);
        update(0, 0, n+3, i+1, a[i+1]);
        update(0, 0, n+3, i+2, a[i+2]);
    }

    cout << ans << "\n";
}
