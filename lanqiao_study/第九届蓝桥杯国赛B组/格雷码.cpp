#include <stdio.h>

//题目关键如下生成方式：
//编码全从0开始。
//当产生第奇数个数时，只把当前数字最末位改变（0变1，1变0）
//当产生第偶数个数时，先找到最右边的一个1，把它左边的数字改变。
void show(int a,int n)
{
    //打印格雷码。
	int i;
	int msk = 1;
	for(i=0; i<n-1; i++) msk = msk << 1;
	for(i=0; i<n; i++){
		printf((a & msk)? "1" : "0");
		msk = msk >> 1;
	}
	printf("\n");
} 

void f(int n)
{
	int i;
	int num = 1;
	for(i=0; i<n; i++) num = num<<1;
	
	int a = 0;
	for(i=0; i<num; i++){
		show(a,n);
		
		if(i%2==0){
            //当产生的是第奇数个数的时候，最末位改变。
			a = a ^ 1;
		}
		else{
            //当产生的是第偶数个数的时候，先找到最右边的1，再将它左边的数字改变。
			//a = _________________________ ; //填空
            //x&(-x)取最右边的1.再左移一位与x做与即可。
            a = a^((a&(-a))<<1);
		}
	}
}

int main()
{
	f(4);
	return 0;
}
