/**
  *@filename:三体攻击优化
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-07 17:14
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//对于暴力法，我们过不了全部样例，那么我们可以利用差分来解决这道题。这里利用三维的差分。
int a,b,c,m;
void work(int flag,int l,int r){
    for(int t=l;i<=r;i++){
        int lat=hitInfo[t][0],rat=hitInfo[t][1],lbt=hitInfo[t][2],rbt=hitInfo[t][3],
        lct=hitInfo[t][4],rct=hitInfo[t][5],ht=hitInfo[t][6]*flag;
        dif[lat][lbt][lct]+=ht,dif[lat+1][lbt][lct]-=ht,dif[lat][lbt+1][lct]-=ht;
        dif[lat][lbt][lct+1]-=ht,dif[lat+1][lbt+1][lct]+=ht,dif[lat+1][lbt][lct+1]+=ht;
        dif[lat][lbt+1][lct+1]+=ht,dif[lat+1][lbt+1][lct+1]-=ht;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                dif[lat][lbt]lct]
            }
        }
    }
}
int main(){
    while(cin>>a>>b>>c>>m){
        extern vector<vector<vector<int> > > planes(a+1,vector<vector<int> >(b+1,vector<int>(c+1)));
        extern vector<vector<vector<int> > > dif(a+1,vector<vector<int> >(b+1,vector<int>(c+1)));//三维差分数组。
        extern vector<vector<int> > hitInfo(m,vector<int>(7));
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                for(int k=1;k<=c;k++){
                    cin>>planes[i][j][k];
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<7;j++){
                cin>>hitInfo[i][j];
            }
        }
        int l=1,r=m,mid,fast;//fast做记忆用，即每次二分之后不必重新去设置上一步已经更新过的差分数组。
        while(l<m){
            mid=(l+r)>>1;
            bool flag=true;//标志，是否已经满足条件。
            memset(dif,0,sizeof(dif));
            if(fast<=mid){
                //说明要更新的比上一次大相差cnt-fast，我们只要处理fast->cnt之间的即可。
                work(-1,fast,mid);
            }
            else{
                //说明要更新的比上一次小相差cnt-fast，我们需要弥补回来。
                work(1,fast,mid);
            }
        }
    }
    return 0;
}
