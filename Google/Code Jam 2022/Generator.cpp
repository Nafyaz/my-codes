#include<bits/stdc++.h>
using namespace std;
#define ll long long

string getStr()
{
    string ret;
    ll len = 4;
    while(len--)
        ret += char('A' + rand()%26);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("in.txt", "w", stdout);

    ll T, n, i, j;

    T = rand()%100;
    cout << T << "\n";
    for(i = 0; i < T; i++)
    {
        n = rand() % 6;
        cout << n << "\n";

        for(j = 0; j < n; j++)        
            cout << getStr() << " ";
        cout << "\n";
    }
}