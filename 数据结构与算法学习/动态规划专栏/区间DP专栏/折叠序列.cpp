/**
  *@filename:折叠序列
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-17 21:17
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100+ 5;
const int P = 1e9+7;
const int INF = 0x3f3f;

//区间dp，我们用f[l,r]来表示[l,r]折叠成的最小长度。
//则f[l,r]=max(f[l,k]+f[k+1][r])。这个时候我们还需要考虑到是序列折叠的情况，
//所以我们需要考虑到的就是f[l,r]是可以通过f[l,k]循环(r-l+1)/（k-l+1）次得到的。
//当然，如果我们需要判断循环节，即判断是否可以循环，那么即是(r-l+1)%（k-l+1）。
//其次就是对应字符要相等。我们用一个函数判断即可。
string s;
int f[N][N],n,len[N];//n为字符串的长度。len数组预处理每个数字所占的长度。
void init(){
    fill(f[0],f[0]+N*N,INF);
    for(int i=1;i<100;i++){
        if(i<10)len[i]=1;
        else len[i]=2;
    }
    len[100]=3;
}
bool isSubstr(int l,int r,int L,int R){
    //这个函数判断[L,R]是否可以由[l,r]得到。
    if((R-L+1)%(r-l+1))return false;
    for(int i=L;i<=R;i++){
        if(s[i]!=s[l+(i-L)%(r-l+1)])return false;
    }
    return true;
}
void print(int l,int r){
    if(f[l][r]==r-l+1){
        for(int i=l;i<=r;i++){
            cout<<s[i];
        }
        return;
    }
    for(int k=l;k<r;k++){
        if(f[l][r]==f[l][k]+f[k+1][r]){
            print(l,k);
            print(k+1,r);
            return;
        }
        if(isSubstr(l,k,k+1,r)&&f[l][r]==f[l][k]+len[(r-l+1)/(k-l+1)]+2){
            cout<<(r-l+1)/(k-l+1)<<"(";
            print(l,k);
            cout<<")";
            return;
        }
    }
}
void solve(){
    //初始化。
    for(int i=0;i<n;i++)f[i][i]=1;
    //枚举区间长度。
    for(int t=2;t<=n;t++){
        for(int l=0;l+t-1<n;l++){
            int r=l+t-1;//确定区间起点和区间端点。
            //状态转移。枚举分割点。
            for(int k=l;k<r;k++){
                f[l][r]=min(f[l][k]+f[k+1][r],f[l][r]);
                //判断是否可以循环。
                if(isSubstr(l,k,k+1,r)){
                    f[l][r]=min(f[l][r],f[l][k]+len[(r-l+1)/(k-l+1)]+2);//这里加的2为括号的长度。
                }
            }
        }
    }
    print(0,n-1);
}
int main(){
    cin>>s;
    init();
    n=s.size();
    solve();
    return 0;
}