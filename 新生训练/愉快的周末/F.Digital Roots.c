/**
  *@filename:F.Digital Roots
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-14 10:36
**/
#include<stdio.h>
#include<string.h>

int n;
char s[1005];//存储输入的大数。
void solve(){
    //先将其位数相加形成一个整数。
    n=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        n+=s[i]-'0';
    }
    int cnt,temp;//cnt记录取位数，temp存储形成的新整数。
    while(1){
        cnt=0,temp=0;
        while(n){
            temp+=n%10;
            cnt++;
            n/=10;
        }
        n=temp;
        if(cnt==1){
            break;
        }
    }
    printf("%d\n",n);
}
int main(){
    while(scanf("%s",s)){
        //判断是否要退出输入。
        if(s[0]=='0')break;
        solve();
    }
    return 0;
}
