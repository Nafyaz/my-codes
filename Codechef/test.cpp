#include<bits/stdc++.h>
#define ll long long int
#define pa pair<ll,ll>
#define f first
#define s second
#define sz 100009
#define mod 1000000007 
const ll mx=400000000000000001ll;
#define vec array<ll,3>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

struct bol{
   int ans,left,right,sum,left_right;
   bol()
   {
    ans=left=right=sum=left_right=0;
   }
};

bol solve(string c)
{
  bol an;
  int mn=0; 
  for(char cc:c)
  {
    if(cc=='1')
      an.sum++;
    else
      an.sum--;
    an.ans=max(an.ans,an.sum-mn);
    an.left=max(an.left,an.sum);
    mn=min(mn,an.sum);
  }
  mn=0;
  for(int i=c.size()-1;i>=0;i--)
  {
   if(c[i]=='0')
    mn--;
  else
    mn++;
  an.right=max(an.right,mn);
  }
  return an;
}

std::vector<bol> arr, Tree;
bol combine(bol a, bol b)
{
  bol c;
  c.sum = a.sum + b.sum;

  c.left = max({a.left+b.sum, a.sum+b.left});
  
  c.right = max({a.right+b.sum, a.sum+b.right});
  
  c.left_right = max({a.left_right + b.sum, a.sum + b.left_right, a.left+b.right, a.right+b.left});
  
  c.ans = max({a.ans, b.ans, c.left, c.right, a.left+b.right, a.right+b.left, c.left_right});
  
  return c;
}

void prin(bol a,int l,int r)
{
  cout<<l<<" "<<r<<"\n";
  cout<<a.sum<<a.left<<a.right<<a.ans<<"\n";
}

void build(int node,int l,int r)
{
  if(l == r)
  {
    Tree[node].sum = max(arr[l].sum,0);
    
    Tree[node].left = arr[l].left;
    
    Tree[node].right = arr[l].right;
    Tree[node].left_right = max(arr[l].left, arr[l].right);
    Tree[node].ans = arr[l].ans;
   // prin(t[node],l);
    return;
  }
  int mid = (l+r)/2;
  build(2*node, l, mid);
  build(2*node+1, mid+1, r);
  Tree[node] = combine(Tree[2*node],Tree[2*node+1]);
  //prin(t[node],l,r);
  return;
}

bol query(int node,int l,int r,int le,int ri)
{
  if(l>r || l>ri || le>r || le>ri)
  {
    bol a;
    return a;
  }
  if(l>=le && r<=ri)
    return Tree[node];
  int mi=(l+r)/2;
  bol a=query(2*node,l,mi,le,ri);
  bol b=query(2*node+1,mi+1,r,le,ri);
  return combine(a,b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_case=1;
     //cin>>test_case;
    for(int cs=1;cs<=test_case;cs++)
    {
      int n,q;
      cin>>n>>q;
      arr.resize(n+1);
      t.resize(4*n);
      for(int i=1;i<=n;i++)
      {
        int len;
        string c;
        cin>>len>>c;
        arr[i]=solve(c);
      }
      build(1,1,n);
      while(q--)
      {
        int l,r;
        cin>>l>>r;
        cout<<query(1,1,n,l,r).ans<<"\n";
      }
    }
} 