/**
  *@filename:机器人塔
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-25 17:12
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int m,n;//m代表A的数量，n代表B的数量。
int ans,cnt_a,cnt_b;//ans统计方案数。
int h;//表示最后一行的长度，同时也表示高度。
int dp[maxn];//行的状态。
void solve(){
    ans=0;
    h=(int)sqrt(2*(m+n));//根据等差数列得出h的高度。
    //接下来开始枚举，同h个0，枚举到h个1，实际上就是
    for(int i=0;i<=(1<<h)-1;i++){
        //i即表示最后一行。
        int temp_h=h,temp=i;//临时变量
        cnt_a=0,cnt_b=0;
        for(int j=temp_h;j>=1;j--,temp>>=1){
            //temp右移去初始化每一位。
            dp[j]=temp&1;
            if(dp[i])cnt_a++;
            else cnt_b++;
        }
        //初始化最后一行之后就可以去推导前面了，之后判断是否符合。
        while(temp_h--){
            for(int j=1;j<=temp_h;j++){
                //根据相邻是否相等来决定。
                if(dp[j]==dp[j+1]){
                    cnt_a++;
                    dp[j]=1;
                }
                else{
                    cnt_b++;
                    dp[j]=0;
                }
            }
        }
        if(cnt_a==m&&cnt_b==n){
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main() {
    while(cin>>m>>n){
        solve();
    }
    return 0;
}