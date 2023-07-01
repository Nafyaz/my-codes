#include<bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
    ll n, k, x, y, i, skill, ans;
    string temp;

    priority_queue<ll> aSkill, bSkill;

    cin >> n >> k >> x >> y;

    for(i = 0; i < n; i++)
    {
        cin >> temp >> skill;
        if(temp == "A")
            aSkill.push(skill);
        else
            bSkill.push(skill);
    }

    vector<ll> teamA, teamB;

    // 1
    while(teamA.size() < k && teamB.size() < k)
    {
        if(!aSkill.empty() && !bSkill.empty()) 
        {
            if(aSkill.top() > bSkill.top())
            {
                teamA.push_back(aSkill.top());
                aSkill.pop();
            }
            else
            {
                teamB.push_back(bSkill.top());
                bSkill.pop();
            }
        }       

        else if(!aSkill.empty())
        {
            teamA.push_back(aSkill.top());
            aSkill.pop();
        }

        else
        {
            teamB.push_back(bSkill.top());
            bSkill.pop();
        }
    }

    // 2
    while(teamA.size() < k)
    {
        if(!aSkill.empty() && !bSkill.empty()) 
        {
            if(aSkill.top() > bSkill.top() - y)
            {
                teamA.push_back(aSkill.top());
                aSkill.pop();
            }
            else
            {
                teamA.push_back(bSkill.top() - y);
                bSkill.pop();
            }
        }       

        else if(!aSkill.empty())
        {
            teamA.push_back(aSkill.top());
            aSkill.pop();
        }

        else
        {
            teamA.push_back(bSkill.top() - y);
            bSkill.pop();
        }
    }

    // 3
    while(teamB.size() < k)
    {
        if(!aSkill.empty() && !bSkill.empty()) 
        {
            if(aSkill.top() - x > bSkill.top())
            {
                teamB.push_back(aSkill.top() - x);
                aSkill.pop();
            }
            else
            {
                teamB.push_back(bSkill.top());
                bSkill.pop();
            }
        }       

        else if(!aSkill.empty())
        {
            teamB.push_back(aSkill.top() - x);
            aSkill.pop();
        }

        else
        {
            teamB.push_back(bSkill.top());
            bSkill.pop();
        }
    }

    ans = 0;
    for(i = 0; i < k; i++)
        ans += teamA[i] + teamB[i];

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;

    cin >> T;

    while(T--)
    {
        solve();
    }
}