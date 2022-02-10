/**
  *@filename:B_Plus_and_Multiply
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-03 21:08
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,a,b;
map<int,int> p;
bool check(int x,int q){
    while(x % q == 0)x /= q;
    return x == 1;
}
void solve(){
    if(n < a || n < b || (a == 1 && (n - 1) % b != 0)){
        puts("NO");
    }
    else{
        p.clear();
        bool flag = false;
        queue<int> q;
        q.push(1);
        p[1] ++;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            //cout << temp << endl;
            if((n % temp == 0 && a != 1 && check(n / temp,a)) || (n - temp) % b == 0){
                flag = true;
                break;
            }
            ll x;
            for(int i = 0; i < 2; ++ i){
                x = temp;
                if(i == 0){
                    x *= a;
                }
                else{
                    x += b;
                }
                if(x <= n && p[x] == 0){
                    p[x] ++;
                    q.push(x);
                }
            }
        }
        if(flag){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> a >> b;
        solve();
    }
    return 0;
}