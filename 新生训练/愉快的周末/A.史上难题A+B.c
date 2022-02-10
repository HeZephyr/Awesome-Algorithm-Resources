/**
  *@filename:A.史上难题A+B
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-14 09:58
**/
#include<stdio.h>
#include<string.h>

int T;
char A[1005],B[1005];

void solve(){
    int index_A=strlen(A)-1,index_B=strlen(B)-1,add=0;//add表示进位值，初始为0.
    int result[1005];
    /**
     *显然我们是要从低位开始进行加法。
     *为了统计result的长度以及作为索引存储值，我们还需要一个变量cnt来记录。
    **/
    int cnt=0;//索引
    int x,y,temp;//辅助变量。
    while(index_A>=0||index_B>=0||add!=0){
        x=index_A>=0?A[index_A]-'0':0;
        y=index_B>=0?B[index_B]-'0':0;
        temp = x+y+add;
        result[cnt++]=temp%10;
        add=temp/10;
        index_A--,index_B--;
    }
    printf("%s + %s = ",A,B);
    //由于和我们是从低位存储到高位的，故我们输出的时候应该要逆着输出。
    for(int i=cnt-1;i>=0;i--){
        printf("%d",result[i]);
    }
    printf("\n");
}
int main(){
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%s%s",A,B);
        printf("Case %d:\n",i);
        solve();
        if(i!=T){
        printf("\n");
        }
    }
    return 0;
}