#include<bits/stdc++.h>

using namespace std;

const int maxn=110;
int n;
int h[maxn],dp1[maxn],dp2[maxn];
int main(){
    while(cin>>n){
        for(int i=1;i<=n;i++)cin>>h[i];
        for(int i=1;i<=n;i++){
            dp1[i]=1;
            for(int j=1;j<i;j++){
                if(h[i]>h[j]){
                    dp1[i]=max(dp1[i],dp1[j]+1);
                }
            }
        }
        for(int i=n;i>=1;i--){
            dp2[i]=1;
            for(int j=n;j>i;j--){
                if(h[i]>h[j]){
                    dp2[i]=max(dp2[i],dp2[j]+1);
                }
            }
        }
        int maxx=0;
        for(int i=1;i<=n;i++)maxx=max(maxx,dp1[i]+dp2[i]-1);
        cout<<n-maxx<<endl;
    }
    return 0;
}