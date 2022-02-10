/**
  *@filename:C
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-25 23:48
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t;
int ans;
string a,b;
void solve(){
    //枚举a的子串。空字符串也相等。
    ans=1000000;
    int len_a=a.size(),len_b=b.size();
    for(int i=0;i<len_a;i++){
        for(int j=1;i+j<=len_a;j++){
            string temp=a.substr(i,j);
            if(b.find(temp)!=string::npos){
                ans=min(ans,len_b+len_a-2*j);
            }
        }
    }
    if(ans==1000000){
        cout<<len_a+len_b<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}
int main() {
    while(cin>>t){
        while(t--){
            cin>>a>>b;
            solve();
        }
    }
    return 0;
}