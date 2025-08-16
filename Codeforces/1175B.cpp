#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
    LL lines;
    string command;
    stack <LL> s;
    LL x, m, big = (1LL << 32);

    cin >> lines;

    s.push(0);

    while(lines--)
    {
        cin >> command;
        if(command == "add")
        {
            x = s.top() + 1;
            s.pop();
            s.push(x);
            if(x >= big)
            {
                cout << "OVERFLOW!!!\n";
                return 0;
            }
        }
        else if(command == "for")
        {
            cin >> m;

            s.push(m);
            s.push(0);
        }
        else
        {
            x = s.top();
            s.pop();
            m = s.top();
            s.pop();

            x = m*x + s.top();
            s.pop();

            s.push(x);
            if(x >= big)
            {
                cout << "OVERFLOW!!!\n";
                return 0;
            }
        }
    }

    cout << s.top();
}
