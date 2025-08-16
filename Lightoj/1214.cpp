#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isDivisible(string a, ll b)
{
    ll rem = 0, i;

    for(i = 0; i < a.size(); i++)
    {
        rem = 10*rem + a[i] - '0';
        rem %= b;
    }

    return (rem == 0);
}

int main()
{
    ll T, caseno = 0;

    string a;
    ll b;

    cin >> T;

    while(T--)
    {
        cin >> a >> b;
        if(a[0] == '-')
            a = a.substr(1, a.size() - 1);

        b = abs(b);

        cout << "Case " << ++caseno << ": " << (isDivisible(a, b)? "divisible\n" : "not divisible\n");
    }
}
