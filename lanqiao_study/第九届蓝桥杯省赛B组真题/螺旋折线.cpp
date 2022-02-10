/**
  *@filename:螺旋折线
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-09 12:04
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll x,y;
void solve(){
}
int main(){
    while(cin>>x>>y){
        int judge=max(abs(x),abs(y));//第几个矩形处。
        //判断是在哪一条边上。
        if(abs(x)<=y){
            //在上方。我们知道在y轴上的点即为(4*y*y-y);
            cout<<4*y*y-y+x<<endl;
        }
        else if(abs(y)<=x){
            //在右方，我们知道在x轴上的点即为(4*x*x+x);
            cout<<4*x*x+x-y<<endl;
        }
        else if(abs(x)<=abs(y)&&y<0){
            //在下方，我们知道在y轴上的点即为(4*y*y+3*abs(y));
            cout<<4*y*y+3*abs(y)-x<<endl;
        }
        else{
            //在左方。我们知道在x轴上的点即为。(4*x*x-3*abs(x));
            cout<<4*x*x-3*abs(x)+y<<endl;
        }
    }
    solve();
    return 0;
}