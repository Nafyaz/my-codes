#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, a[200005];

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> a[i];

        for(i = n-2; i >= 0; i -= 2)
        {
            if(a[i] > a[i+1])
                swap(a[i], a[i+1]);
        }

        cout << (is_sorted(a, a+n)? "YES\n" : "NO\n");
    }
}