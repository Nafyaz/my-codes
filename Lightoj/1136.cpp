#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("Fout.txt", "w", stdout);
    int T, i, j, a, b, c;
    scanf("%d", &T);
    for(i = 1; i <= T; i++)
    {
        scanf("%d %d", &a, &b);
        c = 0;
        for(j = a; j <= b; j++)
        {
            if((j%3 == 0 || j%3 == 2))
                c++;
            if(j >= 5 && (b-j)%3 == 0)
            {
                c += 2*(b-j)/3;
                break;
            }
        }
        printf("Case %d: %d\n", i, c);
    }
}
