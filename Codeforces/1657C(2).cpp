#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, n, i, j, op;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n >> s;

        op = 0;
        for(i = 0; i+1 < n;)
        {
            if(s[i] == '(' || s[i] == ')' && s[i+1] == ')')
            {
                i += 2;
                op ++;
            }
            else
            {
                j = i+1;
                while(j < n && s[j] == '(')
                    j++;
                if(j < n)
                {
                    i = j+1;
                    op++;
                }
                else
                    break;
            }
        }

        cout << op << " " << n - i << "\n";
    }
}
