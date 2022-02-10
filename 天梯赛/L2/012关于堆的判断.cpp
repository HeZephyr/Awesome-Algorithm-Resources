/**
  *@filename:012关于堆的判断
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-20 19:19
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m,h[maxn];//结点个数，需要判断的命题数，小顶堆。
string op[5];
int a,b;
void adjust(int i){
    if(i==1)return;//如果是根结点自然返回。
    while(i!=1){
        //往上更新交换值。
        if(h[i]<h[i/2]){
            swap(h[i],h[i/2]);
            i/=2;
        }
        else{
            break;
        }
    }
}
int getIndex(int value){
    for(int i=1;i<=n;i++){
        if(h[i]==value)return i;
    }
    return -1;
}
void solve(){
    //开始对输入进行判断。根据下标来确定关系。
    while(m--){
        cin>>a>>op[0];
        if(op[0]=="and"){
            cin>>b>>op[1]>>op[2];
            if(getIndex(a)/2==getIndex(b)/2)puts("T");
            else puts("F");
            //cout<<a<<" "<<op[0]<<' '<<b<<' '<<op[1]<<' '<<op[2]<<endl;
        }
        else{
            cin>>op[1]>>op[2];
            if(op[2]=="root"){
                if(getIndex(a)==1)puts("T");
                else puts("F");
                //cout<<a<<" "<<op[0]<<' '<<op[1]<<' '<<op[2]<<endl;
            }
            else{
                cin>>op[3]>>b;
                if(op[2]=="parent"){
                    if((getIndex(b)/2==getIndex(a)))puts("T");
                    else puts("F");
                }
                else{
                    if(getIndex(a)/2==getIndex(b))puts("T");
                    else puts("F");
                }
                //cout<<a<<" "<<op[0]<<' '<<op[1]<<' '<<op[2]<<' '<<op[3]<<' '<<b<<endl;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    //建立小顶堆。
    for(int i=1;i<=n;i++){
        cin>>h[i];
        adjust(i);
    }
    solve();
    return 0;
}