/**
  *@filename:兴趣小组
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-31 21:58
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

set<int> a,b,c;//存放数据。
void solve(){
    int cnt=0;
    for(auto &x:a){
        if(x!=0&&b.find(x)!=b.end()&&c.find(x)==c.end()){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
int main() {
    int temp; 
    while(cin>>temp&&temp!=0){
        a.insert(temp);
    } 
    while(cin>>temp&&temp!=0){
        b.insert(temp);
    }
    while(cin>>temp&&temp!=0){
        c.insert(temp);
    }
    solve();//20
    return 0;
}