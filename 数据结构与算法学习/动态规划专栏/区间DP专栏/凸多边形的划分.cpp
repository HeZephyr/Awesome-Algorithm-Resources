/**
  *@filename:凸多边形的划分
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-19 17:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 50 + 5;
const int P = 1e9+7;

int n;
ll w[N];
vector<int> f[N][N];//其中f[l][r][k]表示将[l][r]分割成k个三角形所得到的权值乘积和最小值。
vector<int> add(vector<int> &a,vector<int> &b){
    vector<int> c;
    int res=0;//进位。
    for(int i=0;i<a.size()||i<b.size();i++){
        int x=res;
        if(i<a.size())x+=a[i];
        if(i<b.size())x+=b[i];
        c.push_back(x%10);
        res=x/10;
    }
    if(res>0)c.push_back(res);
    return c;
}
vector<int> mul(vector<int> &a,int x){
    vector<int> c;
    ll temp=0;
    for(int i=0;i<a.size()||temp;i++){
        if(i<a.size())temp+=1LL*a[i]*x;
        c.push_back(temp%10);
        temp/=10;
    }
    return c;
}
bool cmp(vector<int> &a,vector<int> &b){
    if(a.size()!=b.size())return a.size()<b.size();
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]!=b[i])return a[i]<b[i];
    }
    return false;//相等返回false。
}
void solve(){
    vector<int> temp;//存储中间值。
    for(int len=3;len<=n;len++){
        //分割成n-2个三角形。
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            f[l][r].resize(N,1);
            for(int k=l+1;k<r;k++){
                temp.clear();
                temp.push_back(w[k]);
                temp=mul(temp,w[l]),temp=mul(temp,w[r]);
                temp=add(temp,f[l][k]),temp=add(temp,f[k][r]);
                if(cmp(temp,f[l][r])){
                    f[l][r]=temp;
                }
            }
        }
    }
    for(int i=f[1][n].size()-1;i>=0;i--){
        cout<<f[1][n][i];
    }
    cout<<endl;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    solve();
    return 0;
}