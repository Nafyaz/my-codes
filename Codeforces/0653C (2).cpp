#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define INF 1000000000000015
#define MOD 1000000007
#define MAXN 150005

LL a[MAXN], b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, i, j, k, flag;
    vector<int> problem;
    vector<pii> ans;

    cin >> n;

    for(i = 1; i <= n; i++)    
    {
        cin >> a[i];

        if(i > 1)
        {
            if(i%2 == 0 && a[i-1] >= a[i])
                problem.insert(i-1);

            if(i%2 == 1 && a[i-1] <= a[i])
                problem.insert(i-1);
        }
    }

    if(problem.size() > 4)
    {
        cout << "0\n";
        return 0;
    }

    for(i = 0; i < pos.size(); i++)
    {
        
    }
}