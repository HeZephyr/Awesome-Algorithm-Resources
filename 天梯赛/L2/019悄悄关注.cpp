/**
  *@filename:019悄悄关注
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-21 15:08
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m;//关注人数和点赞用户id数
map<string,int> p1,p2;//p1存储关注，标记是否关注过，p2存储点赞次数，判断是否大于平均值。
int sum;
void solve(){
    //开始判断。
    vector<string> result;
    double avg=sum*1.0/m;
    //cout<<avg<<endl;
    for(auto &x:p2){
        if(p1.find(x.first)==p1.end()&&x.second>avg){
            result.push_back(x.first);
        }
    }
    if(result.size()==0)puts("Bing Mei You");
    else{
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<endl;
        }
    }
}
int main(){
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        p1[s]++;
    }
    cin>>m;
    sum=0;
    int temp;
    for(int i=0;i<m;i++){
        cin>>s>>temp;
        p2[s]=temp;
        sum+=temp;
    }
    solve(); 
    return 0;
}