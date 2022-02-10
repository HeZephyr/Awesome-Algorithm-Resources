int exGcd(int a, int b, int &x, int &y)   //x和y使用引用
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int g = exGcd(b, a%b, x, y);    //递归计算exGcd（b,a%b）
    int temp = x;             //存放x的值
    x = y;
    y = temp - (a/b)*y;       //更新y = x(old) - a/b*y(old)
    return g;                 //g是gcd
}

int exGcd(int a,int b,int &x,int &y){
    //利用引用最后x,y就是我们想要的值。
    if(b==0){
        //说明到达已知解。
        x=1;
        y=0;
        return a;
    }
    int g=exGcd(b,a%b,x,y);//递归到最后寻找到我们已知的解。
    //开始回溯，通过已知解，利用公式返回。
    int temp=x;//temp=x2
    x=y;//x1=y2;
    y=temp-a/b*y;//y1=(x2-a/b*y2)。
    return g;
}