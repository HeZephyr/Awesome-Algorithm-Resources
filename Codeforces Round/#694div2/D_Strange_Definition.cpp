/**
  *@filename:D_Strange_Definition
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-03 09:20
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 300000 + 5;
const int P = 1e9+7;

int t,n,q;
ll w;
int primer[N],cnt;
map<int,int> p;//存储质因子。
void init(){
    for(int i = 2; i < N; ++ i){
        if(!primer[i]){
            primer[++primer[0]] = i;
            for(int j = i * 2; j < N; j += i){
                primer[j] = 1;
            }
        }
    }
}
void get(int x){
    int ans = 1;
    for(int i = 1; i <= primer[0]; ++ i){
        int temp = 0;
        while(x % primer[i] == 0){
            temp++;
            x /= primer[i];
        }
        if(temp % 2 == 1){
            ans *= primer[i];//获取奇质因子。对于偶数因子本来就满足，无需考虑。
        }
        if(x < 1LL * primer[i] * primer[i])break;
    }
    if(x != 1){
        ans *= x;
    }
    p[ans] ++;
}
void solve(){
    int ans1 = 0,ans2 = 0;
    for(auto &it: p){
        ans1 = max(ans1,it.second);
        if(it.second % 2 == 0)ans2 += it.second;
        else if(it.first == 1) ans2 += it.second;//将偶数因子累加起来。
    }
    ans2 = max(ans1,ans2);
    scanf("%d", &q);
    while(q -- ){
        scanf("%lld", &w);
        printf("%d\n",w ? ans2 : ans1);
    }
}
int main(){
    init();
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        p.clear();
        int temp;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &temp);
            get(temp);
        }
        solve();
    }
    return 0;
}