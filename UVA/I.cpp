#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 5000006

bool isTriplet[MAXN];

void solve(int caseno)
{
    int n;
    cin >> n;

    cout << (isTriplet[n]? "YES" : "NO") << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    for(long long i = 1; i*i < MAXN; i++)
    {
        for(long long j = i+1; i*i + j*j < MAXN; j++)
        {
            for(long long k = 1; (i*i + j*j)*k < MAXN; k++)
            isTriplet[(i*i + j*j)*k] = true;
        }
            
    }

    // int c = 0;
    // for (long long i = 0; i < MAXN; i++)
    // {
    //     if (isTriplet[i])
    //         c++;
    // }
    // cout << c << "\n";

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}