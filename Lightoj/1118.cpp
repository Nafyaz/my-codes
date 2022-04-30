#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define PI acos(-1)

double dist(pair<double, double> p1, pair<double, double> p2)
{
    return sqrt((p1.ff-p2.ff)*(p1.ff-p2.ff) + (p1.ss-p2.ss)*(p1.ss-p2.ss));
}

double triArea(double a, double b, double c)
{
    double s = (a + b + c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, caseno = 0;
    pair<double, double> c1, c2;
    double r1, r2;
    double c1c2, AB, theta1, theta2, left, right;

    cin >> T;

    while(T--)
    {
        cin >> c1.ff >> c1.ss >> r1;
        cin >> c2.ff >> c2.ss >> r2;

        if(r2 < r1)
        {
            swap(c1, c2);
            swap(r1, r2);
        }

        c1c2 = dist(c1, c2);

        if(c1c2 == 0)
        {
            cout << "Case " << ++caseno << ": " << fixed << setprecision(6) << PI*r1*r1 << "\n";
        }

        else if(r1+r2 <= c1c2)
            cout << "Case " << ++caseno << ": " << 0 << "\n";

        else if(r2*r2 <= r1*r1 + c1c2*c1c2)
        {
            AB = 2*(triArea(r1, r2, c1c2)/(c1c2/2));

            theta1 = acos((2*r1*r1 - AB*AB) / (2*r1*r1));
            theta2 = acos((2*r2*r2 - AB*AB) / (2*r2*r2));

            right = theta1/2*r1*r1 - triArea(r1, r1, AB);
            left = theta2/2*r2*r2 - triArea(r2, r2, AB);

            cout << "Case " << ++caseno << ": " << fixed << setprecision(6) << left + right << "\n";
        }

        else if(r2 <= c1c2 + r1)
        {
            AB = 2*(triArea(r1, r2, c1c2)/(c1c2/2));

            theta1 = 2*PI - acos((2*r1*r1 - AB*AB) / (2*r1*r1));
            theta2 = acos((2*r2*r2 - AB*AB) / (2*r2*r2));

            right = theta1/2*r1*r1 + triArea(r1, r1, AB);
            left = theta2/2*r2*r2 - triArea(r2, r2, AB);

            cout << "Case " << ++caseno << ": " << fixed << setprecision(6) << left + right << "\n";
        }

        else
            cout << "Case " << ++caseno << ": " << fixed << setprecision(6) << PI*r1*r1 << "\n";
    }
}
