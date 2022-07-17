#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, id, parent, child1, child2, a[1002], b[1002];

    cin >> n;

    for(i = 1; i <= n/3*3; i++)
    {
        if(i%3)
            a[i] = i+1;
        else
            a[i] = i-2;
    }

    if(n%3 == 1)
        a[n] = n;
    else if(n%3 == 2)
    {
        a[n-1] = n;
        a[n] = n-1;
    }

    for(i = 1; i <= n; i++)
    {
        id = (i + 2)/3;

        if(id == 1)
            parent = 1;
        else
            parent = id/2;

        child1 = id*2;
        child2 = id*2 + 1;

        if(i%3 == 1)
        {
            if(3*parent - 2 <= n)
                b[i] = 3*parent - 2;
            else
                b[i] = rand()%n + 1;
        }
        else if(i%3 == 2)
        {
            if(3*child1 - 2 <= n)
                b[i] = 3*child1 - 2;
            else
                b[i] = rand()%n + 1;
        }
        else
        {
            if(3*child2 - 2 <= n)
                b[i] = 3*child2 - 2;
            else
                b[i] = rand()%n + 1;
        }
    }

    for(i = 1; i <= n; i++)
        cout << a[i] << " " << b[i] << "\n";
}

