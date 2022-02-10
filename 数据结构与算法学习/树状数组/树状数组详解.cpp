#include<bits/stdc++.h>

using namespace std;

const int maxn=5e5+5;
int n,m;
int c[maxn];//树状数组。从c[i]=A[i-2^k+1]+..A[i]，其中k是i二进制位最低为的1.
//适用于单点修改和区间查询。
int lowbit(int x){
    //获取x的最低位的1.
    return x&(-x);//原理是因为-x的补码为按位取反再+1，由于会仅为到加1前第一个0的位置，故进行与的时候会获取最低位的1.
}
void update(int idx,int value){
    //往上更新到拥有i的点。
    for(int i=idx;i<=n;i+=lowbit(i)){
        c[i]+=value;
    }
}
int getSum(int idx){
    //求和函数，求1到idx中的所有数，所以若求解[x,y]之间的和，我们需要利用c[y]-c[x-1].
    int ans=0;
    for(int i=idx;i>=1;i-=lowbit(i)){
        ans+=c[i];
    }
    return ans;
}
int main(){
    cin>>n>>m;
    int op,x,y;
    for(int i=1;i<=n;i++){
        cin>>x;
        update(i,x);
    }
    for(int i=0;i<m;i++){
        cin>>op>>x>>y;
        if(op==1){
            update(x,y);
        }
        else{
            cout<<getSum(y)-getSum(x-1)<<endl;//注意这里一定是减1.
        }
    }
    return 0;
}