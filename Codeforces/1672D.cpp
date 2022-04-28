#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005];
ll b[200005];
ll bCnt[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, j, val, aCnt;
    bool flag;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];
        for(i = 0; i < n; i++)
            cin >> b[i];

        fill(bCnt, bCnt+n, 0);
        flag = 1;
        for(i = n-1, j = n-1; i >= 0;)
        {
            val = a[i];
            aCnt = 0;

            while(i >= 0 && a[i] == val)
            {
                i--;
                aCnt++;
            }

            while(j >= 0 && b[j] == val)
            {
                j--;
                bCnt[val]++;
            }

            bCnt[val] -= aCnt;

            if(bCnt[val] < 0)
            {
                flag = 0;
                break;
            }
        }

        if(j > 0)
            flag = 0;

        cout << (flag? "Yes\n" : "No\n");
    }
}
