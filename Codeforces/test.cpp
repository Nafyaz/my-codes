#include<bits/stdc++.h>
using namespace std;
#define sz 200009
set<int>mp[sz];
int ans,arr[sz];
std::vector<int> v[sz];
void solve(int node,int par)
{
  int fs=0;
  mp[node].insert(arr[node]);
  for(int u:v[node])
  {
    if(u!=par)
    {
      arr[u]^=arr[node];
      solve(u,node);
      if(mp[u].size()>mp[node].size())
        swap(mp[u],mp[node]);
      for(int vv:mp[u])
        if(mp[node].find(vv^arr[node]^arr[par])!=mp[node].end())
         fs=1;
      if(!fs)
        for(int vv:mp[u])
          mp[node].insert(vv);
    }
  }
  if(fs)
    ans++,mp[node].clear();
} 
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>arr[i];
    for(int i=2;i<=n;i++)
    {
      int a,b;
      cin>>a>>b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    solve(1,0);
    cout<<ans;
}