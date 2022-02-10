/**
  *@filename:A
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-09 19:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

string s;
struct node{
    int st,ed;
};
void solve(){
    vector<node> pos;
    int st=-1,ed=-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            if(st==-1){
                st=i;
            }
            ed=i;
        }
        else if(ed!=-1){
            pos.push_back({st,ed});
            st=-1;
            ed=-1;
        }
    }
    if(ed!=-1&&st!=-1){
        pos.push_back({st,ed});
    }
    bool flag=false;
    for(int i=0;i<pos.size();i++){
        if(i+1<pos.size()&&pos[i+1].st-pos[i].ed==2&&!flag){
            i++;
            flag=true;
        }
        if(pos[i].ed-pos[i].st==0){
            flag=true;
        }
    }
    cout<<pos.size()-flag<<endl;
}
int main(){
    while(cin>>s){
        solve();
    }
    return 0;
}