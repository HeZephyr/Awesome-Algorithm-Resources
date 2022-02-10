/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-28 12:56
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int t,n,a[N],pos[N],vis[N];//vis[i]表示第i次操作是否用完。
void solve(){
    //我们会交换k-1次，首先交换1，让1往左移。再2,3,4..
    for(int i = 1; i <= n; ++ i){
        //要将pos[i]上的i回到i上。
        if(pos[i] > i){
            while(pos[i] > i && !vis[pos[i] - 1]){
                swap(a[pos[i] - 1],a[pos[i]]);
                vis[pos[i] - 1] = true;
                //cout << a[pos[i] - 1] << " " << a[pos[i]] << endl;
                //这里它们的下标都发生了改变。
                swap(pos[a[pos[i]]],pos[a[pos[i] - 1]]);
            }
        }
        vis[pos[i]] = true;//由于该点被确定了，故设置该点为true。
    }
    for(int i = 1; i <= n; ++ i){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        memset(vis,0,sizeof(vis));
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
            pos[a[i]] = i;
        }
        solve();
    }
    return 0;
}