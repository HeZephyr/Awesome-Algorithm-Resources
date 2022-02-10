/**
  *@filename:整数拼接
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 19:15
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,k;
int cnt[11][maxn];
int a[maxn];
void solve(){
}
int main(){
    cin>>n>>k;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++){
        int temp=a[i]%k;
        for(int j = 0; j < 11; j++){
            cnt[j][temp]++;
            temp = temp*10%k;
        }
    }
    //用哈希表存储完之后开始遍历统计。
    ll res=0;
    for(int i=0;i<n;i++){
        int temp=a[i]%k;
        int len=to_string(a[i]).size();//获取其位数。
        res+=cnt[len][(k-temp)%k];//加上互余。
        //cout<<res<<endl;
        //判断i==j
        int temp1=temp;
        while(len--)temp1=temp1*10%k;
        if(temp1==(k-temp)%k)res--;//减去重复计算的值。
    }
    cout<<res<<endl;
    solve();
    return 0;
}