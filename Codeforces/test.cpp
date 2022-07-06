#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;

    int cnt[128] = {0};
    for (auto c:s)  cnt[c]++;

    string pair, lone;
    for (int i=0; i<128; i++)
    {
        for (int j=0; j<cnt[i]/2; j++)
            pair.push_back(i);
        if (cnt[i]%2)  lone.push_back(i);
    }

    if (lone.size() == 0)
    {
        cout<<1<<endl;
        cout<<pair + string(pair.rbegin(), pair.rend());
        return 0;
    }

    for (int i=1; i<=n; i++)
    {
        if (n%i || (n/i)%2==0)    continue;
        if (lone.size() > i)      continue;

        cout<<i<<endl;

        for (int j=0; j<i; j++)
        {
            int sz=(n/i)/2;
            string s(pair.end()-sz, pair.end());
            pair.erase(pair.end()-sz, pair.end());

            char c;
            if (lone.size())    c=lone.back(), lone.pop_back();
            else                c=pair.back(), pair.pop_back(), lone.push_back(c);
            cout<<s + c + string(s.rbegin(), s.rend())<<" ";
        }
        return 0;
    }
}
