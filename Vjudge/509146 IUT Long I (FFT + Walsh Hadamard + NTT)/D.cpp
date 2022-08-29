#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 50004
#define PI acos(-1)

bool flag[MAXN];
vector<LL> composites;

typedef complex<long double> base;

void fft(vector<base> & a, bool invert) 
{
	LL i, j, bit, n, len;
    long double ang;
    n = (LL)a.size();

	for (i = 1, j = 0; i < n; i++) 
    {
		bit = n >> 1;
		for (; j >= bit; bit >>= 1)
            j -= bit;
		j += bit;
		if (i < j)
            swap(a[i], a[j]);
	}

	for (len = 2; len <= n; len <<= 1) 
    {
		ang = 2 * PI / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (i = 0; i < n; i += len) 
        {
			base w(1);
			for (j = 0; j < len / 2; j++) 
            {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}

	if (invert)
    {
        for (i = 0; i < n; i++)
            a[i] /= n;
    }
}

vector<LL> Mul(vector<LL>& a, vector<LL>& b)
{
	vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int i, n = 1;
	while (n < max(a.size(), b.size()))
        n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);

	fft(fa, false), fft(fb, false);
	for (i = 0; i < n; i++)
            fa[i] *= fb[i];
	fft(fa, true);

	vector<LL> res;
	res.resize(n);
	for (i = 0; i < n; i++)
        res[i] = round(fa[i].real());
	return res;
}

void sieve()
{
    LL i, j;

    flag[2] = 1;
    for(i = 3; i < MAXN; i += 2)
        flag[i] = 1;

    for(i = 3; i * i < MAXN; i+=2)
    {
        if(flag[i])
        {
            for(j = i*i; j < MAXN; j += 2*i)
                flag[j] = 0;
        }
    }

    for(i = 2; i < MAXN; i++)
    {
        if(!flag[i])
            composites.push_back(i);
    }
}

vector<LL> getAll(LL b)
{
    LL i, j;
    vector<LL> ret;

    for(i = 0, j = 0; i <= b; i++)
    {
        if(j < composites.size() && i == composites[j])
        {
            ret.push_back(1);
            j++;
        }
        else
            ret.push_back(0);
    }

    return ret;
}

void solve(LL a, LL b, LL c)
{
    LL i;
    vector<LL> S, H, C, D, ans;
    string lost;

    S = H = C = D = getAll(b);

    while(c--)
    {
        cin >> lost;
        if(lost.back() == 'S')
            S[stoi(lost.substr(0, lost.size()-1))] = 0;
        else if(lost.back() == 'H')
            H[stoi(lost.substr(0, lost.size()-1))] = 0;
        else if(lost.back() == 'C')
            C[stoi(lost.substr(0, lost.size()-1))] = 0;
        else if(lost.back() == 'D')
            D[stoi(lost.substr(0, lost.size()-1))] = 0;
    }

    // cout << "S: ";
    // for(auto u : S)
    //     cout << u << " ";
    // cout << "\n";
    // cout << "H: ";
    // for(auto u : H)
    //     cout << u << " ";
    // cout << "\n";
    // cout << "C: ";
    // for(auto u : C)
    //     cout << u << " ";
    // cout << "\n";
    // cout << "D: ";
    // for(auto u : D)
    //     cout << u << " ";
    // cout << "\n";

    ans = Mul(S, H);
    ans = Mul(ans, C);
    ans = Mul(ans, D);

    for(i = a; i <= b; i++)
        cout << ans[i] << "\n";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int a, b, c;

    while(1)
    {
        cin >> a >> b >> c;

        if(!a && !b && !c)
            break;

        solve(a, b, c);
    }
}