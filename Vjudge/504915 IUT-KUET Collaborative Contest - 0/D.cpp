#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, id, parent, child1, child2, child3, a[1002], b[1002];

    cin >> n;

    for(i = 1; i <= n/4*4; i++)
    {
        if(i%4)
            a[i] = i+1;
        else
            a[i] = i-3;
    }

    if(n%4 == 1)
        a[n] = n;
    else if(n%4 == 2)
    {
        a[n-1] = n;
        a[n] = n-1;
    }
    else if(n%4 == 3)
    {
        a[n-2] = n-1;
        a[n-1] = n;
        a[n] = n-2;
    }

    for(i = 1; i <= n; i++)
    {
        id = (i + 3)/4;

        if(id == 1)
            parent = 1;
        else
            parent = (id+1)/3;

        child1 = 3*id-1;
        child2 = 3*id;
        child3 = 3*id+1;

        if(i%4 == 1)
        {
            if(4*parent - 3 <= n)
                b[i] = 4*parent - 3;
            else
                b[i] = rand()%n + 1;
        }
        else if(i%4 == 2)
        {
            if(4*child1 - 3 <= n)
                b[i] = 4*child1 - 3;
            else
                b[i] = rand()%n + 1;
        }
        else if(i%4 == 3)
        {
            if(4*child2 - 3 <= n)
                b[i] = 4*child2 - 3;
            else
                b[i] = rand()%n + 1;
        }
        else
        {
            if(4*child3 - 3 <= n)
                b[i] = 4*child3 - 3;
            else
                b[i] = rand()%n + 1;
        }
    }

    for(i = 1; i <= n; i++)
        cout << a[i] << " " << b[i] << "\n";
}
