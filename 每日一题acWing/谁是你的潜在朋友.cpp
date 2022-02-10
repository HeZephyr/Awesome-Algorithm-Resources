/**
  *@filename:谁是你的潜在朋友
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-18 19:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200 + 5;
const int P = 1e9+7;

int n,m;//读者的编号和书的编号。
vector<int> p[N];
int idx[N];//idx[i]记录i读者所喜欢的书籍编号。
void solve(){
}
int main(){
    cin>>n>>m;
    int temp;
    for(int i=1;i<=n;i++){
        cin>>temp;
        p[temp].push_back(i);//入队。
        idx[i]=temp;
    }
    //开始检索。
    for(int i=1;i<=n;i++){
        if(p[idx[i]].size()>1){
            cout<<p[idx[i]].size()-1<<endl;
        }
        else{
            cout<<"BeiJu"<<endl;
        }
    }
    solve();
    return 0;
}