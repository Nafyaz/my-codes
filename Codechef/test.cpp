#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define ff first 
#define ss second 
#define ld long double
#define rep(i, a, b) for (long long i = a; i < b; i++)
#define all(v) v.begin(),v.end()
int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll o1,o2;
        cin>>o1>>o2;
        ll n=o1*o2;
        vector<ll>v(2*n+1);
        vector<ll>vec(n+1);
        v[0]=0;
        rep(i,1,n+1)
        {
            ll x;
            cin>>x;
            vec[i]=x;
            if(x==1)
            v[i]=v[i-1]+1;
            else v[i]=v[i-1];
        }
        rep(i,n+1,2*n+1)
        {
            if(vec[i-n]==1)
            v[i]=v[i-1]+1;
            else v[i]=v[i-1];
        }
        bool check=false;
        ll j=0;
        ll y=o2;
        while(y>0)
        {
            ll x=o1;
            ll i=o2+j;
            ll cnt=0;
            while(x>0)
            {
                if(v[i]-v[i-o2]>(ll)(o2/2))
                {cnt++;}
                x--;
                i+=o2;
            }
            if(cnt>o1/2)
            {check=true;
           
            break;
            }
            y--;
            j++;
        }
        if(check)
        cout<<"1\n";
        else cout<<"0\n";

    }   
}