/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 10:38
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 5;
const int P = 1e9+7;

int n,cnt[N],x,a[22][22];
void solve(){
    //先判断n是否为奇数。如果是，直接将奇数放入a[(n + 1) / 2][(n + 1) / 2]
    if(n & 1){
        for(int i = 1; i < N; ++ i){
            if(cnt[i] & 1){
                a[(n + 1) / 2][(n + 1) / 2] = i;
                cnt[i] --;
                break;
            }
        }
        //将构建中间十字。
    }
    priority_queue<pair<int,int>,vector<pair<int,int> > > q;//利用优先队列实现。
    for(int i = 1; i < N; ++ i){
        if(cnt[i])q.push({cnt[i],i});
    }
    //构建对角。
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            if(n % 2 && (i == (n + 1) / 2 || j == (n + 1) / 2))continue;
            if(!a[i][j] && !q.empty() && q.top().first >= 4){
                auto x = q.top();
                q.pop();
                a[i][j] = a[n - i + 1][j] = a[n - i + 1][n - j + 1] = a[i][n - j + 1] = x.second;
                x.first -= 4;
                if(x.first)q.push(x);
            }
        }
    }
    //注意中间十字是不会变的。我们先构建中间十字。
    if(n & 1){
        for(int i = 1; i <= n; ++ i){
            if(!a[i][(n + 1) / 2] && !q.empty() && q.top().first > 1){
                auto x = q.top();
                q.pop();
                a[i][(n + 1) / 2] = a[n - i + 1][(n + 1) / 2] = x.second;
                x.first -= 2;
                if(x.first)q.push(x);
            }
        }
        for(int j = 1; j <= n; ++ j){
            if(!a[(n + 1) / 2][j] && !q.empty() && q.top().first > 1){
                auto x = q.top();
                q.pop();
                a[(n + 1) / 2][j] = a[(n + 1) / 2][n - j + 1] = x.second;
                x.first -= 2;
                if(x.first)q.push(x);
            }
        }
    }
    bool flag = true;
    if(!q.empty())flag = false;
    if(flag){
        cout << "YES" << endl;
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "NO" << endl;
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n * n; ++ i){
        cin >> x;
        cnt[x] ++;
    }
    solve();
    return 0;
}