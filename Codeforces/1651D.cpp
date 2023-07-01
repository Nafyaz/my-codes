#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

map<ll, set<ll>> posSet, negSet;
map<ll, vector<ll>> pos, neg;

ll findMissingXPos(ll st, ll ed, ll c)
{
    if(st == ed)
    {
        ll idx = lower_bound(pos[c].begin(), pos[c].end(), st) - pos[c].begin();
        if(idx >= pos[c].size() || pos[c][idx] != st)
            return st;
        else
            return -1;
    }

    ll cnt = upper_bound(pos[c].begin(), pos[c].end(), ed) - lower_bound(pos[c].begin(), pos[c].end(), st);
    ll range = ed - st + 1;

    if(range == cnt)
        return -1;

    ll mid = (st + ed)/2;
    ll left = findMissingXPos(st, mid, c);

    if(left != -1)
        return left;

    ll right = findMissingXPos(mid+1, ed, c);
    return right;
}

ll findMissingXNeg(ll st, ll ed, ll c)
{
    if(st == ed)
    {
        ll idx = lower_bound(neg[c].begin(), neg[c].end(), st) - neg[c].begin();
        if(idx >= neg[c].size() || neg[c][idx] != st)
            return st;
        else
            return -1;
    }

    ll cnt = upper_bound(neg[c].begin(), neg[c].end(), ed) - lower_bound(neg[c].begin(), neg[c].end(), st);
    ll range = ed - st + 1;

    if(range == cnt)
        return -1;

    ll mid = (st + ed)/2;
    ll left = findMissingXNeg(st, mid, c);

    if(left != -1)
        return left;

    ll right = findMissingXNeg(mid+1, ed, c);
    return right;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, x[200005], y[200005], dist, st, ed, c, missing;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];

        posSet[y[i]-x[i]].insert(x[i]);
        negSet[x[i]+y[i]].insert(x[i]);
    }

    for(auto u : posSet)
    {
        for(auto v : u.ss)
            pos[u.ff].push_back(v);
    }
    for(auto u : negSet)
    {
        for(auto v : u.ss)
            neg[u.ff].push_back(v);
    }

    for(i = 0; i < n; i++)
    {
        for(dist = 1;; dist++)
        {
            st = x[i] - dist;
            ed = x[i];
            c = y[i] + dist - x[i];
            missing = findMissingXPos(st, ed, c);
            if(missing != -1)
            {
                cout << missing << " " << missing + c << "\n";
                break;
            }

            c = x[i] - dist + y[i];
            missing = findMissingXNeg(st, ed, c);
            if(missing != -1)
            {
                cout << missing << " " << -missing + c << "\n";
                break;
            }

            st = x[i];
            ed = x[i] + dist;
            c = y[i] - x[i] - dist;
            missing = findMissingXPos(st, ed, c);
            if(missing != -1)
            {
                cout << missing << " " << missing + c << "\n";
                break;
            }

            c = x[i] + dist + y[i];
            missing = findMissingXNeg(st, ed, c);
            if(missing != -1)
            {
                cout << missing << " " << -missing + c << "\n";
                break;
            }
        }
    }
}
