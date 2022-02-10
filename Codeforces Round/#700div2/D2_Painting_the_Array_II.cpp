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
vector<int> v[N];
int nex[N];
void solve(){
    for(int i = 1; i <= n; ++ i){
        for(int j = 0 ; j < (int)v[i].size() - 1; ++ j){
            nex[v[i][j]] = v[i][j + 1];//保存下一个与其值相等的情况。
        }
    }
    int ans = 0;
    int x = -1,y = -1;//x代表a0中的最后一个元素，y代表a1中的最后一个元素，初始化为-1.
    int next_x = n + 1,next_y = n + 1;//初始化。
    for(int i = 1; i <= n; ++ i){
        int z1 = a[i],z2 = a[i + 1];//z1表示当前要处理的元素，z2表示下一个要处理的元素。
        if(z1 == x){
            //放x更优。
            next_x = nex[i];
        }
        else if(z1 == y){
            next_y = nex[i];
        }
        else{
            //说明都不相等，我们需要考虑放哪个更优。
            ans ++;
            if(z2 == x && z2 != y){
                y = z1;
                next_y = nex[i];
            }
            else if(z2 == y && z2 != x){
                x = z1;
                next_x = nex[i];
            }
            else{
                if(next_x < next_y){
                    //说明下个相等的x比y先到。
                    y = z1;
                    next_y = nex[i];
                }
                else{
                    x = z1;
                    next_x = nex[i];
                }
            }
        }
    }
    cout << ans << endl;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        v[a[i]].push_back(i);
        nex[i] = n + 1;
    }
    solve();
    return 0;
}