/**
  *@filename:激光样式二进制暴力枚举
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-09 13:50
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;  

//求x在二进制下表示的第k位是0还是1.
inline int get(int x,int k){
    return x>>k&1;
}
void solve(){
    int cnt=0;
    for(int i=0;i<1<<30;i++){
        bool flag=true;
        for(int j=1;j<30;j++){
            if(get(i,j)&&get(i,j-1)){
                flag=false;
                break;
            }
        }
        cnt+=flag;
    }
    cout<<cnt<<endl;//2178309，一分钟之内能够跑完。
}
int main(){
    solve();
    return 0;
}