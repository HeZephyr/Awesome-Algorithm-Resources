/**
  *@filename:C_Pair_Programming
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-10 22:55
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;
const int INF = 0x3f3f3f3f;

int t,k,n,m;
int a[N],b[N];
void solve(){
    vector<int> result;
    int l = 1,r = 1;
    int ans = k;
    bool flag = true;
    while(l <= n || r <= m){
        int minn1 = INF,minn2 = INF;
        if(l <= n){
            minn1 = a[l];
        }
        if(r <= m){
            minn2 = b[r];
        }
        if(minn1 >= minn2){
            //选b。
            if(minn2 <= ans){
                result.push_back(minn2);
                if(!minn2)ans ++;
                r ++;
            }
            else{
                flag = false;
                break;
            }
        }
        else{
            // 选a
            if(minn1 <= ans){
                result.push_back(minn1);
                if(!minn1)ans ++;
                l ++;
            }
            else{
                flag = false;
                break;
            }
        }
    }
    if(!flag){
        cout << - 1 << endl;
    }
    else{
        for(auto &x : result){
            cout << x << " ";
        }
        cout << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> k >> n >> m;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
        }
        for(int i = 1; i <= m; ++ i){
            cin >> b[i];
        }
        solve();
    }
    return 0;
}