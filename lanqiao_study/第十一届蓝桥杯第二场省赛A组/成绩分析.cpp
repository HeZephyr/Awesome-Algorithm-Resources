/**
  *@filename:成绩分析
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 14:58
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
int minn,avg,maxx;
void solve(){
}
int main(){
    while(cin>>n){
        int temp;
        minn=105,maxx=-1,avg=0;
        for(int i=0;i<n;i++){
            cin>>temp;
            minn=min(temp,minn);
            maxx=max(temp,maxx);
            avg+=temp;
        }
        printf("%d\n%d\n%.2f\n",maxx,minn,double(avg)/n);
    }
    solve();
    return 0;
}