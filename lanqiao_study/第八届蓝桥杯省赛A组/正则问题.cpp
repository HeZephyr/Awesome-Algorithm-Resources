/**
  *@filename:正则问题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-27 10:17
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int len;
int cur;
string s;
//我们知道对于(是具有优先计算的，而dfs其实就可以看成是一次计算，那么遇到(
//即是优先计算，我们进去dfs搜索即可。
int dfs(){
    int ans=0;
    //在while循环下执行当前计算。
    while(cur<len){
        if(s[cur]=='('){
            //优先计算。
            cur++;
            ans+=dfs();//结束完这次计算后我们继续往后遍历。
            cur++;
        }
        else if(s[cur]==')'){
            //说明优先计算结束，我们直接break即可。
            break;
        }
        else if(s[cur]=='|'){
            //说明遇到分支，我们继续往下。
            cur++;
            ans=max(ans,dfs());
        }
        else{
            cur++;
            ans++;
        }
    }
    return ans;
}
int main() {
    while(cin>>s){
        len=s.size();
        cur=0;
        cout<<dfs()<<endl;
    }
    return 0;
}