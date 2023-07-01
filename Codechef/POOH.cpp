#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define MOD 1000000007
#define MAXN 300005

ll arr[MAXN], brr[MAXN];
ll pref[MAXN];

void solve(ll caseno)
{
    ll n, k, i, pos, left, right;

    cin >> n >> k;

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];

        pref[i] = pref[i-1] + arr[i];
    }   

    ordered_set<ll> cuts;
    for(i = 1; i <= k; i++)
    {
        cin >> brr[i];
        cuts.insert(brr[i]);
    }

    multiset<ll> segments;
    for(i = 0; i < k; i++)
    {
        if(i == 0)
            segments.insert(pref[*(cuts.find_by_order(i))]);
        else
            segments.insert(pref[*(cuts.find_by_order(i))] - pref[*(cuts.find_by_order(i-1))]);
    }
    segments.insert(pref[n] - pref[*(cuts.find_by_order(k-1))]);

    // cout << "cuts:\n";
    // for(auto u : cuts)
    //     cout << u << " ";
    // cout << "\n";
    // cout << "segments:\n";
    // for(auto u : segments)
    //     cout << u << " ";
    // cout << "\n\n";

    stack<ll> ans;
    ans.push(*segments.rbegin());
    for(i = k; i > 1; i--)
    {
        pos = cuts.order_of_key(brr[i]);

        if(pos == 0)
            left = 1;
        else
            left = *(cuts.find_by_order(pos-1)) + 1;
        
        if(pos+1 == cuts.size())
            right = n;
        else
            right = *(cuts.find_by_order(pos+1));

        segments.erase(pref[right] - pref[brr[i]]);
        segments.erase(pref[brr[i]] - pref[left-1]);
        segments.insert(pref[right] - pref[left-1]);

        ans.push(*segments.rbegin());

        cuts.erase(brr[i]);

        // show(i);
        // show(brr[i]);
        // show(left);
        // show(right);
        // cout << "\ncuts:\n";
        // for(auto u : cuts)
        //     cout << u << " ";
        // cout << "\n";
        // cout << "segments:\n";
        // for(auto u : segments)
        //     cout << u << " ";
        // cout << "\n\n";
    }

    while(!ans.empty())
    {
        cout << ans.top() << "\n";
        ans.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T = 1, caseno = 0;

    // cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}