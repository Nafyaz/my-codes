#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, D, i;
    bool flag;
    string N;

    cin >> T;

    while(T--)
    {
        cin >> D >> N;

        flag = 0;
        for(i = 0; i < D; i++)
        {
            if(N[i] == '0' || N[i] == '5')
            {
                flag = 1;
                break;
            }
        }

        cout << (flag? "Yes\n" : "No\n");
    }
}
