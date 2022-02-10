/**
  *@filename:G.a^b
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-14 10:48
**/
#include<stdio.h>
#include<string.h>

long T,N;
long quick_pow(long n,long q){
    long result=1;
    while(q){
        if(q&1){
            result=result*n%10;
        }
        n=n*n%10;
        q>>=1;//等价与q/=2;
    }
    return result;
}
void solve(){
    printf("%ld\n",quick_pow(N%10,N));
}
int main(){
    while(scanf("%ld",&T)!=EOF){
        while(T--){
            scanf("%ld",&N);
            solve();
        }
    }
    return 0;
}
