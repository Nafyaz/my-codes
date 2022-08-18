#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    while(true)
    {
    int n;
    cin >> n;
    if(n)
    {
        long long int m = 10000007;
    long long int fact = 1;
        for(int i= n; i >= 1; i--)
        {
            fact *= i;
        }
        vector <long long int> div;

        for(long long int i = 1; i <= sqrt(fact); i++)
        {
            if(fact%i == 0)
            {
                div.push_back(i);
                if(i != (fact/i))
                {
                div.push_back(fact/i);
                }
            }
        }
        sort(div.begin(), div.end());

        long long int cnt = 0;
        for(long long int i = 0; i < div.size(); i++)
        {
            for(int j = 1; j <= sqrt(div[i]); j++)
            {
                if(div[i]%j == 0)
                {
                    if(j != (div[i]/j))
                    {
                    cnt += 2;
                    }
                    else
                    {
                        cnt++;
                    }
                }

            }
        }
        cout << cnt%m << endl;
    }
    else
    {
        break;
    }
    }
}
