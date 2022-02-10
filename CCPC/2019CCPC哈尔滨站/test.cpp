#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7,N=1e6+77,inv3=333333336;
ll p[N],num,sp1[N],sp2[N],n,Sqr,tot,g1[N],g2[N],w[N],yjy1[N],yjy2[N];
bool bz[N];
void pre(int n)
{
    bz[1]=1;
    for(int i=1; i<=n; i++)
    {
        if(!bz[i])
        {
            p[++num]=i;
            sp1[num]=(sp1[num-1]+i)%mod;
            sp2[num]=(sp2[num-1]+1ll*i*i)%mod;
        }
        for(int j=1; j<=num&&p[j]*i<=n; j++)
        {
            bz[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
ll S(ll x,int y)
{
    if(p[y]>=x)return 0;
    ll k=x<=Sqr?yjy1[x]:yjy2[n/x];
    ll ans=(g2[k]-g1[k]+mod-(sp2[y]-sp1[y])+mod)%mod;
    for(int i=y+1; i<=num&&p[i]*p[i]<=x; i++)
    {
        ll pe=p[i];
        for(int e=1;pe<=x;e++,pe=pe*p[i])
        {
            ll xx=pe%mod;
            ans=(ans+xx*(xx-1)%mod*(S(x/pe,i)+(e!=1)))%mod;
        }
    }
    return ans%mod;
}
int main()
{
    scanf("%lld",&n);
    Sqr=sqrt(n);
    pre(Sqr);
    for(ll i=1,j; i<=n; i=j+1)
    {
        j=n/(n/i);
        w[++tot]=n/i;
        g1[tot]=w[tot]%mod;
        g2[tot]=g1[tot]*(g1[tot]+1)/2%mod*(2*g1[tot]+1)%mod*inv3%mod;
        g2[tot]--;
        g1[tot]=g1[tot]*(g1[tot]+1)/2%mod-1;
        if(n/i<=Sqr)yjy1[n/i]=tot;
        else yjy2[n/(n/i)]=tot;
    }
    for(int i=1; i<=num; i++)
    {
        for(int j=1; j<=tot&&p[i]*p[i]<=w[j]; j++)
        {
            ll k=w[j]/p[i]<=Sqr?yjy1[w[j]/p[i]]:yjy2[n/(w[j]/p[i])];
            g1[j]-=p[i]*(g1[k]-sp1[i-1]+mod)%mod;
            g2[j]-=p[i]*p[i]%mod*(g2[k]-sp2[i-1]+mod)%mod;
            g1[j]%=mod,g2[j]%=mod;
            if(g1[j]<0)g1[j]+=mod;
            if(g2[j]<0)g2[j]+=mod;
        }
    }
    printf("%lld",(S(n,0)+1)%mod);
}