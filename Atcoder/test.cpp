#include <algorithm>
#include <cstring>
#include <cstdio>
#include <ctime>
typedef long long ll;
typedef __int128_t lll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef __uint128_t ulll;
namespace fastIO{
	class endline{}Endl;
	class fastIn{
		public:
			inline fastIn operator>>(char& x){scanf(" %c", &x);return *this;}
			inline fastIn operator>>(char* x){scanf("%s", x);return *this;}
			inline fastIn operator>>(float& x){scanf("%f", &x);return *this;}
			inline fastIn operator>>(double& x){scanf("%lf", &x);return *this;}
			inline fastIn operator>>(long double& x){scanf("%Lf", &x);return *this;}
			inline fastIn operator>>(int& x){char ch = getchar();int t = 1;x = 0;while (ch < '0' || ch > '9') t = (ch == '-' ? -1 : t), ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();x *= t;return *this;}
			inline fastIn operator>>(uint& x){char ch = getchar();x = 0;while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();return *this;}
			inline fastIn operator>>(ll& x){char ch = getchar();int t = 1;x = 0;while (ch < '0' || ch > '9') t = (ch == '-' ? -1 : t), ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();x *= t;return *this;}
			inline fastIn operator>>(ull& x){char ch = getchar();x = 0;while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();return *this;}
			inline fastIn operator>>(lll& x){char ch = getchar();int t = 1;x = 0;while (ch < '0' || ch > '9') t = (ch == '-' ? -1 : t), ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();x *= t;return *this;}
			inline fastIn operator>>(ulll& x){char ch = getchar();x = 0;while (ch < '0' || ch > '9') ch = getchar();while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();return *this;}
	}fin;
	class fastOut{
		int l = 10;char buf[101];
		public:
			inline fastOut operator<<(char x){putchar(x);return *this;}
			inline fastOut operator<<(char* x){printf("%s", x);return *this;}
			inline fastOut operator<<(const char* x){printf("%s", x);return *this;}
			inline fastOut operator<<(float x){sprintf(buf, "%%.%df", l), printf(buf, x);return *this;}
			inline fastOut operator<<(double x){sprintf(buf, "%%.%dlf", l), printf(buf, x);return *this;}
			inline fastOut operator<<(long double x){sprintf(buf, "%%.%dLf", l), printf(buf, x);return *this;}
			inline fastOut operator<<(int x){if (x < 0) putchar('-'), x = -x;int tp = 0;while (x) buf[++ tp] = x % 10 + '0', x /= 10;if (!tp) buf[++ tp] = '0';while (tp) putchar(buf[tp --]);return *this;}
			inline fastOut operator<<(uint x){int tp = 0;while (x) buf[++ tp] = x % 10 + '0', x /= 10;if (!tp) buf[++ tp] = '0';while (tp) putchar(buf[tp --]);return *this;}
			inline fastOut operator<<(ll x){if (x < 0) putchar('-'), x = -x;int tp = 0;while (x) buf[++ tp] = x % 10 + '0', x /= 10;if (!tp) buf[++ tp] = '0';while (tp) putchar(buf[tp --]);return *this;}
			inline fastOut operator<<(ull x){int tp = 0;while (x) buf[++ tp] = x % 10 + '0', x /= 10;if (!tp) buf[++ tp] = '0';while (tp) putchar(buf[tp --]);return *this;}
			inline fastOut operator<<(lll x){if (x < 0) putchar('-'), x = -x;int tp = 0;while (x) buf[++ tp] = x % 10 + '0', x /= 10;if (!tp) buf[++ tp] = '0';while (tp) putchar(buf[tp --]);return *this;}
			inline fastOut operator<<(ulll x){int tp = 0;while (x) buf[++ tp] = x % 10 + '0', x /= 10;if (!tp) buf[++ tp] = '0';while (tp) putchar(buf[tp --]);return *this;}
			inline fastOut operator<<(endline x){putchar('\n');return *this;}
			inline void cgelft(int x){l = x;}
	}fout;
}
struct custom_hash{
    static ull splitmix64(ull x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    uint operator()(ull x)const{
        static const ull FIXED_RANDOM = (ull)time(0) << 32 | time(0);
        return splitmix64(x + FIXED_RANDOM);
    }
};

using namespace fastIO;
using namespace std;

int n, m, x, y, r, lim, to[200001], ans[200002];
inline void add(int L, int R){ans[L] ++, ans[R + 1] --;}
int main(){
	fin >> n >> m, lim = m, r = 1;
	for (int i = 1;i <= n;i ++){
		fin >> x >> y, lim = min(lim, y);
		to[x] = max(to[x], y), r = max(r, x);
	}
	for (int l = 1;l <= lim;l ++){
		add(r - l + 1, m - l + 1);
		r = max(r, to[l]);
	}
	for (int i = 1;i <= m;i ++) ans[i] += ans[i - 1];
	for (int i = 1;i <= m;i ++) fout << ans[i] << ' ';
}