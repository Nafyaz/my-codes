//follow dreamoon_love_AA
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, x, y, xSq, ySq, xSum, ySum;

    xSq = ySq = xSum = ySum = 0;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> x >> y;

        xSq += x*x;
        ySq += y*y;
        xSum += x;
        ySum += y;
    }

    cout << n*(xSq+ySq) - xSum*xSum - ySum*ySum;
}