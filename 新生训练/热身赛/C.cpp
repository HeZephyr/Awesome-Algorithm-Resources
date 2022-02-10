#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

const int maxn=1e5+5;
//我们需要求的是时间，而时间恰好是有序的，所以我们可以二分枚举时间。
int n,k;
int a[maxn];
bool check(int time){
    //判断所枚举的时间是否可行。
    int ans=0;//统计实际用时。
    for(int i=n-1;i>=0;i--){
        if(a[i]<=time){
            //如果当前最大值水分小于等于自然时间，说明剩下的都可以直接风干。
            break;
        }
        else{
           ans+=(a[i]-time+k-2)/(k-1);
           if(ans>time){
               return false;
           }
        }
    }
    return true;
}
void solve(){
    sort(a,a+n);
    if(k==1){
        //我们还不如自然风干，自然是最大的水分。
        printf("%d\n",a[n-1]);
        return;
    }
    //二分枚举所需时间。
    int l=0,r=a[n-1],mid;//最差情况就是衣服水分的最大值，因为这样自然晾干都可以满足。
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",l);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&k);
        solve();
    }
    return 0;
}