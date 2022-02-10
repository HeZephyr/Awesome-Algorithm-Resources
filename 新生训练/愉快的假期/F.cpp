#include<bits/stdc++.h>

using namespace std;

const int maxn=5e4+5;
int t,n;
//就是杨辉三角，我们可以直接模拟求最后一层。
double nums[maxn];
void solve(){
    while(n>1){
        for(int i=0;i<n-1;i++){
            nums[i]=(nums[i+1]+nums[i])/2.0;
        }
        n--;
    }
}
int main(){
    while(cin>>t){
        for(int i=1;i<=t;i++){
            cin>>n;
            for(int j=0;j<n;j++)cin>>nums[j];
            solve();
            printf("Case #%d: %.3lf\n",i,nums[0]);
        }
    }
    return 0;
}