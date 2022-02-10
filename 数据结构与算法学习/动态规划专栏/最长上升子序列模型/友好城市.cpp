#include<bits/stdc++.h>

using namespace std;

const int maxn=5010;
//我们可以对这些友好城市去排序，假设以南岸作为第一衡量标准，北岸的作为第二衡量标准。
//那么排好序后如果建立航线会相交，说明北岸的存在冲突，即并不是递增的。所以我们实际上是在北岸上找一个最长上升子序列。
int n;
struct node{
    int x1,x2;
};
node citys[maxn];
int dp[maxn];
bool cmp(node a,node b){
    if(a.x1==b.x1)return a.x2<b.x2;
    return a.x1<b.x1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>citys[i].x1>>citys[i].x2;
    sort(citys+1,citys+1+n,cmp);
    int maxx=0;
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(citys[i].x2>citys[j].x2){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        maxx=max(maxx,dp[i]);
    }
    cout<<maxx<<endl;
    return 0;
}