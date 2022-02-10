#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using pdd = pair<double, double>;
const int N = 1e5+7;
const int p = 1e2;
pdd a, b, c;
double area(pdd a, pdd b, pdd c){
    return abs(a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x) / 2.0;
}
int main(){
    while(cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y){
        double s = area(a, b, c);
        double sum = 0.0;
        int cnt = 1;
        srand((unsigned)time(NULL));
        cout<<s<<endl;
        for(int i = 1;i <= 1e8;i++){
            double tx = 1.0*(rand()%p);
            double ty = 1.0*(rand()%p);
            if(ty>(p-tx) || tx<0 || ty<0)continue;
            if(i<=100){
                printf("tx = %lf %lf\n", tx, ty);
            }
            pdd t = {tx, ty};
            sum += max({area(a, b, t), area(a, c, t), area(b, c, t)});
            cnt++;
        }
        cout<<cnt<<endl;
        cout<<36*sum/(cnt*1.0)/s<<endl;
    }
}