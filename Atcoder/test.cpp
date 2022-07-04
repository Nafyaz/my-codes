#include<bits/stdc++.h>
using namespace std;
int n,m,last[1500002],x,ans=1e9;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(i-last[x]>m){
			ans=min(ans,x);
		}
		last[x]=i;
	}
	for(int i=0;i<=n;i++){
		if(last[i]<n-m+1){
			ans=min(i,ans);
		}
	}
	cout<<ans;
	return 0;
}