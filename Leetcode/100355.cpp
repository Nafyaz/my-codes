#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k) returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

int dp[3003][3003];
set<int> st;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string source, pattern;
    int n, x;
    vector<int> targetIndices;

    cin >> source >> pattern >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        targetIndices.push_back(x);
    }

// -----------------------------------------------------------

    int prev = -1, gotFree, gotMatch;
    for (int i = 0; i < pattern.size(); i++)
    {
        gotFree = 0;
        gotMatch = 0;
        for (int j = prev+1; j < source.size(); j++)
        {
            if (gotMatch == 1)
            {
                dp[j] = dp[j-1];
                if (gotFree == 1)
                    continue;
                
                if (source[j] == pattern[i] && st.find(j) == st.end())
                {
                    gotFree = 1;
                    dp[j]--;
                }
                
                continue;
            }
            
            if (source[j] != pattern[i])
                continue;
            
            if (gotMatch == 0)
            {
                gotMatch = 1;
                prev = j;
            }
            
            if (st.find(j) == st.end())
            {
                gotFree = 1;
                dp[j] = (j == 0? 0 : dp[j-1]);
            }
            else
                dp[j] = (j == 0? 1 : dp[j-1] + 1);
        }
    }
    
    cout << st.size() - dp[pattern.size()-1][source.size()-1] << "\n";
}
