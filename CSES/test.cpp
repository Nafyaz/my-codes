#include<bits/stdc++.h>
using namespace std;
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define vi vector<ll>
#define vll vector<long long>
#define vc vector<char>
#define usc unordered_set<char>
#define sc set<char>
#define umci unordered_map<char,ll>
#define umii unordered_map<ll,ll>
#define ll long long
#define dbl double
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
ll INF=1e9+7;
ll n;
ll v[105];
ll dp[1000005];
 
ll func(ll sum)
{
    if(sum==0) return 1;
    if(dp[sum]!=-1) return dp[sum];
    ll ans=0;
    for(ll d=0;d<n;d++)
    {
        if(sum>=v[d])
        {
            ans+=func(sum-v[d]);
            ans%=INF;
        }
    }
    return dp[sum]=ans;
}
int main()
{
    fastio;
    memset(dp,-1,sizeof(dp));
    ll x;
    cin>>n>>x;
    for(ll d=0;d<n;d++){
        cin>>v[d];
    }
    cout<<func(x)<<endl;
    return 0;
}