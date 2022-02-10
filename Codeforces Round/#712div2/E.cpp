/**
  *@filename:E
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-07 12:26
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;//城市数量。
struct node{
    int a,c;
}citys[maxn];
bool cmp(node &a,node &b){
    return a.a<b.a; 
}
void solve(){
}
int main(){
    while(cin>>n){
        ll ans=0;
        for(int i=0;i<n;i++){
            cin>>citys[i].a>>citys[i].c;
            ans+=citys[i].c;//加上必要花费。
        }
        sort(citys,citys+n,cmp);//排序。
        int maxx=citys[0].a+citys[0].c;//维护一个最远距离。相当于内部是一个集合。
        for(int i=1;i<n;i++){
            ans+=max(0,citys[i].a-maxx);
            maxx=max(maxx,citys[i].a+citys[i].c);
        }
        cout<<ans<<endl;
    }
    solve();
    return 0;
}