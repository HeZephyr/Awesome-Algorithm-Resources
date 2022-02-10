/**
  *@filename:B.最大素数因子
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-14 10:08
**/
#include<stdio.h>
#include<string.h>

int maxPrimerFactor[1000005];//初始化为0，我们规定若为0，则表示是素数。
//埃氏筛法的思想就是剔除除1和它
int n;
void init(){
    int index=0;//index作为索引。
    //这里不能为了节约时间复杂度换为logn，因为我们要求最大素数因子的位置，每个都要遍历到确定位置。
    for(int i=2;i<1000000;i++){
        if(!maxPrimerFactor[i]){
            index++;
            maxPrimerFactor[i]=index;
            for(int j=i+i;j<1000000;j+=i){
                //确定以i为因子的数的素数因子位置。
                maxPrimerFactor[j]=index;
            }
        }
    }
    return;
}
int main(){
    init();
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",maxPrimerFactor[n]);
    }
    return 0;
}
