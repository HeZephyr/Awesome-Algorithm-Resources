/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-28 15:39
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 5;
const int P = 1e9+7;

int n,m,d,c[N],pos[N];
int ans = 0;
void solve(){
    for(int i = n - ans + 1,j = 1; j <= m; ++ j){
        pos[j] = i;//获取每个木板放置的起始位置。
        i += c[j];
    }
    int idx = 1,x = 0;//idx为当前处理的模板，x为当前的坐标值。
    bool flag = false;//判断是否可行。
    while(x < n && idx <= m){
        if(x + d>= n + 1){
            //说明再跨一下可以到达。
        }
        if(x + d < pos[idx]){
            //说明不够，我们需要往前移。
            pos[idx] = x + d;
            x = pos[idx] + c[idx] - 1;
            idx ++;
        }
        else{
            break;
        }
        if(x + d <= n && idx > m){
            flag = true;
            break;
        }
    }
    if(flag){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        for(int i = 1, j = 1; i <= n; ++ i){
            if(i == pos[j]){
                while(i <= pos[j] + c[j] - 1){
                    cout << j << " ";
                    i ++;
                }
                i --;
                j ++;
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}
int main(){
    cin >> n >> m >> d;
    for(int i = 1; i <= m; ++ i){
        cin >> c[i];
        ans += c[i];
    }
    solve();
    return 0;
}