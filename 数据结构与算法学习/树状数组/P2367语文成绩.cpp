/**
  *@filename:P2367语文成绩
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-26 17:28
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn =5e6 + 5;
const int mod = 1e9+7;

int n,p;//学生数和增加分数的次数。
int c[maxn];//树状数组。
int x,y,z;
int lowbit(int x){
    return x&(-x);
}
void add(int pos,int x){
    while(pos<=n){
        c[pos]+=x;
        pos+=lowbit(pos);
    }
}
void update(int l,int r,int x){
    //cout<<l<<" "<<r<<" "<<x<<endl;
    add(l,x),add(r+1,-x);
}
long long get(int pos){
    long long ans=0;
    while(pos>0){
        ans+=c[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
//d[i]=c[i]-c[i-1];
void solve(){
    while(p--){
        scanf("%d%d%d",&x,&y,&z);
        update(x,y,z);
    }
    long long minn=5e10;
    for(int i=1;i<=n;i++){
        minn=min(minn,get(i));
    }
    printf("%d\n",minn);
}
int main(){
    scanf("%d%d",&n,&p);
    int pre=0,cur;
    for(int i=1;i<=n;i++){
        scanf("%d",&cur);
        add(i,cur-pre);//记住这里要用add加上去。
        pre=cur;
    }
    solve();
    return 0;
}