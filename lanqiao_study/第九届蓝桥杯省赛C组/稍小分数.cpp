#include<stdio.h>

int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b, a%b);	
}
int main()
{
	// 这是屏幕上显示的那个分数 a/b
	int a = 7;
	int b = 13;
	
	int m,n;
	int max_a = 0;
	int max_b = 1; 
	
	for(n=100; n>1; n--){
		for(m=n-1; m>=1; m--){
			if(m*b<a*n && gcd(m,n)==1){
				//if( __________________________________ ){  //填空
                if(m*max_b>n*max_a){
					max_a = m;
					max_b = n;
					break;
				}
			}
		}
	}
	printf("%d/%d\n", max_a, max_b);	
	return 0;
}
