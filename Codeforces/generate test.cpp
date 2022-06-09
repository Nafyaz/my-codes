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
	ll n = 100000, q = 1;
	cout << n << " " << q << "\n";

	for(ll i = 0; i < n; i++)	
		cout << rand()%2;
	
	cout << "\n1 " << n << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	srand(time(0));

	ll T = 1, caseno = 0;

	// cout << T << "\n";

	while(T--)
	{
		solve(++caseno);
	}
}