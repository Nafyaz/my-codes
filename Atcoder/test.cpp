#include<bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;

int n,f[26][55][55],aux[55][55];
vector<string> g[26];
string t;

void calc(string s){
    memset(aux,0x3f,sizeof(aux));
    for(int i=0;i<n;i++)aux[i][i]=0;
    for(char c:s){
        for(int i=0;i<n;i++)for(int j=n;j>=i;j--)if(aux[i][j]!=inf){
            for(int k=j+1;k<=n;k++)if(f[c-'a'][j][k]!=inf){
                aux[i][k]=min(aux[i][k],aux[i][j]+f[c-'a'][j][k]);
            }
            aux[i][j]=inf;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s>>t;
    n=t.size();
    {
        int k;
        cin>>k;
        while(k--){
            char c;
            cin>>c;
            g[c-'a'].emplace_back();
            cin>>g[c-'a'].back();
        }
    }
    memset(f,0x3f,sizeof(f));
    for(int i=0;i<n;i++)f[t[i]-'a'][i][i+1]=0;
    bool edit=1;
    while(edit){
        edit=0;
        for(int i=0;i<26;i++){
            for(auto &s:g[i]){
                calc(s);
                for(int j=0;j<n;j++)for(int k=j+1;k<=n;k++)if(f[i][j][k]>aux[j][k]+1){
                    edit=1;
                    f[i][j][k]=aux[j][k]+1;
                }
            }
        }
    }
    calc(s);
    cout<<(aux[0][n]==inf?-1:aux[0][n]);

    return 0;
}
