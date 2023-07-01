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
#define MAXN 200005

LL a[MAXN], b[MAXN];
pLL minA[MAXN], minB[MAXN];
vector<pLL> dollar, pound;
vector<LL> dollarPref, poundPref;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, m, k, s, type, c, i;
    LL low, high, mid, ans;
    LL dSize, ansDSize, dCost, pCost, burl;

    cin >> n >> m >> k >> s;

    minA[0] = {INT_MAX, 0};
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        
        if(a[i] < minA[i-1].ff)
            minA[i] = {a[i], i};
        else
            minA[i] = minA[i-1];
    }

    minB[0] = {INT_MAX, 0};
    for(i = 1; i <= n; i++)
    {
        cin >> b[i];
        
        if(b[i] < minB[i-1].ff)
            minB[i] = {b[i], i};
        else
            minB[i] = minB[i-1];
    }

    for(i = 1; i <= m; i++)
    {
        cin >> type >> c;
        if(type == 1)
            dollar.push_back({c, i});
        else
            pound.push_back({c, i});
    }

    sort(dollar.begin(), dollar.end());
    sort(pound.begin(), pound.end());

    dollarPref.push_back(0);
    for(i = 0; i < dollar.size(); i++)
        dollarPref.push_back(dollarPref.back() + dollar[i].ff);
    
    poundPref.push_back(0);
    for(i = 0; i < pound.size(); i++)
        poundPref.push_back(poundPref.back() + pound[i].ff);

    low = 1;
    high = n;
    ans = dSize = -1;
    while(low <= high)
    {
        mid = (low + high)/2;

        dSize = -1;
        for(i = 0; i <= k; i++)
        {
            if(i >= dollarPref.size() || k-i >= poundPref.size())
                continue;

            dCost = dollarPref[i];
            pCost = poundPref[k-i];

            burl = minA[mid].ff*dCost + minB[mid].ff*pCost;

            if(burl <= s)
            {
                dSize = i;
                break;
            }
        }

        if(dSize != -1)
        {
            ans = mid;
            ansDSize = dSize;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    if(ans == -1)
    {
        cout << ans << "\n";
        return 0;
    }

    cout << ans << "\n";
    for(i = 0; i < ansDSize; i++)
        cout << dollar[i].ss << " " << minA[ans].ss << "\n";
    for(i = 0; i < k-ansDSize; i++)
        cout << pound[i].ss << " " << minB[ans].ss << "\n";
}