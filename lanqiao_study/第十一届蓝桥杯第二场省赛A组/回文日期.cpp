/**
  *@filename:回文日期
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 15:06
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int months[]={0,31,0,31,30,31,30,31,31,30,31,30,31};
ll n;
bool isSpecialYear(int year){
    //判断是否是平闰年。
    if((year%4==0&&year%100!=0)||year%400==0){
        return true;
    }
    else{
        return false;
    }
}
bool isPalindrome(string s){
    int l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r])return false;
        l++,r--;
    }
    return true;
}
bool isABAB(string s){
    if(s[0]!=s[1]&&s[0]==s[2]&&s[1]==s[3])
        return true;
    else
        return false;
}
void solve(){
    int year,month,day;
    day=n%100;
    n/=100;
    month=n%100;
    n/=100;
    year=n;
    //cout<<year<<" "<<month<<" "<<day<<endl;
    bool flag1=false,flag2=false;//表示是否已经找到回文和ABAB回文。
    int i,j,k;
    string s1,s2,s3;
    string result1,result2;
    for(i=year;;i++){
        if(i==year)j=month;
        else j=1;
        if(isSpecialYear(i))months[2]=29;
        else months[2]=28;
        for(;j<=12;j++){
            if(i==year&&j==month)k=day+1;//这里记得应该是+1，应为是改日期之后。
            else k=1;
            for(;k<=months[j];k++){
                s1=to_string(i),s2=to_string(j),s3=to_string(k);
                if(s2.size()==1)s2="0"+s2;
                if(s3.size()==1)s3="0"+s3;
                if(!flag1){
                    if(isPalindrome(s1+s2+s3)){
                        flag1=true;
                        result1=s1+s2+s3;
                    }
                }
                if(!flag2){
                    if(isPalindrome(s1+s2+s3)&&isABAB(s1)){
                        flag2=true;
                        result2=s1+s2+s3;
                    }
                }
                if(flag1&&flag2)break;
            }
            if(flag1&&flag2)break;
        }
        if(flag1&&flag2)break;
    }
    cout<<result1<<endl;
    cout<<result2<<endl;
}
int main(){
    while(cin>>n){
        solve();
    }
    return 0;
}