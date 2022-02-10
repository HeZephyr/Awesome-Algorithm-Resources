#include <stdio.h>
#include <string.h>

//轮换前n个，再递归处理
void permu(char* data, int cur)
{
	int i,j;
	
	if(data[cur]=='\0'){
		printf("%s\n", data);
		return;
	}
	
	for(i=cur; data[i]; i++){
		char tmp = data[i]; //存储首值。
		for(j=i-1; j>=cur; j--) data[j+1] = data[j];//后面的轮上。
		data[cur] = tmp;//cur为开头值。			

		permu(data, cur+1);			

		tmp = data[cur]; 
		//___________________________________ ;  //填空
        for(int j=cur;j<i;j++)data[j]=data[j+1];
		data[i] = tmp;			
	}
}

int main()
{
	char a[] = "1234";
	permu(a,0);
	return 0;
}
