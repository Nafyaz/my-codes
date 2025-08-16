#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
string s[102];
ll in[102];
ll Next[102];
bool taken[102];
vector<string> path;

bool isPossible(string s)
{
    ll i;
    map<char, ll> freq;

    for(i = 0; i < s.size(); i++)
    {
        if(i == 0)
            freq[s[i]]++;
        else if(s[i] != s[i-1])
        {
            freq[s[i]]++;

            if(freq[s[i]] > 1)
                return 0;
        }
    }

    return 1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0, i, j, flag, total;
    string S;

    cin >> T;

    while (T--)
    {
        cin >> n;

        cout << "Case #" << ++caseno << ": ";

        flag = 1;
        for(i = 0; i < n; i++)
        {
            cin >> s[i];

            if(!isPossible(s[i]))
                flag = 0;

            Next[i] = -1;
            in[i] = 0;
            taken[i] = 0;
        }

        if(!flag)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        map<char, ll> sameCnt;
        for(i = 0; i < n; i++)
        {
            if(s[i][0] == s[i].back())
            {
                sameCnt[s[i].back()] += s[i].size();
                taken[i] = 1;
            }
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i != j && !taken[i] && !taken[j] && s[i].back() == s[j][0])
                {
                    Next[i] = j;
                    in[j]++;
                }
            }
        }

        // for(i = 0; i < n; i++)
        // {
        //     // cout << i << ": ";
        //     // for(auto u : adj[i])
        //     //     cout << u << " ";
        //     // cout << "\n";
        //     cout << i << ": " << in[i] << "\n";
        // }

        queue<ll> q;
        for(i = 0; i < n; i++)
        {
            if(!taken[i] && !in[i])
                q.push(i);
        }

        path.clear();

        while(!q.empty())
        {
            i = q.front();
            q.pop();

            if(!taken[i])
            {
                j = i;
                while(1)
                {
                    path.push_back(s[j]);
                    taken[j] = 1;

                    if(Next[j] != -1 && !taken[Next[j]])
                        j = Next[j];
                    else
                        break;                    
                }
            }
        }

        for(i = 0; i < n; i++)
        {
            if(!taken[i])
            {
                j = i;
                while(1)
                {
                    path.push_back(s[j]);
                    taken[j] = 1;

                    if(Next[j] != -1 && !taken[Next[j]])
                        j = Next[j];
                    else
                        break;                    
                }
            }
        }

        // for(auto u : path)
        //     cout << u << "\n";

        S = "";
        for(i = 0; i < path.size(); i++)
        {
            if(sameCnt.find(path[i][0]) != sameCnt.end())
            {
                S = S + string(sameCnt[path[i][0]], path[i][0]);
                sameCnt[path[i][0]] = 0;
            }
            S = S + path[i];
            if(sameCnt.find(path[i].back()) != sameCnt.end())
            {
                S = S + string(sameCnt[path[i].back()], path[i].back());
                sameCnt[path[i].back()] = 0;
            }
        }

        for(auto u : sameCnt)
            S += string(u.second, u.first);


        if(isPossible(S))
            cout << S << "\n";
        else
            cout << "IMPOSSIBLE\n";
    }
}