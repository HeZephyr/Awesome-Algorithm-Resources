/**
  *@filename:猴子分香蕉
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-09 14:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//一定要注意均分这个点。假设一开始有香蕉x。
//说明(x-1) mod 5 我们设(x-1)*4/5=y
//说明(y-2)mod 5,我们设(y-2)*4/5=z
//则(z-3) mod 5，我们设(z-3)*4/5=u
//则(u-4) mod 5,我们设(u-4)*4/5=v
//则v mod 5;我们枚举x判断。
void solve(){
}
int main(){
    int x,y,z,u,v;//3141
    for(x=6;;x+=5){
        y=(x-1)*4/5;
        if((y-2)>0&&(y-2)%5==0){
            z=(y-2)*4/5;
            if((z-3)>0&&(z-3)%5==0){
                u=(z-3)*4/5;
                if((u-4)>0&&(u-4)%5==0){
                    v=(u-4)*4/5;
                    if(v>0&&v%5==0){
                        cout<<x<<endl;
                        break;
                    }
                }
            }
        }
    }
    solve();
    return 0;
}