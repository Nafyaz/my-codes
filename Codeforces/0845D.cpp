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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, i, type, currSpeed, ans, newLimit;
    stack<int> speedLimits;
    int noOvertake;

    cin >> n;

    noOvertake = 0;
    ans = 0;
    for(i = 0; i < n; i++)
    {
        cin >> type;

        if(type == 1)        
        {
            cin >> currSpeed;

            while(!speedLimits.empty())
            {
                if(speedLimits.top() < currSpeed)
                {
                    ans++;
                    speedLimits.pop();
                }
                else
                    break;
            }
        }
        else if(type == 2)
        {
            ans += noOvertake;
            noOvertake = 0;
        }
        else if(type == 3)
        {
            cin >> newLimit;
            if(currSpeed > newLimit)
                ans++;
            else
                speedLimits.push(newLimit);
        }
        else if(type == 4)
            noOvertake = 0;
        else if(type == 5)
        {
            while(!speedLimits.empty())
                speedLimits.pop();
        }
        else
            noOvertake ++;
    }

    cout << ans << "\n";
}