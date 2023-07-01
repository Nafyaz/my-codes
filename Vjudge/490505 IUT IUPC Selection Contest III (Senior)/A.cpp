#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    vector<ll> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    ll cnt = 0;
    string s;

    for(auto p : primes)
    {
        cout << "? " << p << "\n";
        cin >> s;

        if(s == "yes")
        {
            cnt++;
            if(cnt > 1)
            {
                cout << "! composite";
                return 0;
            }

            if(p*p <= 100)
            {
                cout << "? " << p*p << "\n";
                cin >> s;

                if(s == "yes")
                {
                    cout << "! composite";
                    return 0;
                }
            }
        }
    }

    cout << "! prime";
}
