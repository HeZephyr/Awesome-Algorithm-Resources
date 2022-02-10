/**
* @filename:C.cbp
* @Author : pursuit
* @Blog:unique_pursuit
* @email: 2825841950@qq.com
* @Date : 2021-03-17-22.33.47
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn=1e5+5;
const int mod=1e9+7;

int t,n;
void solve(){
    vector<int> a(n);
    vector<int> b;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(i==0||a[i]!=a[i-1]){
            b.emplace_back(a[i]);
        }
    }
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            b.emplace_back(a[i]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<b[i];
        i==n-1?cout<<endl:cout<<" ";
    }
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n;
            solve();
        }
    }
    return 0;
}
