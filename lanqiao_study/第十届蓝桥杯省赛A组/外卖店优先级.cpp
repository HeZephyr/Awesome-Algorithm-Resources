/**
  *@filename:外卖店优先级
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-12 13:25
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

struct node{
    int ts,id;
    bool operator==(const node A){
        if(this->ts==A.ts&&this->id==A.id)return true;
        else return false;
    }
};
node orderInfo[maxn];
int n,m,t;
int priority[maxn];//cnt[i]表示当前第i个外卖店的优先级。
bool st[maxn];//st[i]判断店铺i是否处于优先级。 
int last[maxn];//last[i]表示第i个外卖店上一次有订单的时间。
bool cmp(node a,node b){
    if(a.ts==b.ts){
        return a.id<b.id;
    }
    return a.ts<b.ts;
}
void solve(){
    sort(orderInfo,orderInfo+m,cmp);
    //初始化。
    memset(priority,0,sizeof(priority));
    memset(st,false,sizeof(st));
    memset(last,0,sizeof(last));
    int l=0,r;//双指针遍历这些订单。
    while(l<m){
        r=l;
        while(r<m&&orderInfo[l]==orderInfo[r])r++;//将同一时间同一外卖店的统计起来。
        int curId=orderInfo[l].id,curTime=orderInfo[l].ts;
        priority[curId]-=(curTime-last[curId]-1);
        if(priority[curId]<0)priority[curId]=0;
        if(priority[curId]<=3)st[curId]=false;//当优先级小于等于3就会清除出缓存。
        //进行优先级增加。
        priority[curId]+=(r-l)*2;
        if(priority[curId]>5)st[curId]=true;//当优先级大于5就会加入缓存。
        //更新左端点和时间。
        //cout<<"Time:"<<curTime<<" ID:"<<curId<<" priority:"<<priority[curId]<<endl;
        l=r,last[curId]=curTime;
    }
    //订单处理完之后再对每个进行优先级处理。
    for(int i=1;i<=n;i++){
        if(last[i]<t){
            priority[i]-=(t-last[i]);
            if(priority[i]<=3)st[i]=false;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans+=st[i];
    cout<<ans<<endl;
}
int main(){
    while(cin>>n>>m>>t){
        for(int i=0;i<m;i++){
            cin>>orderInfo[i].ts>>orderInfo[i].id;
        }
        solve();
    }
    return 0;
}