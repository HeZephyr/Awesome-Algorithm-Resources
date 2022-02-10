#include<iostream>
using namespace std;
class Base
{
  private:
    int mem1,mem2;
  public:
      //用m1和m2分别初始化数据成员mem1和mem2
    
	  Base(int m1, int m2): mem1(m1),mem2(m2) {} 
      //squareSum函数定义，返回两个数据成员平方之和
//请在下面空白处完善代码，使得程序正常运行
      virtual int squareSum(){
          return mem1 * mem1 + mem2 * mem2;
      }
};
	
class Derived: public Base
{
  private:
    int mem3;
  public:
      //利用m1和m2作为调用基类构造函数的实际参数
      //请在下面空白处完善代码，使得程序正常运行
      Derived(int m1,int m2,int m3):Base(m1,m2){
          mem3 = m3;
      }
      int squareSum(){
          return mem3 * mem3 + Base::squareSum();
      }
};


int main() {
    Derived b(1,2,3); 
    Base a(5,6), *p;
	p=&a; cout<<p->squareSum()<<' '; 
	p=&b; cout<<p->squareSum()<<endl;
	return 0;
}