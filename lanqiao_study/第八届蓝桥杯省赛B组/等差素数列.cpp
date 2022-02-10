/**
  *@filename:等差素数�?
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-31 13:52
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000000 + 5;
const int mod = 1e9+7;

//枚举公差即可。当然我们也需要建一个素数表
bool isprimer[maxn];
int primer[maxn];
int len;
void init(){
    memset(isprimer,true,sizeof(isprimer));
    int temp=sqrt(maxn);
    for(int i=2;i<=temp;i++){
        if(isprimer[i]){
            primer[len++]=i;
            for(int j=i*i;j<=maxn;j+=i){
                isprimer[j]=false;
            }
        }
    }
}
bool check(int index,int d){
    int temp=primer[index]+9*d;//确定尾数
    if(temp>=maxn)return false;
    for(int i=primer[index];i<=temp;i+=d){
        if(!isprimer[i]){
            return false;
        }
    }
    return true;
}
void solve(){
    bool flag=false;
    for(int d=1;d<=400;d++){
        //枚举首项?
        for(int index=0;index<len-10;index++){
            if(check(index,d)){
                cout<<"首项为："<<primer[index]<<"公差为："<<d<<endl;//199 210.
                flag=true;
                break;
            }
        }
        if(flag)break;
    }
}
int main() {
    len=0;
    init();
    solve();
    return 0;
}