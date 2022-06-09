#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f(string s)
{
    ll i, ret = 0;
    for(i = 0; i+1 < s.size(); i++)    
        ret += 10*(s[i] - '0') + (s[i+1] - '0');
    
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s = "0000";
    do
    {
        cout << s << ": " << f(s) << "\n";
    }while(next_permutation(s.begin(), s.end()));
    cout << "\n";

    s = "0001";
    do
    {
        cout << s << ": " << f(s) << "\n";
    }while(next_permutation(s.begin(), s.end()));
    cout << "\n";

    s = "0011";
    do
    {
        cout << s << ": " << f(s) << "\n";
    }while(next_permutation(s.begin(), s.end()));
    cout << "\n";

    s = "0111";
    do
    {
        cout << s << ": " << f(s) << "\n";
    }while(next_permutation(s.begin(), s.end()));
    cout << "\n";

    s = "1111";
    do
    {
        cout << s << ": " << f(s) << "\n";
    }while(next_permutation(s.begin(), s.end()));
    cout << "\n";
}


1st: A, B, C
2nd: B, C, A
3rd: B, C, A
4th: B, A, C
5th: A, C, B
6th: B, A, C

1st: A
2nd: B
3rd: B
4th: A
5th: C
6th: C

for each student sorted by their ranks:
{
    for each choice sorted by his selection:
    {
        if this choice of department is not filled:
        {
            put him in this department;
            reduce remaining seats in this department by 1;
            break;
        }
    }
}