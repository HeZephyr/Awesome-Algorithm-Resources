/**
  *@filename:旅行问题
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-03 11:47
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000000 + 5;
const int P = 1e9+7;

int n,p[N],d[N],a[N << 1];
int st,ed;
ll s[N << 1],q[N];
bool flag[N];
void solve(){
    d[0] = d[n];//便于逆时针处理。
    for(int i = 1; i <= n; ++ i){
        a[i] = a[i + n] = p[i] - d[i];
    }
    //存储2 * n - 1的前缀和。
    for(int i = 1; i < 2 * n; ++ i){
        s[i] = s[i - 1] + a[i];
    }
    //维护一个单调递增序列。
    st = 1,ed = 0;
    for(int i = 1; i < 2 * n; ++ i){
        //剔除过期元素。
        while(st <= ed && i - n >= q[st])st ++ ;
        //维护单调队列。
        while(st <= ed && s[q[ed]] >= s[i])ed --;
        q[++ ed] = i;
        if(i >= n && s[q[st]] >= s[i - n])flag[i - n + 1] = true;
    }
    //求后缀和。
    for(int i = 1; i <= n; ++ i){
        a[i] = a[i + n] = p[n - i + 1] - d[n - i];//注意这里的差别。
    }
    for(int i = 1; i < 2 * n; ++ i){
        s[i] = s[i - 1] + a[i];
    }
    //维护一个单调递增序列。
    st = 1,ed = 0;
    for(int i = 1; i < 2 * n; ++ i){
        //剔除过期元素。
        while(st <= ed && i - n >= q[st])st ++ ;
        //维护单调队列。
        while(st <= ed && s[q[ed]] >= s[i])ed --;
        q[++ ed] = i;
        if(i >= n && s[q[st]] >= s[i - n])flag[2 * n - i] = true;
    }
    for(int i = 1; i <= n; ++ i){
        if(flag[i]){
            printf("TAK\n");
        }
        else{
            printf("NIE\n");
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &p[i], &d[i]);
    }
    solve();
    return 0;
}