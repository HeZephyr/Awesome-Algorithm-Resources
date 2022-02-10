/**
  *@filename:明码
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-08 18:29
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int a[34];
int bin[8];
void change(int value){
    //转二进制。
    int temp=abs(value);
    for(int i=0;i<8;i++){
        bin[i]=temp%2;
        temp/=2;
    }
    if(value<0){
        //若是负数，则需出符号位外全部取反再加1.
        bin[7]=1;
        for(int i=0;i<7;i++){
            bin[i]=!bin[i];
        }
        bin[0]+=1;
        for(int i=1;i<7;i++){
            bin[i]+=bin[i-1]/2;
            bin[i-1]%=2;
        }
    }
}
void solve(){
    for(int i=0;i<32;i++){
        change(a[i]);
        for(int j=7;j>=0;j--){
            bin[j]?cout<<"1":cout<<" ";
        }
        if(i%2)cout<<endl;
    }
}
int main(){
    /* while(true){
        for(int i=0;i<32;i++){
            cin>>a[i];
        }
        solve();
    } */
    cout<<ll(pow(9,9))<<endl;//387420489
    return 0;
}