#include<bits/stdc++.h>

using namespace std;

const int maxn=1010;

//该题目意思即是可以先上山再下山，但一定要编号大于即可。
//其实编号是否大于我们并不在意，因为我们选取的总是有序的，所以就是寻找一个驼峰序列。
//所以我们开两个dp数组，一个为dp_up,一个为dp_down,dp_up[i]表示的是以第i个景点最为结束的严格单调上升子序列。
//down_up[i]表示的是以第i经典作为结束的先单调递增再单调递减序列。
//那么我们对于dp_up已经了如指掌了，可dp_down就是要利用dp_up来更新的，即dp_down[i]=max(dp_down[i],max(dp_up[j]+1,dp_down[j]+1));
int n,h[maxn],dp_up[maxn],dp_down[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    int maxx=0;
    for(int i=1;i<=n;i++){
        dp_up[i]=1,dp_down[i]=1;
        for(int j=1;j<i;j++){
            if(h[i]>h[j]){
                dp_up[i]=max(dp_up[i],dp_up[j]+1);
            }
            else if(h[i]<h[j]){
                dp_down[i]=max(dp_down[i],max(dp_down[j]+1,dp_up[j]+1));
            }
        }
        maxx=max(maxx,max(dp_up[i],dp_down[i]));
    }
    cout<<maxx<<endl;
    return 0;
}