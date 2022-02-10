/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-24 12:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000000 + 5;
const int P = 1e9+7;
const double eps = 1e-6;
int n,m;
int ans[N][5],tot;
//只有分数解的解法。
//思路，去枚举n张牌。可以通过dfs来枚举。
//dfs，求解这n张牌
double num[5];
int flag;//判断方案是否可行。
void dfs2(int idx,int state){
    if(flag == 3)return;//说明方案已经不可行了。
    if(idx == n){
        if(fabs(num[1] - m) <= eps){
            if(state){
                //说明遇到了非整数分数。
                flag = 1;
            }
            else{
                flag = 3;
            }
        }
        return;
    }
    double temp[5];
    for(int i = 0; i <= n; ++ i){
        temp[i] = num[i];
    }
    for(int i = 1; i <= n - idx + 1; ++ i){
        for(int j = 1; j <= n - idx + 1; ++ j){
            //枚举两个数运算。
            if(i == j)continue;
            for(int op = 0; op < 4; ++ op){
                int nstate = state;
                if(op == 0)num[i] += num[j];
                else if(op == 1)num[i] -= num[j];
                else if(op == 2)num[i] *= num[j];
                else{
                    num[i] /= num[j];
                    //判断是否出现小数。
                    if(fabs(num[i] - ((int)num[i])) > eps){
                        nstate = 1;
                    }
                }
                //为了避免j干扰。将j放到后面的闲置位置。
                swap(num[j],num[n - idx + 1]);
                dfs2(idx + 1,nstate);
                //还原a。
                for(int i = 1; i <= n; ++ i){
                    num[i] = temp[i];
                }
            }
        }
    }
}
void dfs1(int step,int k){
    //还需要构建k个数。
    if(step > n){
        flag = 0;
        dfs2(1,0);//判断构建的数得到的答案是否符合要求。
        if(flag == 1){
            tot ++;
            for(int i = 1; i <= n; ++ i){
                ans[tot][i] = num[i];
            }
        }
        return;
    }
    for(int i = k; i <= 13; ++ i){
        num[step] = i;
        dfs1(step + 1,i);
    }
}
void solve(){
    dfs1(1,1);//构建数。
    cout << tot << endl;
    for(int i = 1; i <= tot; ++ i){
        for(int j = 1; j <= n; ++ j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    cin >> n >> m;
    //当n<=3的情况是不可能的，因为要出现一次非整数，然后又要变成m。
    solve();
    return 0;
}