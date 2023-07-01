#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, i, j;

    cin >> n >> m;

    for(i = 1; i <= n+m-1; i++)
    {
        for(j = 1; j <= i; j++)
        {
            if(i-j+1 <= n && j <= m)
                cout << i-j+1 << " " << j << "\n";
        }
    }
}
