/**
  *@filename:付账问题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-08 12:51
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 500000 + 10;
const int mod = 1e9+7;

int n;
long double s;
int a[maxn];
int main(){
    while(cin>>n>>s){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long double ave,sum;
        ave=s/n,sum=0;
        double cur_pay;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            cur_pay=s/(n-i);//获取剩下的人需要平摊的钱数。
            if(a[i]<cur_pay){
                //如果低于此时每个人都需要支付的数，那么就全部付出，并更新剩下的人所需平摊的值。
                cur_pay=a[i];
            }
            //如果高于，就只需支付现在每个人所需的平摊数。
            s-=cur_pay;
            sum+=(cur_pay-ave)*(cur_pay-ave);
        }
        printf("%.4Lf\n",sqrt(sum/n));
    }
    return 0;
}