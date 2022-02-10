/**
  *@filename:完全二叉树的权值
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-12 13:18
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
ll sum[maxn];
int main(){
    while(cin>>n){
        memset(sum,0,sizeof(sum));
        int temp;
        for(int i=1;i<=n;i++){
            cin>>temp;
            sum[int(log2(i)+1)]+=temp;
        }
        temp=log2(n)+1;
        ll maxx=-1000000000000;
        int index=0;
        for(int i=1;i<=temp;i++){
            if(sum[i]>maxx){
                index=i;
                maxx=sum[i];
            }
        }
        cout<<index<<endl;
    }
    return 0;
}