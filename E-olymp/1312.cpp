#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[3], x[3];

    cin >> a[0] >> a[1] >> a[2] >> x[0] >> x[1];

    sort(a, a+3);
    sort(x, x+2);

    if(a[0] <= x[0] && a[1] <= x[1])
        cout << "YES\n";
    else
        cout << "NO\n";
}
