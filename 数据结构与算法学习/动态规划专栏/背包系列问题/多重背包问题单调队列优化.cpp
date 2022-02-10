#include<bits/stdc++.h>

using namespace std;

const int maxn=2e4+10;

int dp[maxn],q[maxn];//q为单调队列，维护当前的最大值。
int pre[maxn];//pre[i]保留的是上一层的状态。
int n,m;//n表示物品种数，m表示的是背包容量。
int main(){
    scanf("%d%d",&n,&m);
    int v,w,s;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&v,&w,&s);
        //获取上一层的状态。
        memcpy(pre,dp,sizeof(dp));
        //接下来去维护单调队列选取最大值。
        for(int j=0;j<v;j++){
            //0~v-1,在这些状态上进行更新。
            int head=0,tail=-1;//单调队列的头尾指针。
            for(int k=j;k<=m;k+=v){
                //剔除过期元素。
                if(head<=tail&&k-s*v>q[head])head++;
                //维护单调队列
                while(head<=tail&&pre[q[tail]]-(q[tail]-j)/v*w<=pre[k]-(k-j)/v*w)tail--;
                if(head<=tail){
                    //更新这一层的dp值。
                    dp[k]=max(dp[k],pre[q[head]]+(k-q[head])/v*w);
                }
                q[++tail]=k;
            }
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}