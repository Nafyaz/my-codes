#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, a, mx[2], cnt[2];

    cin >> n;

    mx[0] = mx[1] = 0;
    cnt[0] = cnt[1] = 0;

    for(i = 0; i < n;  i++)
    {
        cin >> a;

        if(a == 0)
        {
            cnt[0]++;
            cnt[1]--;
        }
        else
        {
            cnt[0]--;
            cnt[1]++;
        }

        cnt[0] = max(0LL, cnt[0]);
        cnt[1] = max(0LL, cnt[1]);

        mx[0] = max(mx[0], cnt[0]);
        mx[1] = max(mx[1], cnt[1]);
    }

    cout << mx[0] + mx[1] + 1;
}
