/**
  *@filename:windy数
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-12 15:43
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int l,r;
int f[11][10];//f数组。其中f[i][j]表示i位，其中最高位为j的方案数。
void init(){
    for(int i=0;i<10;i++)f[1][i]=1;
    for(int i=2;i<11;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                if(abs(k-j)>=2){
                    f[i][j]+=f[i-1][k];
                }
            }
        }
    }
}
int dp(int n){
    if(!n){
        //特判n为0的情况，避免对之后操作造成影响。
        return 0;
    }
    vector<int> nums;//存储分割位数。
    int last=-2;//存储上一位的值。这里初值为-2,是因为我们需要确定1可以。
    int ans=0;//答案。
    while(n)nums.push_back(n%10),n/=10;
    for(int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        //左分支。
        for(int j=(i==nums.size()-1);j<x;j++){
            if(abs(j-last)>=2){
                //说明符合要求。
                ans+=f[i+1][j];
            }
        }
        if(abs(x-last)<2)break;//不满足要去。
        last=x;
        if(!i)ans++;//枚举到最后一位，自身也形成了一种方案。
    }
    //特殊枚举有前导0的数。
    for(int i=1;i<nums.size();i++){
        for(int j=1;j<=9;j++){
            ans+=f[i][j];
        }
    }
    return ans;
}
void solve(){
}
int main(){
    init();
    cin>>l>>r;
    cout<<dp(r)-dp(l-1)<<endl;
    solve();
    return 0;
}