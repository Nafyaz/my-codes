#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll T, caseno = 0, n, m, x;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n >> m;

        deque<ll> dq;

        cout << "Case " << ++caseno << ":\n";

        while(m--)
        {
            cin >> s;

            if(s == "pushLeft")
            {
                cin >> x;

                if(dq.size() == n)
                {
                    cout << "The queue is full\n";
                }
                else
                {
                    dq.push_front(x);
                    cout << "Pushed in left: " << x << "\n";
                }
            }
            else if(s == "pushRight")
            {
                cin >> x;

                if(dq.size() == n)
                {
                    cout << "The queue is full\n";
                }
                else
                {
                    dq.push_back(x);
                    cout << "Pushed in right: " << x << "\n";
                }
            }
            else if(s == "popLeft")
            {
                if(dq.empty())
                    cout << "The queue is empty\n";
                else
                {
                    cout << "Popped from left: " << dq.front() << "\n";
                    dq.pop_front();
                }
            }
            else
            {
                if(dq.empty())
                    cout << "The queue is empty\n";
                else
                {
                    cout << "Popped from right: " << dq.back() << "\n";
                    dq.pop_back();
                }
            }
        }
    }
}
