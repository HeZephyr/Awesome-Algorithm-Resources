/**
  *@filename:B
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-25 22:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;


int t,n,k;
int ans;
string s;
void solve(){
    int left=0,right=n-1;
    while(s[left]!='*')left++;
    while(s[right]!='*')right--;
    if(left==right){
        cout<<1<<endl;
        return;
    }
    ans=2;
    while(right-left>k){
        //开始枚举，我们选一个跨度从高到底开始。
        for(int i=left+k;i>left;i--){
            if(s[i]=='*'){
                ans++;
                left=i;
                break;
            }
        }
    }
    cout<<ans<<endl;
}
int main() {
    while(cin>>t){
        while(t--){
            cin>>n>>k;
            cin>>s;
            solve();
        }
    }
    return 0;
}