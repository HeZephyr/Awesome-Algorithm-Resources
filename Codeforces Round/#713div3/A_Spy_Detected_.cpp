/**
  *@filename:A_Spy_Detected_
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-10 22:37
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
int a[maxn];
int b[maxn];
bool cmp(int i,int j){
    return a[i]<a[j];
}
void solve(){
    sort(b+1,b+1+n,cmp);
    if(a[b[1]]==a[b[2]]){
        cout<<b[n]<<endl;
    }
    else{
        cout<<b[1]<<endl;
    }
}
int main(){
    int t;
    while(cin>>t){
        while(t--){
            cin>>n;
            for(int i=1;i<=n;i++){
                cin>>a[i];
                b[i]=i;
            }
            solve();
        }
    }
    return 0;
}