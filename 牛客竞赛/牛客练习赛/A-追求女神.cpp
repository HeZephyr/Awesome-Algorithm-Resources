/**
  *@filename:A-追求女神
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-22 09:48
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
struct node{
    int x,y,t;
    bool operator<(const node &A)const{
        return t<A.t;
    }
};
node a[N];
void solve(){
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].t>>a[i].x>>a[i].y;
        }
        a[0].t=0,a[0].x=0,a[0].y=0;
        bool flag=true;
        for(int i=1;i<=n;i++){
            int len=abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y);
            int temp=a[i].t-a[i-1].t;
            if(len>temp){
                flag=false;
                break;
            }
            if((temp-len)%2){
                flag=false;
                break;
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    solve();
    return 0;
}