/**
  *@filename:024部落
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-21 19:42
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,k,father[maxn];
int cnt1,cnt2;//统计总人数和不相交的部落数。
int find(int x){
    int r=x;
    while(r!=father[r])r=father[r];
    int i=x,j;
    while(father[i]!=r){
        j=father[i];
        father[i]=r;
        i=j;
    }
    return r;
}
int main(){
    cin>>n;
    int x,y,fx,fy;
    int maxx=0;//记录最大编号。
    set<int> v1,v2;
    for(int i=1;i<=10000;i++)father[i]=i;
    for(int i=1;i<=n;i++){
        cin>>k;
        cin>>x;
        maxx=max(x,maxx);
        v1.insert(x);
        for(int j=1;j<k;j++){
            cin>>y;
            maxx=max(maxx,x);
            v1.insert(y);
            fx=find(x);
            fy=find(y);
            if(fx!=fy)father[fx]=fy;
        }
    }
    for(int i=1;i<=maxx;i++){
        v2.insert(find(i));
    }
    printf("%d %d\n",v1.size(),v2.size());
    int q;
    cin>>q;
    while(q--){
        cin>>x>>y;
        if(find(x)==find(y))puts("Y");
        else puts("N");
    }
    return 0;
}