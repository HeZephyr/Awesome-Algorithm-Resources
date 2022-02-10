/**
  *@filename:A_Average_Height
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-16 22:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n;
vector<int> odd,even;
void solve(){
    for(int i=0;i<odd.size();i++){
        cout<<odd[i]<<" ";
    }
    for(int i=0;i<even.size();i++){
        cout<<even[i]<<" ";
    }
    cout<<endl;
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n;
            int temp;
            odd.clear(),even.clear();
            for(int i=0;i<n;i++){
                cin>>temp;
                if(temp%2)odd.push_back(temp);
                else even.push_back(temp);
            }
            solve();
        }
    }
    return 0;
}