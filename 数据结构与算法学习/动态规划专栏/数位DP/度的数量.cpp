/**
  *@filename:度的数量
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-12 11:23
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int l,r,k,b;
int f[35][35];
//首先我们先预处理f数组。其中f[i][j]表示剩下还有i个没填，需要填写j个1的方案数。
void init(){
    for(int i=0;i<35;i++){
        for(int j=0;j<=i;j++){
            if(!j)f[i][j]=1;
            else{
                f[i][j]=f[i-1][j]+f[i-1][j-1];
            }
        }
    }
}
int dp(int n){
    //求解f(n)。我们需要避免n为0的情况，这里需要特判。
    if(!n)return 0;
    vector<int> nums;//将n分割，存储位数。
    while(n){
        nums.push_back(n%b);
        n/=b;
    }
    int ans=0;//答案。
    int last=0;//前面的信息，这里代表的是前面分支选取了多少个1.
    for(int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        if(x){
            //说明x>0，我们可以选择左边分支填0.
            ans+=f[i][k-last];
            if(x>1){
                //当x>1我们才可以枚举左边分支填1.
                if(k-last-1>=0){
                    //如果还可以填1的话。
                    ans+=f[i][k-last-1];
                }
                break;//因为右边分支只能为0或1，所以不符合条件。break。
            }
            else{
                //当x=1就可以进入右边的分支继续讨论。
                last++;
                if(last>k)break;
            }
        }
        //考虑到最后一位，如果符合条件那么末位填0也算一种方案。
        if(!i&&last==k)ans++;
    }
    return ans;
}
void solve(){
}
int main(){
    cin>>l>>r>>k>>b;
    init();
    cout<<dp(r)-dp(l-1)<<endl;
    solve();
    return 0;
}