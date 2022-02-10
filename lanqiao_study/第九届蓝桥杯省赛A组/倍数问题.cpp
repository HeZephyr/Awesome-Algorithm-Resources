/**
  *@filename:倍数问题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-07 22:06
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;

int n,mod;//n个数与mod。
void solve(){
}
int main(){
    while(cin>>n>>mod){
        vector<vector<int> > nums(mod); 
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            nums[temp%mod].push_back(temp);
        }
        //排序。
        for(int i=0;i<mod;i++){
            if(nums.size())sort(nums[i].begin(),nums[i].end(),greater<int>());//降序排列。
        }
        //接下来开始枚举即可。枚举两个余数确定另一个余数。
        int maxx=0;
        for(int i=0;i<mod;i++){
            for(int j=0;j<mod;j++){
                int k=((mod-i-j)%mod+mod)%mod;
                //枚举之后确定是否可行。
                if(nums[i].size()&&nums[j].size()&&nums[k].size()){
                    //接下来分情况选择。
                    int ans=0;
                    if(i!=j&&i!=k&&j!=k){
                        ans+=nums[i][0]+nums[j][0]+nums[k][0];
                    }
                    else if(i==j&&j==k){
                        if(nums[i].size()>=3){
                            ans+=nums[i][0]+nums[i][1]+nums[i][2];
                        }
                    }
                    else if(i==j){
                        if(nums[i].size()>=2){
                            ans+=nums[i][0]+nums[i][1]+nums[k][0];
                        }
                    }
                    else if(i==k){
                        if(nums[i].size()>=2){
                            ans+=nums[i][0]+nums[i][1]+nums[j][0];
                        }
                    }
                    else if(j==k){
                        if(nums[j].size()>=2){
                            ans+=nums[i][0]+nums[j][0]+nums[j][1];
                        }
                    }
                    maxx=max(maxx,ans);
                }
            }
        }
        cout<<maxx<<endl;
    }
    return 0;
}