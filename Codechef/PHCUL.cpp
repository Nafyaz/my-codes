#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

pair<ll, ll> N[5003], M[5003], K[5003];

double M2K[5003], N2M2K[5003], S2N2M2K;
double N2K[5003], M2N2K[5003], S2M2N2K;

double dist(pair<ll, ll> p, pair<ll, ll> q)
{
    return sqrt((p.ff - q.ff)*(p.ff - q.ff) + (p.ss - q.ss)*(p.ss - q.ss));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, x, y, n, m, k, i, j;

    cin >> T;

    while(T--)
    {
        cin >> x >> y;
        cin >> n >> m >> k;

        S2M2N2K = S2N2M2K = LLONG_MAX;
        for(i = 0; i < n; i++)
        {
            cin >> N[i].ff >> N[i].ss;
            N2K[i] = N2M2K[i] = LLONG_MAX;
        }
        for(i = 0; i < m; i++)
        {
            cin >> M[i].ff >> M[i].ss;
            M2K[i] = M2N2K[i] = LLONG_MAX;
        }
        for(i = 0; i < k; i++)
            cin >> K[i].ff >> K[i].ss;

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < k; j++)
                M2K[i] = min(M2K[i], dist(M[i], K[j]));
        }
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
                N2M2K[i] = min(N2M2K[i], dist(N[i], M[j]) + M2K[j]);
        }
        for(i = 0; i < n; i++)
            S2N2M2K = min(S2N2M2K, dist({x, y}, N[i]) + N2M2K[i]);


        for(i = 0; i < n; i++)
        {
            for(j = 0; j < k; j++)
                N2K[i] = min(N2K[i], dist(N[i], K[j]));
        }
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
                M2N2K[i] = min(M2N2K[i], dist(M[i], N[j]) + N2K[j]);
        }
        for(i = 0; i < m; i++)
            S2M2N2K = min(S2M2N2K, dist({x, y}, M[i]) + M2N2K[i]);

        cout << fixed << setprecision(6) << min(S2N2M2K, S2M2N2K) << "\n";
    }
}