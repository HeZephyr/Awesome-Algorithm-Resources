/**
  *@filename:D_Expression_Evaluation_Error
  *@author: pursuit
  *@created: 2021-09-06 00:09
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//D直接无脑拆 拆出10^p p越大越好就行
int t, n, s;
int power[11];
void init(){
    power[0] = 1;
    for(int i = 1; i <= 9; ++ i){
        power[i] = power[i - 1] * 10;
    }
}
void solve(){
    vector<int> a;
    int sum = 0;
    while(s){
        a.push_back(s % 10);
        sum += s % 10;//sum表示为能凑成的最大10次幂的数。
        s /= 10;
    }
    while(sum < n){
        //这个时候我们需要凑。从低位到高位考虑。
        for(int i = 1; i < a.size(); ++ i){
            if(a[i] > 0){
                -- a[i], a[i - 1] += 10;
                sum += 9;
                break;//退出。即希望用低位凑。能不进到高位就不进到高位。
            }
        }
    }
    vector<int> res;
    for(int i = a.size() - 1; i >= 0; -- i){
        for(int j = 0; j < a[i]; ++ j){
            res.push_back(power[i]);
        }
    }
    while(res.size() > n){
        int x = res.back();
        res.pop_back();
        res.back() += x;
    }
    for(int i = 0; i < res.size(); ++ i){
        cout << res[i] << " ";
    }
    cout << endl;
}
int main(){	
    init();
    cin >> t;
    while(t -- ){
        cin >> s >> n;
        solve();
    }
    return 0;
}