#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        if((2*i)%n == 0)
            cout << n << " ";
        else
            cout << (2*i)%n << " ";

        if((2*i+1)%n == 0)
            cout << n << "\n";
        else
            cout << (2*i+1)%n << "\n";
    }
}
