/**
  *@filename:CF44C-Holidays
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-26 17:17
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m;
int c[maxn];//树状数组。
//我们每个人都负责管辖了一片区间。所以我们最后实际上是要判断每一天有没有被重复浇水或者不浇水。
//这里我们可以用差分数组来实现。
int lowbit(int x){
    return x&(-x);
}
void add(int pos,int x){
    while(pos<=n){
        c[pos]+=x;
        pos+=lowbit(pos);
    }
}
void update(int l,int r){
    add(l,1),add(r+1,-1);
}
int get(int pos){
    int ans=0;
    while(pos>0){
        ans+=c[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
void solve(){
}
int main(){
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        update(a,b);
    }
    //遍历每一个天，判断是否符合条件。
    bool flag=false;
    int pos;
    for(int i=1;i<=n;i++){
        if(get(i)!=1){
            flag=true;
            pos=i;
            break;
        }
    }
    if(flag){
        cout<<pos<<" "<<get(pos)<<endl;
    }
    else{
        cout<<"OK"<<endl;
    }
    solve();
    return 0;
}