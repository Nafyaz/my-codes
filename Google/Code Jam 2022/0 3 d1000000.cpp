#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll s[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, n, i, prev;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> s[i];

        sort(s, s+n);

        prev = 0;
        for(i = 0; i < n; i++)
            prev = min(prev+1, s[i]);

        cout << "Case #" << ++caseno << ": " << prev << "\n";
    }
}
