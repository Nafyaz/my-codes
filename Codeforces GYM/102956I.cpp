#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k, i, color, ay, ar, by, br, s, score;

    cin >> n >> m >> k;

    ay = ar = 0;
    for(i = 0; i < n; i++)
    {
        cin >> color;

        if(color)
            ar++;
        else
            ay++;
    }

    by = br = 0;
    for(i = 0; i < m; i++)
    {
        cin >> color;

        if(color)
            br++;
        else
            by++;
    }

    score = ay - br;
//    for(i = 0; i < k; i++)
//    {
//        cin >> s;
//
//        if(i&1)
//            score += s;
//        else
//            score -= s;
//    }

    cout << abs(score);
}