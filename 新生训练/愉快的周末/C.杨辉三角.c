/**
  *@filename:C.杨辉三角
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-14 10:16
**/
#include<stdio.h>
#include<string.h>

int triangle[35][35];
int n;//杨辉三角的层数。

void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            //获得杨辉三角。
            if(i==j||i==1){
                triangle[i][j]=1;
            }
            else{
                triangle[i][j]=triangle[i-1][j]+triangle[i-1][j-1];
            }
            printf("%d",triangle[i][j]);
            i==j?printf("\n"):printf(" ");
        }
    }
    printf("\n");
}
int main(){
    while(scanf("%d",&n)!=EOF){
        solve();
    }
    return 0;
}