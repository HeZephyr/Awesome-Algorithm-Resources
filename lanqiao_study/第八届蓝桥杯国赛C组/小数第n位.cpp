/**
  *@filename:小数第n位
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-07 19:33
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100 + 5;
const int mod = 1e9+7;

//此题我们可以用数组来存储小数，存储的方法是不断进位。小数分为有限小数，无限循环小数，无限不循环小数。
int sz[maxn];//用于存储小数。
int bcs,cs,n;
//先判断是什么类型的。
void work(){
    int rem=bcs,cnt=0;
    do{
        sz[cnt++]=10*rem/cs;
        rem=rem*10%cs;
    }while(rem!=bcs&&rem!=0&&cnt<maxn);
    if(rem==0){
        //有限小数。输出小数点后的第n为开始的3个数。
        printf("%d%d%d\n",sz[n],sz[n+1],sz[n+2]);
    }
    else if(rem==bcs){
        //无限循环小数，循环节为cnt。
        printf("%d%d%d\n",sz[n%cnt],sz[(n+1)%cnt],sz[(n+2)%cnt]);
    }
    else{
        //无限小数。
        while(n--){
            bcs=bcs*10%cs;
        }
        for(int i=0;i<3;i++){
            printf("%d",bcs*10/cs);
            bcs=bcs*10%cs;
        }
        printf("\n");
    }
}
void solve(){
    bcs%=cs;
    n--;
    work();
}
int main(){
    scanf("%d%d%d",&bcs,&cs,&n);
    solve();
    return 0;
}