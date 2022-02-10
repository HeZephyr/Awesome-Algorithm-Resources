/**
  *@filename:C-完全日期
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-05 14:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int months[] = {0,31,0,31,30,31,30,31,31,30,31,30,31};
bool judge(int year){
    if((year % 4 == 0 && year % 100) || (year % 400 == 0)){
        return true;
    }
    return false;
}
bool cal(int a,int b,int c){
    int sum = 0;
    while(a)sum += a % 10, a /= 10;
    while(b)sum += b % 10, b /= 10;
    while(c)sum += c % 10, c /= 10;
    int temp = sqrt(sum);
    if(temp * temp == sum){
        return true;
    }
    else{
        return false;
    }
}
void solve(){
    int cnt = 0;
    for(int year = 2001; year <= 2021; ++ year){
        if(judge(year))months[2] = 29;
        else months[2] = 28;
        for(int month = 1; month <= 12; month ++){
            for(int day = 1; day <= months[month]; ++ day){
                if(cal(year,month,day)){
                    cnt ++;
                }
            }
        }
    }
    cout << cnt << endl;//977
}
int main(){
    solve();
    return 0;
}