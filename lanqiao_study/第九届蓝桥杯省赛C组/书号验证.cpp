#include<stdio.h>

// 验证成功返回 1，否则返回 0 
int f(const char* s)
{
	int k=1;
	int sum = 0;
	int i; 
	for(i=0; s[i]!='\0'; i++){
		char c = s[i];
		if(c=='-' || c==' ') continue;
		//sum += _________________________________________ ;  //填空
        sum+= (c-'0')*(k%2?1:3);
		k++;
		if(k>12) break; 
	}
	
	while(s[i]!='\0') i++;
	
	return (s[i-1]-'0') == (10-sum % 10)%10;
}

int main()
{
	printf("%d\n",f("978-7-301-04815-3"));
	printf("%d\n",f("978-7-115-38821-6"));	
	return 0;
}

