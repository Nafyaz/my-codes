#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef pair<LL, LL> pLL;
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

#define PI acos(-1)

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
	LL i, n = 1;
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

vector<LL> bigmod(vector<LL> &v, LL k)
{
    vector<LL> ret(1);
    ret[0] = 1;

    while(k)
    {
        if(k&1)
            ret = Mul(ret, v);
        v = Mul(v, v);
        k /= 2;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL n, k, i, a;
    vector<LL> v(1003), ans;

    cin >> n >> k;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        v[a] += 1;
    }

    ans = bigmod(v, k);

    for(i = 0; i < ans.size(); i++)
    {
        if(ans[i])
            cout << i << " ";
    }
    cout << "\n";
}