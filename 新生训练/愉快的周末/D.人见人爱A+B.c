/**
  *@filename:D.人见人爱A+B
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-14 10:20
**/
#include<stdio.h>
#include<string.h>

typedef struct Date{
    int h,m,s;//时分秒。
}date;
date A,B;
int N;
void solve(){
    //先直接进行相加，再考虑进位。
    date result;
    result.h=A.h+B.h;
    result.m=A.m+B.m;
    result.s=A.s+B.s;
    //进位。
    result.m+=result.s/60,result.s%=60;
    result.h+=result.m/60,result.m%=60;
    printf("%d %d %d\n",result.h,result.m,result.s);
}
int main(){
    while(scanf("%d",&N)!=EOF){
        while(N--){
            scanf("%d%d%d",&A.h,&A.m,&A.s);
            scanf("%d%d%d",&B.h,&B.m,&B.s);
            solve();
        }
    }
    return 0;
}