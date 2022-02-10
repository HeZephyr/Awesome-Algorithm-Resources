/**
  *@filename:计数问题
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-12 13:12
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int l,r;
int f[11][10][10];//预处理f数组。其中f[i][j][u]表示i位最高位为j的数拥有u的个数。
void init(){
    for(int i=0;i<10;i++)f[1][i][i]=1;
    for(int i=2;i<11;i++){
        for(int j=0;j<10;j++){
            for(int u=0;u<10;u++){
                //判断j是否等于u。
                if(j==u)f[i][j][u]+=pow(10,i-1);
                for(int k=0;k<10;k++){
                    f[i][j][u]+=f[i-1][k][u];
                }
            }
        }
    }
}
ll dp(int n,int u){
    //1~n,求x的出现次数。
    if(!n)return u?0:1;//特判n是否为0.根据u的值确定返回值。
    vector<int> nums;//存储分割后的位数。
    while(n)nums.push_back(n%10),n/=10;
    int last=0;//last记录前面u出现的次数。
    ll ans=0;//答案。
    for(int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        //左边分支，0~x。
        for(int j=(i==nums.size()-1);j<x;j++){
            //由于此题不能有前导0.
            ans+=f[i+1][j][u];//注意这里i需要+1，因为我们i下标从0开始。而位数从1开始。
        }
        //走左边分支，那么我们需要加上前面的个数。注意这里需要乘上x，因为左边分支有x中选择。
        ans+=x*last*pow(10,i);
        if(x==u)last++;//记录last。
        if(!i)ans+=last;//加上这个数本身含有的。
    }
    //由于我们前面都是枚举n位数的，我们还需要统计所有0~n-1位数的方案数量。
    //例如000011是不合法的，但11是合法的。
    //这一步确实很容易忽略，没办法，数位DP就是这么难。
    for(int i=1;i<nums.size();i++){
        for(int j=(i!=1);j<=9;j++){
            ans+=f[i][j][u];
        }
    }
    return ans;
}
void solve(){
}
int main(){
    init();
    while(cin>>l>>r&&(l||r)){
        if(l>r)swap(l,r);
        for(int i=0;i<=9;i++){
            cout<<dp(r,i)-dp(l-1,i);
            i==9?cout<<endl:cout<<" ";
        }
    }
    solve();
    return 0;
}