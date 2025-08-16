#include<bits/stdc++.h>
using namespace std;
#define hlw ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
long long A[200005],B[200005];
long long lazy[200005];
long long type[200005];
long long start[200005];
long long n,q,t,sz;

//Nafis

#define ff first
#define ss second
typedef long long LL;
typedef pair<LL, LL> pLL;
#define MAXN 1000006

LL leastFactor[MAXN];
vector<LL> primes;

void linSieve()
{
    LL i, j;
    for (i = 2; i < MAXN; ++i)
    {
        if (leastFactor[i] == 0)
        {
            leastFactor[i] = i;
            primes.push_back(i);
        }
        for (j = 0; j < (LL)primes.size() && primes[j] <= leastFactor[i] && i*primes[j] < MAXN; ++j)
        {
            leastFactor[i * primes[j]] = primes[j];
        }
    }
}

LL bigmod(LL a, LL p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return a;

    LL res = bigmod(a, p/2);
    res = (res*res);
    if(p&1)
        return (a*res);
    return res;
}

LL getTotient(LL bU, LL bV)
{
    unordered_map<LL, LL> mp;

    while(bU > 1)
    {
        mp[leastFactor[bU]]++;
        bU /= leastFactor[bU];
    }

    while(bV > 1)
    {
        mp[leastFactor[bV]]++;
        bV /= leastFactor[bV];
    }

    LL ret = 1;

    for(auto u : mp)
        ret = ret*(bigmod(u.ff, u.ss) - bigmod(u.ff, u.ss-1));

    return ret;
}

//Nafis end


void push(LL i)
{
    if(i < 0 || lazy[i]==0)
        return;
    lazy[i]=0;
    LL k=start[i];
    for(LL j=i*sz; j<(i+1)*sz; j++)
    {
        B[j]=A[k++];
    }
    if(type[i]==2)
    {
        LL a=i*sz;
        LL b=a+sz-1;
        while(a<b)
        {
            swap(B[a],B[b]);
            a++;
            b--;
        }
    }
}
int main()
{
    hlw;

    linSieve();

    cin>>n;
    sz=sqrt(1.0*n);
    for(LL i=0; i<n; i++)
    {
        cin>>A[i];
    }
    cin>>q;
    while(q--)
    {
        LL l,r,s;
        cin>>t;
        if(t==1)
        {
            cin>>l>>r>>s;
            l--;
            r--;
            s--;
            LL ll=(l + sz - 1)/sz;
            LL rr=(r+1)/sz-1;
            for(LL i=ll; i<=rr; i++)
            {
                lazy[i]=1;
                type[i]=1;
                start[i]=(i*sz-l+s);
            }
            push(ll-1);
            push(rr+1);
            LL j=s;
            for(LL i=l; i<ll*sz&&i<=r; i++)
            {
                B[i]=A[j++];
            }
            j=s+r-l;
            for(LL i=r; i>=(rr+1)*sz&&i>=l; i--)
            {
                B[i]=A[j--];
            }

        }
        else if(t==2)
        {
            cin>>l>>r>>s;
            l--;
            r--;
            s--;
            s-=(r-l);
            LL ll=(l+sz-1)/sz;
            LL rr=(r+1)/sz-1;
            for(LL i=ll; i<=rr; i++)
            {
                lazy[i]=1;
                type[i]=2;
                start[i]=((s+r-l)-(i*sz-l)-sz+1);
            }
            push(ll-1);
            push(rr+1);
            LL j=s+r-l;
            for(LL i=l; i<ll*sz&&i<=r; i++)
            {
                B[i]=A[j--];
            }
            j=s;
            for(LL i=r; i>=(rr+1)*sz&&i>=l; i--)
            {
                B[i]=A[j++];
            }
        }
        else
        {
            long long u,v;
            cin>>u>>v;
            u--;
            v--;
            LL ll=u/sz;
            push(ll);
            ll=v/sz;
            push(ll);
            long long Bu=B[u],Bv=B[v];

//            cout << Bu << " " << Bv << "\n";

            if(Bu != 0 && Bv != 0)
                cout << getTotient(Bu, Bv) << "\n";
            else
                cout << "0\n";
        }

    }

    return 0;
}
