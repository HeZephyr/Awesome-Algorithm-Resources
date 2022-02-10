#include <stdio.h>
 
// a个A，b个B，c个C 字母，能组成多少个不同的长度为n的串。
int f(int a, int b, int c, int n)
{
	if(a<0 || b<0 || c<0) return 0;
	if(n==0) return 1; 
	
	//return ______________________________________ ;  // 填空
    return f(a-1,b,c,n-1)+f(a,b-1,c,n-1)+f(a,b,c-1,n-1);
}
 
int main()
{
	printf("%d\n", f(1,1,1,2));
	printf("%d\n", f(1,2,3,3));
	return 0;
}