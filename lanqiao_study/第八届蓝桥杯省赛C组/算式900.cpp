/**
  *@filename:算式900
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-01 08:55
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//直接暴力全排列输出所有解。
int a[]={0,1,2,3,4,5,6,7,8,9};
void solve(){
    do{
        if(a[0]==0||a[4]==0||a[8]==0)continue;
        if(((a[0]*1000+a[1]*100+a[2]*10+a[3])-(a[4]*1000+a[5]*100+a[6]*10+a[7]))*(a[8]*10+a[9])==900){
            cout<<"("<<a[0]*1000+a[1]*100+a[2]*10+a[3]<<"-"
            <<a[4]*1000+a[5]*100+a[6]*10+a[7]<<")"<<"*"<<a[8]*10+a[9]<<"="<<900<<endl;
        }
    }while(next_permutation(a,a+10));//(6048-5973)*12=900
}
int main(){
    solve();
    return 0;
}