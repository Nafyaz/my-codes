#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int n;
int arr[12];
int sign[12];

bool call(int pos)
{
    if(pos == n)
    {
        int sum = 0;
        bool allZero = 1;
        for(int i = 0; i < n; i++)
        {
            sum += sign[i]*arr[i];

            if(sign[i] != 0)
                allZero = 0;
        }

        return (allZero == 0 && sum == 0);
    }

    for(int i = -1; i <= 1; i++)
    {
        sign[pos] = i;
        if(call(pos+1))
            return 1;
    }

    return 0;
}

void solve(int caseno)
{
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    if(call(0))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}