#include<stdio.h>

// 求x用10进制表示时的数位长度
int len(int x){
if(x<10) return 1;
return len(x/10)+1;
}

// 取x的第k位数字
int f(int x, int k){
    //这题我们知道len是计算x的长度，也就是说
    if(len(x)-k==0) return x%10;
    //return _____________________; //填空
    return f(x/10,k);
}

int main(){
    int x = 23574;
    printf("%d\n", f(x,3));
    return 0;
}