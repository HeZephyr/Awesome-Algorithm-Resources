/**
  *@filename:拉马车
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-01 11:29
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

queue<char> a[2];//a和b的牌序列，利用双端队列处理。
void solve(){
    //模拟游戏过程。结束的条件即有一人的牌序列为空。
    int flag=0;//0代表a出牌，1代表b出牌。我们利用异或操作转换角色。
    vector<char> temp;
    char op;
    int ans=0;//统计游戏次数，由于字符串长度是不超过30的，所以我们可以设置若游戏次数超过1e3，则游戏无法结束。
    while(!a[0].empty()&&!a[1].empty()){
        ans++;
        if(ans>=1000){
            cout<<-1<<endl;
            return;
        }
        op=a[flag].front(),a[flag].pop();
        temp.push_back(op);
        //cout<<flag<<" "<<op<<endl;
        //判断是否有相同牌点。
        int len=temp.size();
        for(int i=0;i<len-1;i++){
            if(temp[i]==op){
                for(int j=len-1;j>=i;j--){
                    a[flag].push(temp[j]);
                    temp.pop_back();
                }
                //赢牌的人再出一次牌.
                flag^=1;
                break;
            }
        }
        flag^=1;
    }
    if(!a[0].empty()){
        while(!a[0].empty()){
            cout<<a[0].front();
            a[0].pop();
        }
    }
    else{
        while(!a[1].empty()){
            cout<<a[1].front();
            a[1].pop();
        }
    }
    cout<<endl;
}
int main(){
    string temp1,temp2;
    while(cin>>temp1>>temp2){
        while(!a[0].empty()){
            a[0].pop();
        }
        while(!a[1].empty()){
            a[1].pop();
        }
        for(auto &x:temp1)a[0].push(x);
        for(auto &x:temp2)a[1].push(x);
        solve();
    }
    return 0;
}