#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 100005

void solve(int caseno)
{
    int n, i, temp, zeros;
    vector<int> a, b;

    cin >> n;

    zeros = 0;
    for(i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp == 0)
            zeros++;
        else
            a.push_back(temp);
    }

    while(a.size() > 1)
    {
        b.clear();
        
        if(zeros)
        {
            b.push_back(a[0]);
            zeros--;
        }

        for(i = 1; i < a.size(); i++)
            b.push_back(a[i] - a[i-1]);
        
        sort(b.begin(), b.end());

        a.clear();
        for(i = 0; i < b.size(); i++)
        {
            if(b[i] == 0)
                zeros++;
            else
                a.push_back(b[i]);
        }

        // cout << "a:\n";
        // for(i = 0; i < a.size(); i++)
        //     cout << a[i] << " ";
        // cout << "\n";
    }

    if(a.size() == 0)
        cout << "0\n";
    else
        cout << a[0] << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}