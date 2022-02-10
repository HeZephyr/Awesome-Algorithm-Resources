/**
  *@filename:C
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-18 14:40
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m;
struct Point{
    int x,y;
    Point(){}
    Point(int x,int y){
        this->x=x,this->y=y;
    }
};
struct Line{
    //我们通过点斜式来确定一条直线，即y=kx+b;那么判重的方法就是判断k和b是不是相等的。
    double k,b;
    Line(){}
    Line(double k,double b){
        this->k=k,this->b=b;
    }
    //由于我们要利用set判重，故我们需要对<运算符重载。
    bool operator<(const Line &A)const {
        if(k==A.k)return b<A.b;
        return k<A.k;
    }
};
set<Line> t;
Point points[maxn];
int cnt=0;//点的个数。
void addLine(Point a1,Point a2){
    if(a1.x==a2.x||a1.y==a2.y)return;//对于k=0，或者k=无穷的情况我们不考虑，避免精度损失等问题。最后我们累加上这些即可。n+m。
    double temp=(a2.x-a1.x)*1.0;
    double k=(a2.y-a1.y)*1.0/temp;
    double b=(a1.y*a2.x-a1.x*a2.y)*1.0/temp;
    t.insert(Line(k,b));
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            points[cnt++]=Point(i,j);
        }
    }
    //接下来确定直线加入set中。
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            addLine(points[i],points[j]);
        }
    }
    cout<<t.size()+n+m<<endl;
    return 0;
}