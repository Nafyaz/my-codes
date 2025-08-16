#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll generator[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, sum, i;

    for(i = 1; i < 100005; i++)
    {
        n = i;
        for(sum = n; n; n /= 10)
            sum += (n%10);

        if(sum < 100005 && generator[sum] == 0)
            generator[sum] = i;
    }

    cin >> T;

    while(T--)
    {
        cin >> n;

        cout << generator[n] << "\n";
    }
}
