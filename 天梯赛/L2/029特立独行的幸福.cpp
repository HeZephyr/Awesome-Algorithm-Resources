/**
  *@filename:029特立独行的幸福
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-22 14:11
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000 + 5;
const int mod = 1e9+7;

int l,r;
bool isprimer[maxn];
bool vis[maxn];//判断是否出现过。
void init(){
    memset(isprimer,true,sizeof(isprimer));
    isprimer[0]=isprimer[1]=false;
    for(int i=2;i*i<maxn;i++){
        if(isprimer[i]){
            for(int j=i+i;j<maxn;j+=i){
                isprimer[j]=false;
            }
        }
    }
}
int cal(int x){
    int ans=0;
    while(x){
        ans=ans+((x%10)*(x%10));
        x/=10;
    }
    return ans;
}
void solve(){
    //遍历区间统计幸福数。
    map<int,int> result;
    for(int i=l;i<=r;i++){
        int temp=i;
        vector<int> deep;//统计迭代层数。
        while(temp!=1){
            temp=cal(temp);
            if(find(deep.begin(),deep.end(),temp)!=deep.end())break;
            deep.push_back(temp);//放入其中。
            vis[temp]=true;//标记出现过的数。
        }
        if(temp==1)result[i]=deep.size();
    }
    //统计完之后就遍历result。
    if(result.empty()){
        puts("SAD");
        return;
    }
    for(auto &x:result){
        if(!vis[x.first]){
            printf("%d %d\n",x.first,x.second*(isprimer[x.first]?2:1));
        }
    }
}
int main(){
    init();
    cin>>l>>r;
    solve();
    return 0;
}