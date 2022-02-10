/**
  *@filename:E_Arranging_The_Sheep
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-05 23:16
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000000 + 5;
const int mod = 1e9+7;

int t,n;
string s;
void solve(){
    vector<int> pos;
    //我们可以认为连续的就是同一个点，这样方便处理。
    int idx=1;
    for(int i=0;i<n;i++){
        if(s[i]=='*')pos.push_back(idx);
        else idx++;
    }
    if(pos.empty()){
        //说明为空。
        cout<<0<<endl;
        return;
    }
    //选择中间位置进行处理。
    int idx1=pos.size()/2,idx2=(pos.size()-1)/2;
    ll cnt1=0,cnt2=0;
    /* for(int i=0;i<pos.size();i++){
        cout<<pos[i]<<" ";
    } */
    /*  cout<<endl; */
    for(int i=0;i<pos.size();i++){
        cnt1+=abs(pos[idx1]-pos[i]);
        cnt2+=abs(pos[idx2]-pos[i]);
        /* cout<<cnt1<<" "<<cnt2<<endl; */
    }
    cout<<min(cnt1,cnt2)<<endl;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>s;
        solve();
    }
    return 0;
}