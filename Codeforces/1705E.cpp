#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 200025

bitset<MAXN> bs, temp, zero;
int arr[MAXN];

bitset<MAXN> Add(bitset<MAXN> a, bitset<MAXN> b)
{
    bitset<MAXN> carry;
    while(b != zero)
    {
        carry = a&b;
        a = a^b;
        b = carry << 1;
    }

    return a;
}

bitset<MAXN> Sub(bitset<MAXN> a, bitset<MAXN> b)
{
    b = ~b;
    b = Add(b, bitset<MAXN>(1));

    return Add(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, k, l, i, ans;

    cin >> n >> q;

    for(i = 0; i < n; i++)
    {
        cin >> arr[i];

        temp[arr[i]] = 1;
        bs = Add(bs, temp);
        temp[arr[i]] = 0;
    }

    while(q--)
    {
        cin >> k >> l;

        temp[arr[k-1]] = 1;
        bs = Sub(bs, temp);
        temp[arr[k-1]] = 0;

        arr[k-1] = l;
        temp[arr[k-1]] = 1;
        bs = Add(bs, temp);
        temp[arr[k-1]] = 0;

        ans = 0;
        for(i = 0; i < MAXN; i++)
        {
            if(bs[i])
                ans = i;
        }

        cout << ans << "\n";
    }
}