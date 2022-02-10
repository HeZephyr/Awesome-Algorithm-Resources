/**
  *@Author: pursuit
  *@Created: 2021-03-28 16:28
**/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int n,m;
void solve(vector<int> a1,vector<int> a2){
    int ans=0;
    for(auto &x:a1){
        for(auto &y:a2){
            if(x==y){
                ans++;
            } 
        }
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n>>m){
        vector<int> a1(n),a2(m);
        for(int i=0;i<n;i++){
            cin>>a1[i];
        }
        for(int i=0;i<m;i++){
            cin>>a2[i];
        }
        solve(a1,a2);
    }
    return 0;
}