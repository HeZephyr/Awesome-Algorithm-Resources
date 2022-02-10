/**
  *@filename:Transform
  *@author: pursuit
  *@created: 2021-09-05 15:27
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

//将点(x, y, z)绕L线段旋转r度和-r度得到两点P和Q。如果P的纵坐标大于Q则输出P，否则输出Q。
//利用罗德里格公式，但注意要先用向量表示。
typedef struct Point{
    double x, y, z;
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {};
}Vector;
int t;
double a, b, c, x, y, z, r;
inline double radToDegree(double rad){
    return rad * 180 / PI;
}
inline double degreeToRad(double degree){
    return degree / 180 * PI;
}
//向量平移之后还是那个向量，所以只需要原点和向量的终点即可
//!向量 + 向量 = 向量，点 + 向量 = 向量
Vector operator + (Vector A, Vector B){return Vector(A.x + B.x, A.y + B.y, A.z+B.z);}
//!点 - 点 = 向量(向量BC = C - B)
Vector operator - (Point A, Point B){return Vector(A.x - B.x, A.y - B.y, A.z-B.z);}
//!向量 * 数 = 向量
Vector operator * (Vector A, double p){return Vector(A.x * p, A.y * p, A.z * p);}
//!向量 / 数 = 向量
Vector operator / (Vector A, double p){return Vector(A.x / p, A.y / p, A.z / p);}
//!点/向量的比较函数
bool operator < (const Point& a, const Point& b) {
	if(a.x != b.x)return a.x < b.x;
	else if(a.y != b.y)return a.y < b.y;
	else return a.z < b.z;
}

//!点积(满足交换律)
double Dot(Vector A, Vector B){return A.x * B.x + A.y * B.y + A.z * B.z;}
//叉乘
Vector multi(Vector A,Vector B){return Vector(A.y*B.z-B.y*A.z,B.x*A.z-A.x*B.z,A.x*B.y-B.x*A.y);}
//转单位向量
Vector toUnitVector(Vector U){
	double k=sqrt(Dot(U,U));
	return Vector(U/k);
}
//罗德里格斯公式
Vector eval(Vector U,Vector V,double r){
	return V*cos(r)+U*Dot(U,V)*(1-cos(r))+multi(U,V)*sin(r);
}
void solve(){
    Vector U = {a, b, c}, V{x, y, z}, P, Q;
    U = toUnitVector(U);
    P = eval(U, V, degreeToRad(r));
    Q = eval(U, V, degreeToRad(-r));
    if(P.z > Q.z){
        printf("%.9lf %.9lf %.9lf\n", P.x, P.y, P.z);
    }
    else{
        printf("%.9lf %.9lf %.9lf\n", Q.x, Q.y, Q.z);
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> a >> b >> c >> x >> y >> z >> r;
        solve();
    }
    return 0;
}