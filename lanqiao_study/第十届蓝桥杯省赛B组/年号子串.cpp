/**
  *@filename:年号子串
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-12 22:54
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//就是一道以前蓝桥杯的原题。位权值为26，每位的值也为1~26。
void solve(){
    int n=2019;
    for(int i=1;i<=26;i++){
        for(int j=1;j<=26;j++){
            for(int k=1;k<=26;k++){
                if(i*26*26+j*26+k==n){
                    cout<<char(i+'A'-1)<<" "<<char(j+'A'-1)<<" "<<char(k+'A'-1)<<endl;
                }
            }
        }
    }
    cout<<endl;
}
int main(){
    
    solve();
    return 0;
}