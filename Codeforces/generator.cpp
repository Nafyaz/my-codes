#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define mod 1000000007

void solve(ll caseno)
{
	ll n = rand()%10+1, m = rand()%10+1;

	cout << n << " " << m << "\n";

	for(ll i = 0; i < n; i++)
	{
		for(ll j = 0; j < m; j++)		
			cout << (rand()%7 == 0? "B" : "W");
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	srand(time(0));

	ll T = 1000, caseno = 0;

	cout << T << "\n";

	while(T--)
	{
		solve(++caseno);
	}
}