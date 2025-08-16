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

string A[1003];

void solve(int caseno)
{
    int n, i, j;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> A[i];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(A[i][j] == 'W' && A[j][i] != 'L')
            {
                cout << "incorrect\n";
                return;
            }

            if(A[i][j] == 'L' && A[j][i] != 'W')
            {
                cout << "incorrect\n";
                return;
            }

            if(A[i][j] == 'D' && A[j][i] != 'D')
            {
                cout << "incorrect\n";
                return;
            }
        }
    }

    cout << "correct\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

//    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
