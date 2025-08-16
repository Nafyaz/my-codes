#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int n, k, a;
int sLevel[10], sLoyalty[10], sLoyalty2[10];
double ans;

void calc()
{
    int i, mask, levelSum, votes;
    double total = 0, part;
    for(mask = 0; mask < (1 << n); mask ++)
    {
        part = 1;
        levelSum = votes = 0;
        for(i = 0; i < n; i++)
        {
            if(mask & (1 << i))            
            {
                part *= sLoyalty2[i]/100.0;
                votes ++;
            }
            else
            {
                part *= (100 - sLoyalty2[i])/100.0;
                levelSum += sLevel[i];
            }
        }

        if(2*votes <= n)
            part *= double(a)/(a + levelSum);
        
        total += part;
    }

    ans = max(ans, total);
}

void call(int pos, int rem)
{
    if(pos == n)
    {
        calc();
        return;
    }

    int i, b;
    for(i = 0; i <= rem; i++)
    {
        sLoyalty2[pos] = min(100, sLoyalty[pos] + i*10);
        call(pos+1, rem - i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i;

    cin >> n >> k >> a;

    for(i = 0; i < n; i++)
    {
        cin >> sLevel[i] >> sLoyalty[i];
    }
    
    call(0, k);

    cout << fixed << setprecision(10) <<  ans << "\n";
}