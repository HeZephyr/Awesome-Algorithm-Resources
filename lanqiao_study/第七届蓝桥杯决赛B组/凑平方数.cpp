/**
  *@filename:凑平方数
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-24 13:09
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;


//想法是将所有满足条件的平方数给找出来。答案为300.
bool used[10];//用于辅助判断是否出现重复的数。
vector<ll> nums;//存储平方数
set<int> t;//存储位数，判断是否符合存在唯一的0~9
ll ans=0;//统计方案数
bool  check(ll num){
    memset(used,false,sizeof(used));
    int temp;
    while(num>0){
        temp=num%10;
        num/=10;
        if(used[temp])return false;
        used[temp]=1;
    }
    return true;
}
int getNumLen(ll num){
    int temp=0;
    while(num>0){
        temp++;
        num/=10;
    }
    return temp;
}
bool is_ok(ll num){
    t.clear();
    if(getNumLen(num)==9){
        t.insert(0);
    }
    while(num>0){
        t.insert(num%10);
        num/=10;
    }
    if(t.size()!=10){
        return false;
    }
    return true;
}
void dfs(ll num,int numLen,int pos){
    //num表示合成的数，numlen为合成数的长度，而pos则代表的就是当前开始遍历平方数的下标。
    if(numLen==10&&is_ok(num)){
        ans++;
        return;
    }
    int len;
    for(int i=pos;i<nums.size();i++){
        len=getNumLen(nums[i]);
        if(numLen+len>10){
            break;//剪枝。
        }
        else{
            //特判为0的时候。
            if(i==0){
                dfs(0,1,1);
            }
            else{
                len=getNumLen(nums[i]);
                //cout<<num*ll(pow(10,len))+nums[i]<<endl;
                dfs(num*ll(pow(10,len))+nums[i],len+numLen,i+1);
            }
        }
    }
}
void solve(){
    dfs(0,0,0);
    cout<<ans<<endl;
}
int main() {
    ll temp;
    for(ll i=0;i<100000;i++){
        temp=i*i;
        if(temp>9876543210)break;
        if(check(temp)){
            nums.push_back(temp);
        }
    }
    //将这些都列出来之后就可以进行组合了。
    solve();
    return 0;
}