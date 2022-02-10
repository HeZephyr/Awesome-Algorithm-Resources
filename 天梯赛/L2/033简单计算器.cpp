/**
  *@filename:033简单计算器
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-22 19:15
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

stack<int> num;
stack<char> op;
int n,u,v,temp;
char c;
void solve(){
    //开始模拟即可。
    bool flag=false;
    while(!op.empty()){
        c=op.top(),op.pop();
        u=num.top(),num.pop();
        v=num.top(),num.pop();
        //处理非0的情况。
        if(u==0&&c=='/'){
            temp=v;
            flag=true;
            break;
        }
        if(c=='+')
            //printf("%d%c%d=%d\n",v,c,u,v+u),
            u=v+u;
        if(c=='-')
            //printf("%d%c%d=%d\n",v,c,u,v-u),
            u=v-u;
        if(c=='*')
            //printf("%d%c%d=%d\n",v,c,u,v*u),
            u=v*u;
        if(c=='/')
            //printf("%d%c%d=%d\n",v,c,u,v/u),
            u=v/u;
        num.push(u);
    }
    if(flag)cout<<"ERROR: "<<temp<<"/0"<<endl;
    else cout<<num.top()<<endl;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>u;
        num.push(u);
    }
    for(int i=0;i<n-1;i++){
        cin>>c;
        op.push(c);
    }
    solve();
    return 0;
}