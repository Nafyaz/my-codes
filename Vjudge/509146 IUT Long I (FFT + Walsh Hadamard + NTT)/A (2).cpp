#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define LL long long
#define pLL pair<LL, LL>
#define ff first
#define ss second
#define show(x) cout << #x << ": " << x << "; "
#define MOD 1000000007
#define MAXN 2000006

const double PI = acos(-1.0L);

struct CD {
    double x, y;
    CD(double x=0, double y=0) :x(x), y(y) {}
    CD operator+(const CD& o) { return {x+o.x, y+o.y};}
    CD operator-(const CD& o) { return {x-o.x, y-o.y};}
    CD operator*(const CD& o) { return {x*o.x-y*o.y, x*o.y+o.x*y};}
    void operator /= (double d) { x/=d; y/=d;}
    double real() {return x;}
    double imag() {return y;}
};

CD conj(const CD &c) {return CD(c.x, -c.y);}

namespace FFT {
    int N;
    vector<int> perm;
    vector<CD> wp[2];

    void precalculate(int n) {
        assert((n & (n-1)) == 0);
        N = n;
        perm = vector<int> (N, 0);
        for (int k=1; k<N; k<<=1) {
            for (int i=0; i<k; i++) {
                perm[i] <<= 1;
                perm[i+k] = 1 + perm[i];
            }
        }

        wp[0] = wp[1] = vector<CD>(N);
        for (int i=0; i<N; i++) {
            wp[0][i] = CD( cos(2*PI*i/N),  sin(2*PI*i/N) );
            wp[1][i] = CD( cos(2*PI*i/N), -sin(2*PI*i/N) );
        }
    }

    void fft(vector<CD> &v, bool invert = false) {
        if (v.size() != perm.size())    precalculate(v.size());

        for (int i=0; i<N; i++)
            if (i < perm[i])
                swap(v[i], v[perm[i]]);

        for (int len = 2; len <= N; len *= 2) {
            for (int i=0, d = N/len; i<N; i+=len) {
                for (int j=0, idx=0; j<len/2; j++, idx += d) {
                    CD x = v[i+j];
                    CD y = wp[invert][idx]*v[i+j+len/2];
                    v[i+j] = x+y;
                    v[i+j+len/2] = x-y;
                }
            }
        }

        if (invert) {
            for (int i=0; i<N; i++) v[i]/=N;
        }
    }

     void pairfft(vector<CD> &a, vector<CD> &b, bool invert = false) {
        int N = a.size();
        vector<CD> p(N);
        for (int i=0; i<N; i++) p[i] = a[i] + b[i] * CD(0, 1);
        fft(p, invert);
        p.push_back(p[0]);

        for (int i=0; i<N; i++) {
            if (invert) {
                a[i] = CD(p[i].real(), 0);
                b[i] = CD(p[i].imag(), 0);
            }
            else {
                a[i] = (p[i]+conj(p[N-i]))*CD(0.5, 0);
                b[i] = (p[i]-conj(p[N-i]))*CD(0, -0.5);
            }
        }
    }

    vector<LL> multiply(const vector<LL> &a, const vector<LL> &b) {
        int n = 1;
        while (n < a.size()+ b.size())  n<<=1;

        vector<CD> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        fa.resize(n); fb.resize(n);

//        fft(fa); fft(fb);
        pairfft(fa, fb);
        for (int i=0; i<n; i++) fa[i] = fa[i] * fb[i];
        fft(fa, true);

        vector<LL> ans(n);
        for (int i=0; i<n; i++)     ans[i] = round(fa[i].real());
        return ans;
    }

    const int M = 1e9+7, B = sqrt(M)+1;
    vector<LL> anyMod(const vector<LL> &a, const vector<LL> &b) {
        int n = 1;
        while (n < a.size()+ b.size())  n<<=1;
        vector<CD> al(n), ar(n), bl(n), br(n);

        for (int i=0; i<a.size(); i++)  al[i] = a[i]%M/B, ar[i] = a[i]%M%B;
        for (int i=0; i<b.size(); i++)  bl[i] = b[i]%M/B, br[i] = b[i]%M%B;

        pairfft(al, ar); pairfft(bl, br);
//        fft(al); fft(ar); fft(bl); fft(br);

        for (int i=0; i<n; i++) {
            CD ll = (al[i] * bl[i]), lr = (al[i] * br[i]);
            CD rl = (ar[i] * bl[i]), rr = (ar[i] * br[i]);
            al[i] = ll; ar[i] = lr;
            bl[i] = rl; br[i] = rr;
        }

        pairfft(al, ar, true); pairfft(bl, br, true);
//        fft(al, true); fft(ar, true); fft(bl, true); fft(br, true);

        vector<LL> ans(n);
        for (int i=0; i<n; i++) {
            LL right = round(br[i].real()), left = round(al[i].real());;
            LL mid = round(round(bl[i].real()) + round(ar[i].real()));
            ans[i] = ((left%M)*B*B + (mid%M)*B + right)%M;
        }
        return ans;
    }
}

void solve(int caseno)
{
    int i, carry, sum;
    string a, b;
    vector<LL> vA, vB, vAns;

    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(i = 0; i < a.size(); i++)    
        vA.push_back(a[i] - '0');
    for(i = 0; i < b.size(); i++)
        vB.push_back(b[i] - '0');

    vAns = FFT::multiply(vA, vB);


    carry = sum = 0;
    for(i = 0; i < vAns.size(); i++)
    {
        sum = carry + vAns[i];
        vAns[i] = sum%10;
        carry = sum/10;
    }

    while(!vAns.empty() && vAns.back() == 0)
        vAns.pop_back();

    if(vAns.empty())
    {
        cout << "0\n";
        return;
    }

    reverse(vAns.begin(), vAns.end());

    for(i = 0; i < vAns.size(); i++)
        cout << vAns[i];
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1, caseno = 0;

    cin >> T;

    while(T--)
    {
        solve(++caseno);
    }
}