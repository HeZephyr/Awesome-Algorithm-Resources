/**
  *@filename:贪吃蛇长度
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-31 21:52
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//读入数据即可，利用getline函数。
string temp;
int cnt;
void solve(){
    for(int i=0;i<temp.size();i++){
        if(temp[i]=='#'){
            cnt++;
        }
        else if(temp[i]=='@'){
            cnt+=2;//重合部分有2个。
        }
    }
}
int main() {
    cnt=2;//蛇头蛇尾。
    while(getline(cin,temp)){
        if(temp=="exit"){
            break;
        }
        solve();
    }
    cout<<cnt<<endl;//190
    return 0;
}