#include<stdio.h>



//由于我们需要求得是第row行，第col列。
// 杨辉三角的第row行，第col列 
long long f(int row, int col){
    if(row<2) return 1;
    if(col==0) return 1;
    if(col==row) return 1;
    long long a[1024];
    //为第一行和第二行赋值。
    a[0]=1;
    a[1]=1;  
    int p = 2;//初始为2，即我们从第二行开始初始化。
    int q;
    while(p<=row){
        a[p] = 1;//第p行。这里表示的是存放第p行的杨辉三角数。即最后一列为1.
        //而p之前的都是上一列的状态，所以我们需要根据这些来初始化它们。
        //由于后面是a[q-1]，所以不难发现是从后往前推。
        //for( _________________ ) a[q] = a[q] + a[q-1]; //填空
        //利用一维数组腾挪。
        for(q=p-1;q>0;q--)a[q]=a[q]+a[q-1];//这里不需要更新到0，因为0位置处始终为1.
        p++;
    }
    return a[col];
}
int main()
{
    printf("%d\n", f(6,2));
    printf("%d\n", f(6,3));
    printf("%lld\n", f(40,20));  
    return 0;
}