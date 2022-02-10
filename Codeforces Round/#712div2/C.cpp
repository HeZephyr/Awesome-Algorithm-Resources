/**
  *@filename:C
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-06 19:23
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n;
string s;
bool check(){
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0')cnt++;
    }
    return cnt%2;
}
void solve(){
    //首先我们的得知道什么情况下有解什么情况下无解。
    //两个括号序列开头一定是"("结尾一定是")"，同时由于n是偶数，所以
    //对于01序列中导致不相同的0必须是偶数，这样才能使得括号配对成功。
    //构建序列的时候双指针扫描序列中的1，左边放左括号，右边放右括号，而剩余的0则轮流放左右括号即可。
    if(s[0]!='1'||s[n-1]!='1'||check()){
        puts("NO");
        return;
    }
    puts("YES");
    int l=0,r=n-1;
    while(l<r){
        while(l<n&&s[l]!='1')l++;
        while(r>0&&s[r]!='1')r--;
        if(l>=r)break;
        s[l]='(',s[r]=')';
    }
    //先左右括号轮流放。
    bool flag=true;
    string temp=s;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(flag){
                temp[i]='(';
                s[i]=')';
            }
            else{
                temp[i]=')';
                s[i]='(';
            }
            flag=!flag;
        }
    }
    cout<<temp<<endl<<s<<endl;
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n>>s;
            solve();
        }
    }
    return 0;
}