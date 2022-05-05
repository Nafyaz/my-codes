#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k;
string s[20];

bool call(ll mask, char c)
{
    ll cnt = 0;
    ll i;

    for(i = 0; i < n; i++)
    {
        if(mask & (1LL << i) && s[i].find(c) != -1)
            cnt++;
    }

    return (cnt == k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, mask, ans, cnt;
    char c;

    cin >> n >> k;

    for(i = 0; i < n; i++)
        cin >> s[i];

    ans = 0;
    for(mask = 0; mask < (1LL << n); mask++)
    {
        if(__builtin_popcount(mask) < k)
            continue;

        cnt = 0;
        for(c = 'a'; c <= 'z'; c++)        
            cnt += call(mask, c);

        ans = max(ans, cnt);
    }

    cout << ans << "\n";
}