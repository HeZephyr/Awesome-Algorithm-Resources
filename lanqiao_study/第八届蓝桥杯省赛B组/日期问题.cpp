/**
  *@filename:日期问题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-31 14:59
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int months[]={0,31,0,31,30,31,30,31,31,30,31,30,31};
struct Date{
    int year,month,day;
};
int x,y,z;
vector<Date> date;//存放日期。
bool cmp(Date a,Date b){
    if(a.year==b.year){
        if(a.month==b.month){
            return a.day<b.day;
        }
        return a.month<b.month;
    }
    return a.year<b.year;
}
bool isSpecial(int year){
    if((year%4==0&&year%100!=0)||year%400==0){
        return true;
    }
    else{
        return false;
    }
}
void join(int year,int month,int day){
    if(year>=60) year+=1900;
    else year+=2000;
    if(isSpecial(year)) months[2]=29;
    else months[2]=28;
    //接下来开始判断满足条件。
    if(month>0&&month<=12&&day>0&&day<=months[month]){
        //去重
        for(int i=0;i<date.size();i++){
            if(year==date[i].year&&month==date[i].month&&day==date[i].day){
                return;
            }
        }
        date.push_back({year,month,day});
    }
}
void solve(){
    //我们分情况判断是否符合即可。
    //年月日 日月年 月日年。
    int year,month,day;
    //x,y,z
    year=x,month=y,day=z;
    join(year,month,day);
    //z y x
    year=z,month=y,day=x;
    join(year,month,day);
    //z x y
    year=z,month=x,day=y;
    join(year,month,day);
    sort(date.begin(),date.end(),cmp);
    for(auto &x:date){
        printf("%04d-%02d-%02d\n",x.year,x.month,x.day);
    }
}
int main() {
    scanf("%d/%d/%d",&x,&y,&z);
    solve();
    return 0;
}