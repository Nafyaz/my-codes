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

int arr[MAXN];

void solve(int caseno)
{
    int n, i, zeros, fives, parity[2];

    cin >> n;

    parity[0] = parity[1] = zeros = fives = 0;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        zeros += (arr[i] == 0);
        fives += (arr[i]%5 == 0);

        if(arr[i]%5 != 0)
        {
            while(arr[i]%10 != 2)
                arr[i] += arr[i]%10;

            parity[(arr[i]/10)%2]++;
        }
        else
            arr[i] += arr[i]%10;
    }

    if(zeros == n)
    {
        cout << "Yes\n";
        return;
    }

    if(fives)
    {
        for(i = 0; i < n; i++)
        {
            if(arr[i] != arr[0])
            {
                cout << "No\n";
                return;
            }
        }

        cout << "Yes\n";
        return;
    }

    if((zeros > 0 && zeros < n) || (parity[0] && parity[1]))
        cout << "No\n";
    else
        cout << "Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}
