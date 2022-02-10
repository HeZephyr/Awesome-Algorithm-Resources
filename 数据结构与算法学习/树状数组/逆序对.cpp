/**
  *@filename:逆序对(树状数组+离散化)
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-27 20:21
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 500000 + 5;
const int mod = 1e9+7;

int n;//序列汇总有n个数。
//离散化。
struct node{
    int data;
    int pos;
    bool operator<(const node &A){
        return data<A.data;   
    }
};
node id[maxn];
int c[maxn],d[maxn];//c为离散化后的数组。d为树状数组。
int lowbit(int x){
    return x&(-x);
}
inline void add(int x){
    while(x<=n){
        d[x]++;//比它大的可以凑成一个逆序对。
        x+=lowbit(x);
    }
}
inline ll getSum(int x){
    ll ans=0;
    while(x){
        ans+=d[x];
        x-=lowbit(x);
    }
    return ans;
}
void solve(){
    sort(id+1,id+1+n);
    int idx=1;
    for(int i=1;i<=n;i++){
        if(i!=1){
            if(id[i].data==id[i-1].data){
                c[id[i].pos]=c[id[i-1].pos];//要考虑值重复的情况。处理逆序对。
            }
            else{
                c[id[i].pos]=idx++;
            }
        }
        else{
            c[id[i].pos]=idx++;
        }
    }
    //得到的数组c则是已经离散化数组C。
    //我们将其一个一个加入树状数组构建。
    ll cnt=0;
    for(int i=1;i<=n;i++){
        add(c[i]);
        cnt+=i-getSum(c[i]);
        //cout<<cnt<<endl;
    }
    printf("%lld\n",cnt);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&id[i].data);
        id[i].pos=i;//确定好各自位置之后。记录下标。
    }
    solve();
    return 0;
}