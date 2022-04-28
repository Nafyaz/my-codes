#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, i, a, ans;
    cin >> n >> k;

    ll lastZero, newZero;

    ans = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a;

        if(i == 0)
        {
            lastZero = 0;
        }

        else if(a != -1)
        {
            newZero = i-a;

            if(newZero > lastZero)
            {
                ans += (newZero - lastZero)/k;
            }

            cout << "lastZero: " << lastZero << "; newZero: " << newZero << "; ans: " << ans << "\n";

            lastZero = newZero;
        }
    }

    ans += (n-1 - lastZero + 1) / k;

    cout << ans;
}
/*
10 3
0 -1 -1 -1 -1 5 -1 -1 -1 2
*/
