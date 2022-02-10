#include <stdio.h>
#include <string.h>

//移动函数。
void move(char* data, int from, int to)
{
	data[to] = data[from];
	data[from] = '.';
}
//判断是否出界。
int valid(char* data, int k)
{
	if(k<0||k>=strlen(data)) return 0;
	return 1;
}
	
void f(char* data)
{
	int i;
	int tag;
	int dd = 0; // 移动方向
	
	while(1){
		tag = 0;
		for(i=0; i<strlen(data); i++){
            //遍历地图。
			if(data[i]=='.') continue;
			if(data[i]=='A') dd = 1;
			if(data[i]=='B') dd = -1;
			//判断如果移动是否会出界,该情况是判断相隔棋子。
			if(valid(data, i+dd) && valid(data,i+dd+dd) 
			&& data[i+dd]!=data[i] && data[i+dd+dd]=='.'){ 
			//如果能跳... 
				move(data, i, i+dd+dd);
				printf("%s\n", data);
				tag = 1;
				break;
			}
		}
		//tag标记说明跳了。
		if(tag) continue;
		
		for(i=0; i<strlen(data); i++){
			if(data[i]=='.') continue;
			if(data[i]=='A') dd = 1;
			if(data[i]=='B') dd = -1;			
			//这里则是判断是否能够移动。	 
			if(valid(data, i+dd) && data[i+dd]=='.'){ 
			// 如果能移动...
				//if( ______________________ ) continue;  //填空位置 
                //这里主要是判断如果左右两边的字母都不相同，那么就不能移动，因为会将剩余移动的字母全都堵住。
                //if(valid(data,i+dd+dd)&&valid(data,i-dd)&&data[i+dd+dd]==data[i-dd])continue;
				move(data, i, i+dd);
				printf("%s\n", data);
				tag = 1;
				break;
			}
		}
		
		if(tag==0) break;					
	}
}
	
int main()
{
	char data[] = "AAA.BBB";	
	f(data);
	return 0;
}