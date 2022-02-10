#include<bits/stdc++.h>

using namespace std;

int t,n;
void solve(){
}
int main(){
    while(cin>>t){
        for(int k=1;k<=t;k++){
            cin>>n;
            double lnc=0;//存储我们的组合数。
            double ans=0;//结果。
            double ln2=(n-1)*log(2.0);
            double val;
            for(int i=0;i<n;i++){
                cin>>val;
                if(val > 0) ans += exp(log(val) + lnc - ln2);
                else ans -= exp(log(-val) + lnc - ln2);
                lnc = lnc + log(n-i-1) - log(i+1);//这一步是组合数的递推关键。由前一个推导后一个。而不必重复计算C
            }
            printf("Case #%d: %.3lf\n",k,ans);
        }
    }
    return 0;
}