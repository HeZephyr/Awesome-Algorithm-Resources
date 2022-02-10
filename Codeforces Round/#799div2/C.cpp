/**
  *@filename:C
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-26 17:52
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 1e9+7;

int n;
string name[maxn];
int score[maxn];
map<string,int> p1;//用于存储它们最后的总分。有助于我们找到最大点数。
map<string,int> p2;//供之后模拟判断谁最先赢得最高分。
void solve(){
    int maxx=0;
    for(auto &x:p1){
        maxx=max(maxx,x.second);
    }
    for(int i=0;i<n;i++){
        //模拟判断。
        p2[name[i]]+=score[i];
        if(p2[name[i]]>=maxx&&p1[name[i]]==maxx){
            cout<<name[i]<<endl;
            return;
        }
    }
}
int main() {
    while(cin>>n){
        p1.clear(),p2.clear();
        for(int i=0;i<n;i++){
            cin>>name[i]>>score[i];
            p1[name[i]]+=score[i];
        }
        solve();
    }
    return 0;
}