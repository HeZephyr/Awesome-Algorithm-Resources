/**
  *@filename:数列求值
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-10 00:47
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//这道题其实我们在乎的也就是后四位数。直接遍历求解即可。
int main(){
    int a=1,b=1,c=1,d;
    for(int i=4;i<=20190324;i++){
        if(i%4==0){
            d=(a+b+c)%10000;
        }
        else if(i%4==1){
            a=(b+c+d)%10000;
        }
        else if(i%4==2){
            b=(c+d+a)%10000;
        }
        else{
            c=(d+a+b)%10000;
        }
    }
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;//4659
    cout<<20190324%4<<endl;
    return 0;
}