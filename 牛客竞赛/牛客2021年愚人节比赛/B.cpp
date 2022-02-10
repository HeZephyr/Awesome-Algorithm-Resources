#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	time_t rawtime ; 
	struct tm * timeinfo; 
	char s[100];  
	time ( &rawtime ); 
 
	timeinfo = localtime ( &rawtime ); 
	time_t tick = mktime(timeinfo);
	strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", timeinfo); 
	int Year = timeinfo->tm_year+1900;
	int Mon = timeinfo->tm_mon+1;
	int Day = timeinfo->tm_mday;
	int Hour = timeinfo->tm_hour;
	int Min = timeinfo->tm_min;
	int Second = timeinfo->tm_sec;
    printf("%4d/%02d/%02d %02d:%02d:%02d\n",Year,Mon,Day,Hour,Min,Second);
	return 0;
}