/**
  *@filename:C_Yet_Another_Card_Deck
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-07 17:09
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,q,idx[55],t;
void solve(){
    for(int i=1;i<=q;i++){
        cin>>t;
        cout<<idx[t];
        i==q?cout<<endl:cout<<" ";
        for(int j=1;j<=50;j++){
            if(idx[j]<idx[t]){
                idx[j]++;
            }
        }
        idx[t]=1;//放在顶上了。
    }
}
int main(){
    cin>>n>>q;
    int temp;
    for(int i=1;i<=n;i++){
        cin>>temp;
        if(!idx[temp]){
            idx[temp]=i;//只需要记录第一个的序号即可，因为最后每次放在队头，最前面的没有变。
        }
    }
    solve();
    return 0;
}