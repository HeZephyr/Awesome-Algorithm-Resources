/**
  *@filename:乘积尾零
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-03 10:30
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;  

//这道题实际上就是将数分解，然后对于分解之后的因数相乘之后只有2和5相乘才能凑0，所以我们可以统计2和5因子的数量即可。
int main(){
    int temp;
    int cnt2=0,cnt5=0;
    while(cin>>temp&&temp!=1){//这里采用1作为结束标志。
        while(temp%2==0||temp%5==0){
            if(temp%2==0){
                cnt2++;
                temp/=2;
            }
            if(temp%5==0){
                cnt5++;
                temp/=5;
            }
        }
    }
    cout<<min(cnt2,cnt5)<<endl;//31
    return 0;
}