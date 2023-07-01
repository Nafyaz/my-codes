#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        double price;
        cin >> price;
        double output = price * 1.15;
        cout << fixed << setprecision(2) << output << endl;
    }
}
