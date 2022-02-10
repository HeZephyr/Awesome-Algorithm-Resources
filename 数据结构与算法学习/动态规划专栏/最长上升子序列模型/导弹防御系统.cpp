#include<bits/stdc++.h>

using namespace std;
/*
顺序
先枚举将该数放到单调上升的序列中，还是单调下降的序列中。
1.如果将该数放到了单调上升的序列中，则将该数放到哪个单调上升的序列后面。
2.如果将该数放到了单调下降的序列中，则将该数放到哪个单调下降的序列后面。

直接处理必然难以处理，所以我们可以做优化。
up[]存储当前所有上升子序列的末尾元素，down[]存储当前所有下降子序列的末尾元素。
采用dfs枚举所有可能。
*/
const int maxn=50+10;
int n;
int h[maxn];
int up[maxn],down[maxn];
int ans;//全局最优解。
void dfs(int su,int sd,int step){
    //su为上升系统的数量，sd为下降系统的数量，step为当前正在处理的数。
    if(su+sd>=ans)return;//说明此时这个解已经没有作用，达不到我们想要的结果。
    if(step==n+1){
        //说明正在此时正在处理第n+1个数，即前n个数已经处理完毕，达到我们想要的结果。
        ans=min(ans,su+sd);//更新最优解。
        return;
    }
    //接下来开始枚举要放到哪个上升系统中去，自然是选取第一个大于的，由于数据量不大，我们无需二分。
    int i;
    for(i=1;i<=su;i++){
        //找到末尾第一个小于a[step]的，我们将其放入up中。
        if(up[i]<h[step])break;
    }
    //将其放入。
    int temp=up[i];
    up[i]=h[step];
    dfs(max(su,i),sd,step+1);//迭代更新。
    up[i]=temp;//恢复现场。
    for(i=1;i<=sd;i++){
        //找到第一个末尾大于a[step]的导弹系统。
        if(down[i]>h[step])break;
    }
    temp=down[i];
    down[i]=h[step];//将其放入。
    dfs(su,max(i,sd),step+1);
    down[i]=temp;//恢复现场。
}
int main(){
    while(cin>>n&&n){
        for(int i=1;i<=n;i++)cin>>h[i];
        ans=1000;
        dfs(0,0,1);
        cout<<ans<<endl;
    }
    return 0;
}