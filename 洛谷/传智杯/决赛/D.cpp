/**
  *@Author: pursuit
  *@Created: 2021-03-28 17:18
**/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

vector<map<int,int> > a(3);
int n,m;
bool check(){
    for(int i=0;i<3;i++){
        bool flag=true;
        for(auto &x:a[i]){
            if(x.second!=0){
                flag=false;
                break;
            }
        }
        if(flag)return flag;
    }
    return false;
}
void solve(){
    int cur=0;
    int cnt=1,value=0;
    int ans=0;
    while(!check()){
        bool flag=false;
        //这里判断是否能够进行接牌。
        for(auto &x:a[cur]){
            if(x.second>cnt||(x.second==cnt&&x.first>value)){
                flag=true;
                break;
            }
        }
        //如果不能接牌，那么就重新由第一个人出牌。
        if(!flag){
            cur=(cur+1)%3;
            ans++;
            if(ans==2){
                cur=(cur+1)%3;
                cnt=1,value=0;
                ans=0;
            }
            else{
                continue;
            }
        }
        else{
            ans=0;
        }
        flag=false;
        while(!flag){
            for(auto &x:a[cur]){
                if(x.second>=cnt){
                    flag=true;
                    if(x.first>value){
                        value=x.first;
                        x.second-=cnt;
                    }
                    else if(value>m)
                }
            }
        }
    }
    for(int i=0;i<3;i++){
        bool flag=false;
        for(auto &x:a[i]){
            if(x.second!=0){
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<i+1<<endl;
            break;
        }
    }
}
int main(){
    while(cin>>n>>m){
        a.clear();
        int temp;
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                cin>>temp;
                a[i][temp]++;
            }
        }
        solve();        
    }
    return 0;
}