/**
  *@filename:等腰三角形
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-09 16:45
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 300 + 5;
const int mod = 1e9+7;

int n;
char graph[maxn][maxn];
string s;
void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n+i;j++){
            graph[i][j]='.';
        }
    }
    //开始填数。
    int index=0;
    //开始左边。
    for(int i=0,j=n-1;i<n-1;i++,j--){
        graph[i][j]=s[index++];
    }
    //开始底边。
    for(int i=n-1,j=0;j<2*n-1;j++){
        graph[i][j]=s[index++];
    }
    for(int i=n-2,j=2*n-3;i>0;i--,j--){
        graph[i][j]=s[index++];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n+i;j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }
}
int main(){
    s="";
    for(int i=1;i<=200;i++){
        s+=to_string(i);
    }
    while(cin>>n){
        //cout<<s.size()<<endl;
        solve();
    }
    return 0;
}