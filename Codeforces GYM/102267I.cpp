#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s;
ll parent[140005];

ll dfs(ll p, ll bg)
{
    ll node = 0;
    while(bg < s.size() && s[bg] != '(' && s[bg] != ')')
    {
        node = node*10 + (s[bg] - '0');
        bg++;
    }

    // cout << p << " " << node << endl;

    parent[node] = p;

    while(bg < s.size() && s[bg] == '(')
    {
        bg = dfs(node, bg+1) + 1;

        // if(node == 2)
        //     cout << bg << "\n";
    }

    return bg;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i;

    cin >> n >> s;

    dfs(0, 0);

    for(i = 1; i <= n; i++)
        cout << parent[i] << " ";
}