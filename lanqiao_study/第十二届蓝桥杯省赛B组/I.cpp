/**
  *@filename:I
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-18 15:58
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m;
int main(){
    while(cin>>n>>m){
        vector<int> a(n);
        for(int i=0;i<n;i++)a[i]=i+1;
        int p,q;
        while(m--){
            cin>>p>>q;
            if(p)sort(a.begin()+q-1,a.end());
            else sort(a.begin(),a.begin()+q,greater<int>() );
        }
        for(int i=0;i<n;i++){
            cout<<a[i];
            i==n-1?cout<<endl:cout<<" ";
        }
    }
    return 0;
}