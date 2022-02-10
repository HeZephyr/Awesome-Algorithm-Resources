#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
const double eps = 1e-8;
struct Point{
    double x, y;
    Point(){}
    Point(double _x, double _y){
        x = _x;
        y = _y;
    }
    Point operator - (const Point &b) const{
        return Point(x - b.x, y - b.y);
    }
    double operator ^ (const Point &b) const {
        return x * b.y - y * b.x;
    }
};
int sgn(double x){
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    return 1;
}
struct Line{
    Point s, e;
    Line(){}
    Line(Point _s, Point _e){
        s = _s, e = _e;
    }
    int linecrossseg(Line v){
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        if((d1 ^ d2) == -2)return 1;
        return 0;
    }
    Point crosspoint(Line v){
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
       /* if(a1 == 0 && a2 == 0){
            return Point(0, 0);
        }
        else if(a1 == 0){
            return Point(0, (s.y * a2 - e.y * a1) / (a2 - a1));
        }
        else{
            return Point((s.x * a2 - e.x * a1) / (a2 - a1), 0);
        }*/
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
    int relation(Point p){
        int c = sgn((p - s) ^ (e - s));
        if(c < 0)return 1;
        else if(c > 0)return 2;
        return 3;
    }
    bool parallel(Line v){
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }
    int linecrossline(Line v){
        if((*this).parallel(v)){
            return v.relation(s) == 3;
        }
        return 2;
    }
};

int n, m;
Point a[N], b, c;
Line line;
bool judge(Line seg){
    return (line.linecrossline(seg) != 2 || !line.linecrossseg(seg));
}
Line seg;
bool cmp(Point aa, Point bb){
    return (aa.x - b.x) * (aa.x - b.x) +  (aa.y - b.y) * (aa.y - b.y) < (bb.x - b.x) * (bb.x - b.x) +  (bb.y - b.y) * (bb.y - b.y);
}
int main(){
    cin >> n >> m;
    cin >> b.x >> b.y >> c.x >> c.y;
    seg = Line(b, c);
    for(int i = 1; i <= n; ++ i){
        cin >> a[i].x >> a[i].y;
    }
    int idx1, k;
    while(m -- ){
        cin >> idx1 >> k;
        vector<Point> s;
        for(int i = 1; i <= n; ++i){
            if(i == idx1)continue;
            line = Line(a[i], a[idx1]);
            if(judge(seg))continue;
            s.push_back(line.crosspoint(seg));
        }
        sort(s.begin(), s.end(), cmp);
        //printf("%d\n", s.size());
        if(s.size() < k)printf("-1\n");
        else printf("%.8lf %.8lf\n", s[k - 1].x, s[k - 1].y);
    }
    return 0;
}