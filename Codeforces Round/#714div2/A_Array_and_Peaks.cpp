/**
  *@filename:A_Array_and_Peaks
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-15 18:51
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//构建高峰，我们知道构建高峰需要(n-1)/2即可。
//也就是说k必须小于等于(n-1)/2
int t,n,k;
void solve(){
    if(k>(n-1)/2)puts("-1");
    else{
        //构建。
        cout<<1<<" ";//先输出一个1.
        n--;
        int even=2,odd=3;
        while(n>0){
            if(k>0){
                cout<<odd<<" "<<even<<" ";
            }
            else{
                //说明高峰已经填完了。
                if(n>1)cout<<even<<" "<<odd<<" ";
                else{
                    //说明n为偶数，最后还剩余一个未输出，即是even。
                    cout<<even<<" ";
                }
            }
            even+=2,odd+=2;
            k--,n-=2;
        }
        cout<<endl;
    }
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n>>k;
            solve();
        }
    }
    return 0;
}