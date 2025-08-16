#include<bits/stdc++.h>
using namespace std;
#define ll long long

void call(ll n, ll sum)
{
    if(sum <= 0)
        return;

    if(sum > n)
    {
        call(n-1, sum-n);
        cout << n << " ";
    }
    else
        cout << sum << " ";
}

int main()
{
    ll T, n, i, a, Bsum, half, pref;

    cin >> T;

    while(T--)
    {
        cin >> n;

        vector<ll> v;

        for(i = 1; i <= n; i++)
        {
            cout << i << " ";
//            v.push_back(i);
        }
        cout << "\n";

        Bsum = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back(a);

            Bsum += a;
        }

        sort(v.begin(), v.end());

        half = (Bsum + n*(n+1)/2)/2;
        pref = 0;
        for(i = 0; i < n; i++)
        {
            pref += v[i];

            cout << v[i] << " ";

            if(pref >= half-n*(n+1)/2 && pref <= half)
                break;
        }

        call(n, half-pref);
        cout << "\n";
    }
}
