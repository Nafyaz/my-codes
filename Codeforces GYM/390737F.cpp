#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 300005

int arr[MAXN], brr[MAXN];
int movedCount[MAXN];

void solve(int caseno)
{
    int n, i, j;

    cin >> n;

    for(i = 0; i < n; i++)
        cin >> arr[i];
    for(i = 0; i < n; i++)
        cin >> brr[i];

    fill(movedCount, movedCount+n, 0);
    for(i = 0, j = 0; i < n; i++)
    {
        while(j < n && arr[i] > brr[j])
        {
            movedCount[brr[j]]++;
            j++;
        }

        if(j < n && arr[i] == brr[j])
            j++;
        else
        {
            if(movedCount[arr[i]] == 0)
            {
                cout << "NO\n";
                return;
            }

            movedCount[arr[i]]--;
        }
    }

    cout << "YES\n";
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