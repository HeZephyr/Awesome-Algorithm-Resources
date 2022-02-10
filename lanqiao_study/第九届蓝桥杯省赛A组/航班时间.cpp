/**
  *@filename:航班时间
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-04 00:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

struct Date{
    int h,m,s;
};
Date st,ed;//出发日期和截止日期。
int getTime(){
    scanf("%d:%d:%d %d:%d:%d",&st.h,&st.m,&st.s,&ed.h,&ed.m,&ed.s);
    //判断接下来是否是(
    int temp=0;
    if(getchar()!='\n'){
        scanf("(+%d)",&temp);
    }
    //计算时间差。
    ed.h-=st.h,ed.m-=st.m,ed.s-=st.s;
    return temp*24*3600+ed.h*3600+ed.m*60+ed.s;
}
void solve(){
}
int main(){
    int t;
    //通过两个地方的飞行时间相加取平均数抵消时差，得到飞行时间。
    while(cin>>t){
        while(t--){
           int t1=getTime();
           int t2=getTime();
           int result=(t1+t2)/2;
           printf("%02d:%02d:%02d\n",result/3600,result/60%60,result%60);
        }
    }  
    solve();
    return 0;
}