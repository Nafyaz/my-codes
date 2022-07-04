#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

vector<ll> arr;

void solve(ll caseno)
{
    ll n, i, j, k, x, zero;

    cin >> n;

    arr.clear();
    queue<ll> qPos, qNeg;
    zero = 0;
    for(i = 0; i < n; i++)
    {
        cin >> x;
        if(x > 0)
            qPos.push(x);
        else if(x < 0)
            qNeg.push(x);
        else
            zero++;
    }

    if(qPos.size() >= 3 || qNeg.size() >= 3)
    {
        cout << "NO\n";
        return;
    }

    while(!qNeg.empty())
    {
        arr.push_back(qNeg.front());
        qNeg.pop();
    }
    for(i = 0; i < 3 && i < zero; i++)
        arr.push_back(0);
    while(!qPos.empty())
    {
        arr.push_back(qPos.front());
        qPos.pop();
    }

    for(i = 0; i < arr.size(); i++)
    {
        for(j = i+1; j < arr.size(); j++)
        {
            for(k = j+1; k < arr.size(); k++)
            {
                if(find(arr.begin(), arr.end(), arr[i]+arr[j]+arr[k]) == arr.end())
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}