/**
  *@filename:数字游戏
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-12 14:57
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int l,r;
int f[11][11];//预处理f数组。其中f[i][j]表示i位数，且最高位为j的不降数方案数。
void init(){
    for(int i=1;i<10;i++)f[1][i]=1;
    for(int i=2;i<11;i++){
        for(int j=0;j<10;j++){
            for(int k=j;k<10;k++){
                f[i][j]+=f[i-1][k];
            }
        }
    }
}
int dp(int n){
    //1~n，这里我们需要特判n=0。
    if(!n)return 0;
    vector<int> nums;//存储分割位数。
    while(n)nums.push_back(n%10),n/=10;
    int last=0;//last存储上一位的最大值。
    int ans=0;//答案。
    for(int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        //走左边的分支。因为要保持不降序，所以我们j>=last。
        for(int j=last;j<x;j++){
            ans+=f[i+1][j];//注意是i+1位。
        }
        if(last>x)break;//说明上一位比x大，不能构成降序了，直接退出。
        last=x;//走右分支了，更新last。
        if(!i)ans++;//全部枚举完了，自身也同样构成了一种方案。
    }
    return ans;
}
int main(){
    init();
    while(cin>>l>>r){
        cout<<dp(r)-dp(l-1)<<endl;
    }
    return 0;
}