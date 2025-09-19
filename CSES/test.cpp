#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    int bCount = 0, gCount = 0;
    for (auto u : s)
    {
        if (u == 'B')
            bCount++;
        if (u == 'G')
            gCount++;

        if (bCount == 3 & gCount < 1)
            return true;
    }

    return false;
}

int main()
{
    string s = "BBBGR";
    int cnt = 0, total = 0;

    do
    {
        total++;
        cout << s << " ";

        if (check(s))
        {
            cnt++;
            cout << "true\n";
        }
        else
        {

            cout << "\n";
        }

    } while (next_permutation(s.begin(), s.end()));

    cout << cnt << "/" << total << "\n";
}


/*
BBGGR true
BBGRG true
BBRGG true
BGBGR true
BGBRG true
BGGBR 
BGGRB 
BGRBG true
BGRGB 
BRBGG true
BRGBG true
BRGGB 
GBBGR true
GBBRG true
GBGBR 
GBGRB 
GBRBG true
GBRGB 
GGBBR 
GGBRB 
GGRBB 
GRBBG true
GRBGB 
GRGBB 
RBBGG true
RBGBG true
RBGGB 
RGBBG true
RGBGB 
RGGBB 
15/30
*/