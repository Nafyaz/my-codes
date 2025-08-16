#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, i, j;
    vector<string> trending, regular;
    string s;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> s;

        if(s[0] == '#')
            trending.push_back(s.substr(1));
        else
            regular.push_back(s);
    }

    sort(trending.begin(), trending.end());
    sort(regular.begin(), regular.end());

    while(trending.size() > regular.size())
        trending.pop_back();

    bool isPrevTrend = 0;
    ll trendCnt = 0;
    vector<string> ans;
//    cout << trending.size()

    for(i = 0, j = 0; i < trending.size() || j < regular.size();)
    {
//        cout << i << " " << j << "\n";
        if(i < trending.size() && j < regular.size())
        {
            if(trending[i] < regular[j] && !isPrevTrend || trending.size()-i > regular.size()-j && !isPrevTrend)
            {
                ans.push_back(trending[i]);
                i++;
                trendCnt++;
                isPrevTrend = 1;
            }

            else
            {
                ans.push_back(regular[j]);
                j++;
                isPrevTrend = 0;
            }
        }

        else if(i < trending.size())
        {
            if(!isPrevTrend)
            {
                ans.push_back(trending[i]);
                i++;
                trendCnt++;
                isPrevTrend = 1;
            }
            else
                break;
        }

        else if(j < regular.size())
        {
            ans.push_back(regular[j]);
            j++;
            isPrevTrend = 0;
        }
    }

    if(2*trendCnt > ans.size())
        ans.pop_back();

    for(auto u : ans)
        cout << u << " ";
}
