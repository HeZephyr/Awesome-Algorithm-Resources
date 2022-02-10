#include <stdio.h>
 
//将字符串转化为整数。
int f3(const char* s, int begin, int end)
{
	int sum = 0;
	int i;
	for(i=begin; i<end; i++){
		if(s[i]==' ') continue;
		sum = sum * 10 + (s[i]-'0');
	}
	return sum;
}
 
 //f2函数即是计算加号之前的值，即p0~p之间。
int f2(const char* s, int begin, int end)
{
	int p = begin;
	int pro = 1;
	while(1){
		int p0 = p;
        //判断是否有乘号。
		while(p!=end && s[p]!='*') p++;
        //然后乘以我们转化后的数。
		//pro *= _______________________________;  //填空
		pro*=f3(s,p0,p);
        if(p==end) break; 
		p++;
	}
	printf("f2: pro=%d\n", pro);
	return pro;
}
 
int f(const char* s)
{
	int p = 0;
	int sum = 0;
	while(1){
		int p0 = p;
		while(s[p]!=0 && s[p]!='+') p++;//找到+号，将其中的数值计算出来。
		sum += f2(s,p0,p);
		if(s[p]==0) break;
		p++;
	}
	
	return sum;
}
 
int main()
{
	int x = f("12+18+5*4*3+10");//f函数进行运算。
	printf("%d\n", x);
	return 0;
}