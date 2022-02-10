/**
  *@filename:D
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-26 00:07
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n;
map<int,int> p;
void solve(){
    vector<int> cnt;
    for(auto &x:p){
        cnt.emplace_back(x.second);
    }
    //我们知道，不相同的是可以相互抵消的，
    //倘若最多的那个比剩余的数还多，那么我们很容易就知道最后剩的数为最多的减去抵消的。
    //若小于，则我们发现，不管怎样，我们内部都可以进行抵消，因为我们总能找到最优的抵消，那么剩余的也就只和n的奇偶性有关了。
    sort(cnt.begin(),cnt.end());
    if(cnt.back()*2>n){
        cout<<cnt.back()*2-n<<endl;
    }
    else{
        cout<<n%2<<endl;
    }
}
int main() {
    while(cin>>t){
        while(t--){
            cin>>n;
            p.clear();
            int temp;
            for(int i=0;i<n;i++){
                cin>>temp;
                p[temp]++;
            }
            solve();
        }
    }
    return 0;
}