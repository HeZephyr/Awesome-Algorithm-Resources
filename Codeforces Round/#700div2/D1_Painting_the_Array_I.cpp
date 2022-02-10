/**
  *@filename:D1_Painting_the_Array_I
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-02 09:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,a[N]; 
void solve(){
    int ans = 0;
    int x = -1,y = -1;//x代表a0中的最后一个元素，y代表a1中的最后一个元素，初始化为-1.
    for(int i = 1; i <= n; ++ i){
        int z1 = a[i],z2 = a[i + 1];//z1表示当前要处理的元素，z2表示下一个要处理的元素。
        if(z1 == x && z1 == y)continue;//因为放哪都没有贡献。
        if(z1 == x){
            //此时放a1更优。
            ans ++;
            y = z1;
        }
        else if(z1 == y){
            //此时放a0更优。
            ans ++;
            x = z1;
        }
        else{
            //如果两个都可以放，我们需要考虑贡献，即下一个元素是否会影响。
            ans ++;
            if(z2 == x){
                //那我们放x就可能抵消这种冲突。
                x = z1;
            }
            else{
                y = z1;
            }
        }
    }
    cout << ans << endl;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}