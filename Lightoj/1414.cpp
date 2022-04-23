#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0;
    string monthName[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    ll daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    string stMonth, edMonth;
    ll stDay, edDay, ststYear, edYear;
    char temp;

    ll ans;

    cin >> T;

    while(T--)
    {
        cin >> stMonth >> stDay >> temp >> stYear;
        cin >> edMonth >> edDay >> temp >> edYear;

        ans = 0;

        for(i = 0; i < 2; i++)
        {
            if(monthName[i] == stMonth)

        }
    }
}
