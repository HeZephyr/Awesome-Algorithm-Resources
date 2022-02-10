#include <bits/stdc++.h>
using namespace std;
typedef char st[8][7];
st state[2000000];
set<string> all;//判重。
st Begin={{"oybbgb"},{"oygbbb"},{"bygbby"},{"bybbgy"},{"obbogb"},{"obgobb"},{"bbgoby"},{"bbbogy"}}; 
//st Begin={{"oooooo"},{"oooooo"},{"oooooo"},{"oooooo"},{"oooooo"},{"oooooo"},{"oooooo"},{"oooooo"}};
//只有一个颜色的魔方 ans=1 
int front, tail;
void ucell(char *a){swap(a[0], a[2]); swap(a[2], a[5]); swap(a[5], a[4]);}
void rcell(char *a){swap(a[1], a[0]); swap(a[0], a[3]); swap(a[3], a[5]);}
void fcell(char *a){swap(a[2], a[1]); swap(a[1], a[4]); swap(a[4], a[3]);}
//顶层的0123块旋转。
void u(st &s)//顶层顺时针旋转 
{
	ucell(s[0]);
	ucell(s[1]);
	ucell(s[2]);
	ucell(s[3]);
	swap(s[1], s[0]);
	swap(s[2], s[1]);
	swap(s[3], s[2]);
}
//用于判重。
void uwhole(st &s)//整个魔方从顶部看 顺时针转 用于判重 
{
	u(s);
	ucell(s[4]);
	ucell(s[5]);
	ucell(s[6]);
	ucell(s[7]);
	swap(s[5], s[4]);
	swap(s[6], s[5]);
	swap(s[7], s[6]);
}
void f(st &s)//前面一层 顺时针转 
{
	fcell(s[0]);
	fcell(s[1]);
	fcell(s[4]);
	fcell(s[5]);
	swap(s[1], s[5]);
	swap(s[0], s[1]);
	swap(s[4], s[0]);
}
void fwhole(st &s)//整个魔方从前面看 顺时针转 用于判重 
{
	f(s);
	fcell(s[2]);
	fcell(s[6]);
	fcell(s[7]);
	fcell(s[3]);
	swap(s[2], s[6]);
	swap(s[3], s[2]);
	swap(s[7], s[3]);
}
void r(st &s)//魔方右层顺时针转 
{
	rcell(s[1]);
	rcell(s[2]);
	rcell(s[6]);
	rcell(s[5]);
	swap(s[2], s[1]);
	swap(s[5], s[1]);
	swap(s[6], s[5]);
}
void rwhole(st &s)//整个魔方从右边看 顺时针转 用于判重 
{
	r(s);
	rcell(s[0]);
	rcell(s[3]);
	rcell(s[4]);
	rcell(s[7]);
	swap(s[3], s[7]);
	swap(s[0], s[3]);
	swap(s[4], s[0]);
}
string convert(st &s)//魔方状态二维字符数组 转化为string 
{
	string ss;
	for(int i=0; i<8; i++)ss+=s[i];
	return ss;
}
bool try_to_insert(int tail)//判重 
{
	st k;
	memcpy((void*)k, (void*)state[tail], sizeof(state[tail]));
	for(int i=0; i<4; i++)
	{
		fwhole(k);
		for(int j=0; j<4; j++)
		{
			uwhole(k);
			for(int q=0; q<4; q++)
			{
				rwhole(k);
				if(all.count(convert(k))==1)
				{
					return false;
				}
			}
		}
	}
	all.insert(convert(k));
	return true;
}
int main()
{
	front=0,tail=1;
	all.insert(convert(Begin));
	memcpy((void*)state[0],(void*)Begin,sizeof(Begin));
	while(front!=tail)
	{
		//对当前状态分别模拟三种操作U R F 然后判重 
		for(int i=0; i<3; i++)
		{
			memcpy((void*)state[tail], (void*)state[front], sizeof(state[front]));
			if(i==0)
			{
				u(state[tail]);
				if(try_to_insert(tail))tail++;
			}
			else if(i==1)
			{
				r(state[tail]);
				if(try_to_insert(tail))tail++;
			}
			else if(i==2)
			{
				f(state[tail]);
				if(try_to_insert(tail))tail++;
			}
		}
		front++;
	}
	cout<<front<<endl;
	return 0;
}
//ans 229878