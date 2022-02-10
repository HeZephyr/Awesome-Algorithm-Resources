#include <stdio.h>

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

int f2(const char* s, int begin, int end)
{
    //这一步实际上就是累加，需要注意的就是是否有乘号。
	int p = begin;
	int pro = 1;//pro实际上就是存储乘法结果。那么我们需要知道的就是f3是字符串转化函数。
	while(1){
		int p0 = p;
		while(p!=end && s[p]!='*') p++;
		//pro *= _______________________________;  //填空
        //得到的p0~p就是数值。
        pro *=f3(s,p0,p);  //填空
		if(p==end) break; 
		p++;
	}
	printf("f2: pro=%d\n", pro);
	return pro;
}

int f(const char* s)
{
    //f函数中的参数即为表达式。只有加法和乘法。
	int p = 0;
	int sum = 0;
	while(1){
		int p0 = p;
		while(s[p]!=0 && s[p]!='+') p++;//这里的p0是起始位置，p则是结束位置，寻找的则是加号。
		sum += f2(s,p0,p);//这里计算加号左边的值。
		if(s[p]==0) break;
		p++;
	}
	
	return sum;
}

int main()
{
	int x = f("12+18+5*4*3+10");
	printf("%d\n", x);
	return 0;
}
