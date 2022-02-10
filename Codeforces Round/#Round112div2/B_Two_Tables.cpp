/**
  *@filename:B_Two_Tables
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-30 22:56
**/
#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,W,H,w,h;
pii a,b;
void solve(){
    if(h <= a.y || h <= H - b.y){
        printf("%.9f\n",0);        
    }
    else{
        //说明距离不够，我们看是否在边界。
        if(h + (b.y - a.y) > H){
            //说明高度不够，我们必须要移动。
            if(w + (b.x - a.x) > W){
                //说明宽度不够。
                cout << -1 << endl;
            }
            else{
                double minn1 = min(w - a.x,w - (W - b.x));
                if(minn1 < 0)minn1 = 0;
                printf("%.9f\n",minn1);
            }
        }
        else{
            //说明高度够，我们可以作移动。
            if(w + (b.x - a.x) > W){
                //说明水平移不了，我们只能上升或者下降。
                double minn1 = min(h - a.y,h - (H - b.y));
                if(minn1 < 0)minn1 = 0;
                printf("%.9f\n",minn1);
            }
            else{
                //如果够，我们分别判断。
                double minn1 = min(w - a.x,w - (W - b.x));
                if(minn1 < 0)minn1 = 0;
                double minn2 = min(h - a.y,h - (H - b.y));
                if(minn2 < 0)minn2 = 0;
                if(minn1 == 0 || minn2 == 0){
                    minn1 = minn2 = 0;
                }
                printf("%.9f\n",min(minn1,minn2));
            }
        }
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> W >> H;
        cin >> a.x >> a.y >> b.x >> b.y;
        cin >> w >> h;
        solve();
    }
    return 0;
}