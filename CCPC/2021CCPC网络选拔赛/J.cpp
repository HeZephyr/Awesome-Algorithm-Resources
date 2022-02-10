#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200+10;
int a[maxn][maxn];
int dp_y[maxn][maxn],dp_n[maxn][maxn];//dp_y表示前j列打了i发子弹，最后一发不打第j列 (dp_n同理，但要打最后一发)
int dy[maxn][maxn],dn[maxn][maxn];//d_y表示第j列打第i发子弹，不打最后一发子弹(d_n同理，但要打最后一发) 
char c[maxn][maxn];
int main() {
    int k,n,m,t;
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d %c",&a[i][j],&c[i][j]);
        memset(dp_y,0,sizeof(dp_y));
        memset(dp_n,0,sizeof(dp_n));
        memset(dy,0,sizeof(dy));
        memset(dn,0,sizeof(dn));
        int cnt;
        for(int i=1;i<=m;i++){ 
            cnt=n;//行数 
            while(cnt>0&&c[cnt][i]=='Y'){
                dy[i][0]+=a[cnt][i];
                cnt--;
            }
            for(int j=1;j<=n&&cnt>0;j++) {
                dn[i][j]=dy[i][j-1]+a[cnt][i];
                dy[i][j]=dn[i][j];//无Y,看作相同 
                cnt--;
                while(cnt>0&&c[cnt][i]=='Y') {
                    dy[i][j]+=a[cnt][i];//有Y，可直接加入，不废子弹 
                    cnt--;
                }
            }
        }
        for(int j=1;j<=m;j++)//枚举列 
            for(int i=0;i<=k;i++)//子弹数 
                for(int x=0;x<=n;x++)//打出的子弹数 
                    if(x<=i){
                        dp_y[j][i]=max(dp_y[j][i],dp_y[j-1][i-x]+dy[j][x]);//dp_y[j][i]所包括的砖块除了在i发子弹能
                        //够直接打下的最大得分外，还有再多一发子弹就能打下的所有Y的砖块的得分。
                        if(x<i)dp_n[j][i]=max(dp_n[j][i],dp_n[j-1][i-x]+dy[j][x]);
                        //表示在j-1列中一定有一砖块是用我们手上的子弹直接打下来的，
                        //如果，该砖块是Y，我们可以打下它后，用奖励的那发子弹去打第j列靠上的Y砖块。
                        //如果，该砖块是N，我们可以先用一发子弹去打第j列所要打的Y砖块，用j列最后一个被打下的Y砖块所奖励的子弹去打那个N砖块。
                        if(x>0)dp_n[j][i]=max(dp_n[j][i],dp_y[j-1][i-x]+dn[j][x]);
                    }
        printf("%d\n",dp_n[m][k]);
    }
    return 0;
}