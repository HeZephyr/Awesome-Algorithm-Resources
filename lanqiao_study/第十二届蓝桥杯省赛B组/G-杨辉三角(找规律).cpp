/**
  *@filename:G-杨辉三角(找规律)
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-28 20:28
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;


int n;
ll C(int a,int b){
    ll res=1;
    for(int i=a,j=1;j<=b;i--,j++){
        res=res*i/j;
        if(res>n)return res;
    }
    return res;
}
bool check(int k){
    ll l=k*2,r=n;
    while(l<r){
        ll mid=l+r>>1;
        if(C(mid,k)>=n)r=mid;
        else l = mid + 1;
    }
    if(C(r,k)!=n)return false;
}
int main(){
    return 0;
}