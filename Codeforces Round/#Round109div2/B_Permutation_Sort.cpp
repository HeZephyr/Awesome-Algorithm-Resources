/**
  *@filename:B_Permutation_Sort
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-16 16:09
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 50 + 5;
const int P = 1e9+7;

int t,n,a[N];
void solve(){
    if(is_sorted(a+1,a+1+n)){
        cout<<0<<endl;
    }
    else{
        //说明没有排序成功，我们选择排序，最多排三次。
        if(a[1]==1||a[n]==n){
            cout<<1<<endl;
        }
        else{
            if(a[1]==n&&a[n]==1){
                cout<<3<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        solve();
    }
    return 0;
}