#include<bits/stdc++.h>

//判断天平两边哪边重。
int balance(int a, int b)
{
    if(a<b) return -1;
    if(a>b) return 1;
    return 0;
}

void judge(char* data, int a, int b, int std)
{
    //judge判断并输出相关信息。
    switch(balance(data[a],data[std])){
        case -1:printf("%d light\n", a);break;
        case 0:printf("%d heavy\n", b);break;
        case 1:printf("err!\n", b);break;
    }
}

// data 中8个元素，有一个假币，或轻或重
void f(char* data)
{
    //易知这里也是一个比较的地方。
    //switch( ____________________________________ ){ // 填空
    switch(balance(data[0]+data[1]+data[2],data[3]+data[4]+data[5])){ // 填空
        case -1:
            //如果为-1，说明左边小于右边。那么我们需要交叉组合判断。
            switch(balance(data[0]+data[4],data[3]+data[1])){
                case -1:judge(data,0,3,1);break;//如果左边小于右边。
                case 0:judge(data,2,5,0);break;//如果相等，说明假币只可能在2和5之中。判断即可。
                case 1:judge(data,1,4,0);
            }
        break;
        case 0:judge(data,6,7,0);break;//相等，说明只可能在6和7中出现。0是比较值，说明之前的实际上在判断除了6,7之外的。
        case 1:
            switch(balance(data[0]+data[4],data[3]+data[1])){
                case -1:judge(data,4,1,0);break;
                case 0:judge(data,5,2,0);break;
                case 1:judge(data,3,0,1);
            }
        break;
    }
}

int main()
{
    int n;
    char buf[100];
    scanf("%d", &n);
    gets(buf);//gets被删除了。
    int i;
    for(i=0; i<n; i++){
        gets(buf);
        f(buf);
    }
    return 0;
}