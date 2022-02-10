/**
  *@Author: pursuit
  *@Created: 2021-03-28 16:37
**/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int t;
int n,m;
string a,b;
void solve(){
    int ans=0;
    string temp1,temp2;
    transform(a.begin(), a.end(), back_inserter(temp1), ::toupper);
    transform(b.begin(), b.end(), back_inserter(temp2), ::toupper);
    for(int i=0;i+n<=m;i++){
        //统计。
        if(temp2.substr(i,n)==temp1){
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n>>m;
            cin>>a>>b;
            solve();
        }
    }
    return 0;
}