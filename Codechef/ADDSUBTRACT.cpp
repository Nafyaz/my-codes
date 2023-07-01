#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

LL arr[MAXN];
vector<vector<LL>> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, j, k;

    cin >> n;

    for(i = 0; i < n; i++)    
        cin >> arr[i];
    
    while(1)
    {
        bool flag = 0;
        vector<pLL> odds;

        for(i = 0; i < n; i++)
        {
            if(arr[i]%2 == 1)            
                odds.push_back({arr[i], i});

            if(arr[i] != 0)
                flag = 1;
        }

        if(flag == 0)
            break;

        if(!odds.empty())
        {
            sort(odds.begin(), odds.end());

            ans.push_back(vector<LL>());
            for(i = 0; i < odds.size(); i++)
            {
                arr[odds[i].ss] -= arr[odds[0].ss];
                ans.back().push_back(odds[i].ss+1);
            }
        }

        for(i = 0; i < n; i++)
            arr[i] /= 2;
    }

    cout << ans.size() << "\n";

    for(i = 0; i < ans.size(); i++)
    {
        cout << ans[i].size() << "\n";

        k = ans[i][0];
        sort(ans[i].begin(), ans[i].end());

        for(j = 0; j < ans[i].size(); j++)        
            cout << ans[i][j] << " ";
        cout << "\n";

        cout << "- " << k << "\n";
    }
}