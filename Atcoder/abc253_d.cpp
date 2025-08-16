#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b, ans, cnt, lcm;

    cin >> n >> a >> b;

    ans = n*(n+1)/2;

    cnt = n/a;
    ans -= a*cnt*(cnt+1)/2;

    cnt = n/b;
    ans -= b*cnt*(cnt+1)/2;

    lcm = a*b/__gcd(a, b);
    cnt = n/lcm;
    ans += lcm*cnt*(cnt+1)/2;

    cout << ans;
}