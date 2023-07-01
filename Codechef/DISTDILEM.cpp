#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, a, sum;

    cin >> T;

    while(T--)
    {
        cin >> n;

        sum = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            sum += a;
        }

        for(i = 1; i <= sum; i++)
            sum -= i;

        cout << i-1 << "\n";
    }
}
