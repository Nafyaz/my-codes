#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007
#define maxN 200005

int carmichael[] = {561,1105,1729,2465,2821,6601,8911,10585,15841,
				29341,41041,46657,52633,62745,63973,75361,101101,
				115921,126217,162401,172081,188461,252601,278545,
				294409,314821,334153,340561,399001,410041,449065,
				488881,512461};

void solve(ll caseno)
{
	ll n;
	cin >> n;

	cout << (n^1000000) << "\n";
}

int main()
{
	ll T = 1, caseno = 0;

	cin >> T;

	while(T--)
	{
		solve(++caseno);
	}
}
