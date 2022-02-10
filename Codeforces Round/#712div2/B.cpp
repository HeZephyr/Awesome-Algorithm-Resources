/**
  *@filename:B
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-06 18:58
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n;
string a,b;
void solve(){
    //思维题，我们更改前缀的条件就是0和1的数量要相等。那么如果位于需要更改的地方确不能更改，那就无解了。
    int cnt=0;
    a+="0",b+="0";//这么做的目的是为了判断更好的前缀。
    for(int i=0;i<n;i++){
        cnt+=((a[i]=='1')-(a[i]=='0'));//统计0和1的数量是否相等。
        //判断该位置是否可以交换。
        if((a[i]==b[i])!=(a[i+1]==b[i+1])&&cnt!=0){
            //如果出现不相等，且目前不可翻转。
            puts("NO");
            return;
        }
    }
    puts("YES");
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n;
            cin>>a>>b;
            solve();
        }
    }
    return 0;
}