/**
  *@filename:F1_Guess_the_K_th_Zero_Easy_version_
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-06 00:06
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n,k;
//二分查找。
void solve(){
    int T=20;//查找次数最多20次。
    int l=1,r=n;
    while(T--){
        int mid=(l+r)>>1;//我们每次二分查询即可得到所在区间。
        cout<<"?"<<" "<<l<<" "<<mid<<endl;
        cout.flush();
        int res;
        cin>>res;//这个即返回的是[l,mid]这段区间的1的数量，那么0的数量自然易得。
        int cnt=mid-l+1-res;
        if(cnt<k){
            //说明第k个0在右边。
            k-=cnt;
            l=mid+1;
        }
        else{
            //说明第k个0在左边。
            r=mid;
        }
        if(l==r){
            cout<<"! "<<l<<endl;
            break;
        }
    }
}
int main(){
    cin>>n>>t;
    while(t--){
        cin>>k;
        solve();
    }
    return 0;
}