#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, l, cnt[4], mn, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        map<ll, ll> freq;

        for(i = 0; i < n; i++)
        {
            cin >> l;

            freq[l] = (freq[l] + 1) % 4;
        }

        cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
        for(auto u : freq)
            cnt[u.ss]++;

//        cout << cnt[1] << "; " << cnt[2] << "; " << cnt[3] << "\n";

        cnt[1] += cnt[3]/2*2;
        cnt[3] %= 2;
        cnt[2] %= 2;

        if(cnt[2] && cnt[3])
        {
            cnt[2] = 0;
            cnt[3] = 0;
            cnt[1]++;
        }

        ans = 0;
        if(cnt[3])
            ans = 1;
        if(cnt[2] && cnt[1])
        {
            ans = 1;
            cnt[1]--;
        }
        else if(cnt[2])
            ans = 2;

        ans += cnt[1]/2*2;
        cnt[1] = cnt[1]%2;
        ans += 3*cnt[1];

        cout << ans << "\n";
    }
}
