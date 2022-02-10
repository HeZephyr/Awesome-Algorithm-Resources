/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-31 15:09
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl
#define x first
#define y second
using namespace std;

typedef pair<double,double> pdd;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

double a,b,c;
pdd st,ed;
double getDist1(pdd a, pdd b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double getDist2(pdd a, pdd b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}
void solve(){
    //不通过直线，直接曼哈顿距离。
    double minn = getDist2(st,ed),ans;
    //起点通过y轴到达直线，终点通过y轴到达直线。
    //ax + by + c = 0,y = -(ax + c) / b, x = -(by + c) / a
    if(a != 0 && b != 0){
        pdd new_st(st.x,(-1) * (a * st.x + c) / b), new_ed(ed.x,(-1) * (a * ed.x + c) / b);
        ans = getDist1(new_st, new_ed) + getDist1(st, new_st) + getDist1(ed, new_ed);
        minn = min(ans, minn);
        //起点通过y轴到达直线，终点通过x轴到达直线。
        new_st = pdd(st.x,(-1) * (a * st.x + c) / b), new_ed = pdd((-1) * (b * ed.y + c) / a, ed.y);
        ans = getDist1(new_st, new_ed) + getDist1(st, new_st) + getDist1(ed, new_ed);
        minn = min(ans, minn);
        //起点通过x轴到达直线，终点通过y轴到达直线。
        new_st = pdd((-1) * (b * st.y + c) / a, st.y), new_ed = pdd(ed.x, (-1) * (a * ed.x + c) / b);
        ans = getDist1(new_st, new_ed) + getDist1(st, new_st) + getDist1(ed, new_ed);
        minn = min(ans, minn);
        //起点通过x轴到达直线，终点通过x轴到达直线。
        new_st = pdd((-1) * (b * st.y + c) / a, st.y), new_ed = pdd((-1) * (b * ed.y + c) / a, ed.y);
        ans = getDist1(new_st, new_ed) + getDist1(st, new_st) + getDist1(ed, new_ed);
        minn = min(ans, minn);
    }
    printf("%.8lf\n", minn);
}
int main(){	
    scanf("%lf%lf%lf", &a, &b, &c);
    scanf("%lf%lf%lf%lf", &st.x, &st.y, &ed.x, &ed.y);
    solve();
    return 0;
}