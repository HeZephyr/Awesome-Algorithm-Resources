/**
  *@filename:C++17
  *@author: pursuit
  *@created: 2021-09-05 11:50
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;


void solve(){
    /* //if switch 语句中初始化，即在语句中加上初始化语句。
    //形式为：if(初始化语句; 条件)语句; else (初始化语句; 条件);
    //形式为：switch(初始化语句; 条件)语句;
    //需要注意的一点就是在if和switch语句中的初始化语句如果是一个变量声明，那么该变量
    //作用域为该语句
    if(int x = rand(); x <= 0){
        cout << x << endl;
    }
    else if(x = 1; x){
        cout << x << endl;
    } */
    //构造函数模板推导。即能根据给定数值类型推导。
    /* pii a(1,2);//c++17之前
    pair b(1,'2'); // c++17。
    cout << a.first << " " << a.second << endl;
    cout << b.first << " " << b.second << endl;
    vector v = {"abc"};
    cout << v[0] << endl; */
    /* //结构化绑定,将指定的名称绑定到初始值设定的子对象或元素。
    int c[2] = {1, 2};
    auto [a, b] = c;//注意这里设定的[]大小一定要和所赋对象的大小相同。
    cout << a << " " << b << endl;
    auto &[x, y] = c;//利用引用类型可以修改其值。
    x = 3;
    cout << c[0] << " " << c[1] << endl; */
    /* 我们学习过inline关键字，引入inline关键字的就是 
    为了解决一些频繁调用的小函数大量消耗栈内存。在函数定义时添加inline修饰符
    则可表示为内联函数，原理是不在调用时发生控制转移，而是在编译阶段将函数体嵌入到
    每一个调用该函数的语句中。不过inline只是对编译器的一个建议，最后是否真的能内联
    ，看编译器的意思。
    由于在c++中，类结构体中不允许出现非const的静态成员。即：
    static int a = 10;//编译出错。
    const static int a = 10;//需要加上const。
    通过inline之后。
    */
}
int main(){	
    solve();
    return 0;
}