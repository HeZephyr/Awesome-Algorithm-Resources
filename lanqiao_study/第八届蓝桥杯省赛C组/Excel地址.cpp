/**
  *@filename:Excel地址
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-01 09:54
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int pos;
vector<char> result;
void solve(){
    //不难发现，每一位上的权值为26，同时不存在0.位取值也为26。注意，这不是26进制。
    result.clear();
    while(pos>0){
        int temp1=pos%26,temp2=pos/26;
        if(temp1==0){
            result.push_back('Z');
            temp2--;
        }
        else{
            result.push_back('A'+temp1-1);
        }
        pos=temp2;
    }
    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i];
    }
    cout<<endl;
}
int main(){
    while(cin>>pos){
        solve();
    }
    return 0;
}