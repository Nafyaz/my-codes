#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 32768

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, z, ans[N], i, epochs = sqrt(N);

    fill(ans, ans+N, INT_MAX);

    ans[0] = 0;

    while(epochs--)
    {
        for(i = N-1; i >= 0; i--)
        {
            ans[i] = min({ans[i], ans[(i+1)%N]+1, ans[(i*2)%N]+1});
        }
    }

//    for(i = 0; i < 4; i++)
//        cout << ans[i] << " ";
//    cout << "\n";

    cin >> n;

    while(n--)
    {
        cin >> a;

        cout << ans[a] << " ";
    }
}
