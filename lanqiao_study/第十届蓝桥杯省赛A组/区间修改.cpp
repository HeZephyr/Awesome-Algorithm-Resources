/**
  *@filename:区间修改
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-12 17:32
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e6 + 5;
const int mod = 1e9+7;

int n;
int father[maxn];
int find(int x){
    int r=x;
    while(r!=father[r]){
        r=father[r];
    }
    //注意路径压缩。
    int i=x,j;
    while(father[i]!=r){
        j=father[i];
        father[i]=r;
        i=j;
    }
    return r;
}
void solve(){
}
int main(){
    while(cin>>n){
        for(int i=1;i<maxn;i++)father[i]=i;
        int temp;
        for(int i=0;i<n;i++){
            scanf("%d",&temp);
            temp=find(temp);
            printf("%d ",temp);
            father[temp]=temp+1;
        }
        printf("\n");
    }
    solve();
    return 0;
}