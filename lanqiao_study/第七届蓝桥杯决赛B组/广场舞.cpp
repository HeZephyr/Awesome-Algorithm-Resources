/**
  *@filename:广场舞
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-25 19:39
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int INF=100000000;
const int mod = 1e9+7;

struct node{
    int x,y;
};
int n;//代表广场是n边形，也就说明了是有n个点。
int min_x,min_y,max_x,max_y;//边界，确定好遍历区间。
//判断点是否在多边形内部，利用pnpoly算法来解决。
bool pnpoly(vector<node> &points,int x,int y){
    bool flag=false;
    for(int i=0,j=n-1;i<n;j=i++){
        //为了更好的判断，我们将公式变形为乘法。
        //
        if(min(points[i].y,points[j].y)<y&&max(points[i].y,points[j].y)>=y){
            double temp=(double)points[i].x+(double)(((double)(y-points[i].y)
            /(double)(points[i].y-points[j].y))*((double)(points[i].x-points[j].x)));  
            if(temp<x)
                flag=!flag;
        }
    }
    return flag;
}
void solve(vector<node> &points){
    int ans=0;
    for(int i=min_x;i<max_x;i++){
        for(int j=min_y;j<max_y;j++){
            //判断方格四个点是否都在多边形内。
            if(pnpoly(points,i,j)&&pnpoly(points,i+1,j)&&
               pnpoly(points,i,j+1)&&pnpoly(points,i+1,j+1)){
                   ans++;
               }
        }
    }
    cout<<ans<<endl;
}
int main() {
    while(cin>>n){
        vector<node> points(n);
        min_x=INF,min_y=INF;
        max_x=(-1)*INF,max_y=(-1)*INF;
        for(int i=0;i<n;i++){
            cin>>points[i].x>>points[i].y;
            max_x=max(max_x,points[i].x);
            max_y=max(max_y,points[i].y);
            min_x=min(min_x,points[i].x);
            min_y=min(min_y,points[i].y);
        }
        solve(points);
    }
    return 0;
}
/*
5
3 3
6 4
4 1
1 -1
0 4 
*/