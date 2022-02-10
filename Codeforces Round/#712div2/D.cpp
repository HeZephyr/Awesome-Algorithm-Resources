/**
  *@filename:D
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-07 09:07
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

vector<pair<int,int> > od,ev;//存储坐标。od存储x+y为奇数的坐标。ev存储x+y为偶数的坐标。
int n;
void solve(){
}
int main(){
    while(cin>>n){
        od.clear(),ev.clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((i+j)&1){
                    od.push_back({i,j});
                }
                else{
                    ev.push_back({i,j});
                }
            }
        }
        int temp;
        int od_index=0,ev_index=0;//索引。
        for(int i=1;i<=n*n;i++){
            cin>>temp;
            //根据temp判断。
            if(temp!=1&&od_index<od.size()){
                //如果没有禁用颜色1
                cout<<1<<" "<<od[od_index].first<<" "<<od[od_index].second<<endl;
                od_index++;
            }
            else if(temp!=2&&ev_index<ev.size()){
                //如果没有禁用颜色2，就填2.
                cout<<2<<" "<<ev[ev_index].first<<" "<<ev[ev_index].second<<endl;
                ev_index++;
            }
            else{
                //否则根据情况来填充。
                if(od_index<od.size()){
                    cout<<3<<" "<<od[od_index].first<<" "<<od[od_index].second<<endl;
                    od_index++;
                }
                else{
                    cout<<3<<" "<<ev[ev_index].first<<" "<<ev[ev_index].second<<endl;
                    ev_index++;
                }
            }
            cout.flush();
        }
    }
    return 0;
}