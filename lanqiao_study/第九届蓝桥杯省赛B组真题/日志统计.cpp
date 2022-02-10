/**
  *@filename:日志统计
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-09 13:37
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,d,k;
pair<int,int> logInfo[maxn];
bool idInfo[maxn];//idInfo[i]表示id为i的是否曾是热帖。
int cnt[maxn];//cnt[i]表示i在当前的t时间段内获赞的次数。
void solve(){
    //排序遍历。
    sort(logInfo,logInfo+n);
    memset(idInfo,false,sizeof(idInfo));//初始化默认全不是热帖。
    memset(cnt,0,sizeof(cnt));//初始无人获赞。
    int f=0,t=0;//首尾指针。f表示起点，t表示终点。
    while(t<n){
        cnt[logInfo[t].second]++;//获得赞数。
        while(logInfo[t].first-logInfo[f].first>=d){
            //当时间间隔超过了d，那么之前的赞就要作废。
            cnt[logInfo[f].second]--;
            f++;
        }
        if(cnt[logInfo[t].second]>=k){
            idInfo[logInfo[t].second]=true;
        }
        t++;//时间更新。
    }
    for(int i=0;i<=maxn;i++){
        if(idInfo[i])cout<<i<<endl;
    }
}
int main(){
    while(cin>>n>>d>>k){
        for(int i=0;i<n;i++){
            cin>>logInfo[i].first>>logInfo[i].second;
        }
        solve();
    }
    return 0;
}