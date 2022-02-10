/**
  *@filename:数字划分
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-07 18:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//先将所有数的和、平方和、立方和求出来，再枚举判断即可。
int ans1,ans2,ans3,result;
bool vis[20];
vector<int> a(1,1);//存储结果数组。
void dfs(int cur,int s1,int s2,int s3){
    //当前填写的数下限，s1为当前的和，s2为当前的平方和，s3为当前的立方和。
    if(s1*2>ans1||s2*2>ans2||s3*2>ans3)return;
    if(s1*2==ans1&&s2*2==ans2&&s3*2==ans3){
        for(int i=0;i<a.size();i++){//1 4 6 7 10 11 13 16
            cout<<a[i]<<" ";
        }
        cout<<endl;
        result++;
    }
    for(int i=cur;i<=16;i++){
        if(!vis[i]){
            vis[i]=true;
            a.push_back(i);
            dfs(i+1,s1+i,s2+i*i,s3+i*i*i);
            vis[i]=false;
            a.pop_back();
        }
    }
    //cout<<s1<<" "<<s2<<" "<<s3<<endl;
}
void solve(){
    //dfs枚举。当大于和的一般的时候立即退出。
    dfs(2,1,1,1);
    cout<<result<<endl;
}
int main(){
    for(int i=1;i<=16;i++){
        ans1+=i;
        ans2+=i*i;
        ans3+=i*i*i;
    }
    solve();
    return 0;
}