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

int n, m;
bool taken[12];

void Print()
{
    for(int i = 1; i <= m; i++)
    {
        if(taken[i])
            cout << i << " ";
    }
    cout << "\n";
}

void call(int pos, int prev)
{
    if(pos == n+1)
    {
        Print();
        return;
    }

    for(int i = prev+1; i <= m; i++)
    {
        taken[i] = 1;
        call(pos+1, i);
        taken[i] = 0;
    }
}

void solve(int caseno)
{
    cin >> n >> m;

    call(1, 0);
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

