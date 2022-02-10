/**
* @filename:B.cbp
* @Author : pursuit
* @Blog:unique_pursuit
* @email: 2825841950@qq.com
* @Date : 2021-03-17-22.55.57
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn=1e5+5;
const int mod=1e9+7;

int t,n,m;
map<int,int> p;
void solve(){
    int ans=0;
    if(p[0]){
        //如果存在，就将这些分为一组。
        ans++;
    }
    for(int i=1;i<m;i++){
        if(p[i]){
            //那么我们就需要去寻找它们的互余数数量。
            if(abs(p[i]-p[m-i])<=1){
                //要知道我们构造只能夹着凑，即两个互余数数量之差最多为1.
                ans++;
            }
            else{
                //说明互余数不足，我们需要额外分一数组。
                ans+=abs(p[i]-p[m-i]);
            }
            p[m-i]=0;//避免重复计算。
        }
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n>>m;
            p.clear();
            vector<int> a(n);
            for(int i=0;i<n;i++){
                cin>>a[i];
                //记录余数，因为我们只关心能否整除m，对m取余能有效处理，将范围都变成m以内。
                p[a[i]%m]++;
            }
            solve();
        }
    }
    return 0;
}
