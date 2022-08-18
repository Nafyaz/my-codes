#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << ": " << x << "; "
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 2000006

int P[20];
vector<int> v, u;

void solve(int caseno)
{
    int n, i, x;

    cin >> n;

    for(i = 1; i <= P[n]; i++)
        v.push_back(i);

    while(v.size())
    {
        if(v.size() == 1)
        {
            cout << "! " << v[0] << "\n";

            v.clear();
            return;
        }

        if(v.size() == 2)
        {
            cout << "? " << v[0] << " " << v[1] << "\n";
            cin >> x;

            if(x == 1)
                cout << "! " << v[0] << "\n";
            else
                cout << "! " << v[1] << "\n";

            v.clear();
            return;
        }

        for(i = 0; i < v.size(); i += 4)
        {
            cout << "? " << v[i] << " " << v[i+2] << "\n";
            cin >> x;

            if(x == 0)
            {
                cout << "? " << v[i+1] << " " << v[i+3] << "\n";
                cin >> x;

                if(x == 1)
                    u.push_back(v[i+1]);
                else
                    u.push_back(v[i+3]);
            }
            else if(x == 1)
            {
                cout << "? " << v[i] << " " << v[i+3] << "\n";
                cin >> x;

                if(x == 1)
                    u.push_back(v[i]);
                else
                    u.push_back(v[i+3]);
            }
            else
            {
                cout << "? " << v[i+1] << " " << v[i+2] << "\n";
                cin >> x;

                if(x == 1)
                    u.push_back(v[i+1]);
                else
                    u.push_back(v[i+2]);
            }
        }

        swap(u, v);
        u.clear();
    }
}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    int T = 1, caseno = 0;

    P[0] = 1;
    for(int i = 1; i < 20; i++)
        P[i] = 2*P[i-1];

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}