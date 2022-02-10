#include<bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int n,m,s[N],q[N],st,ed;
void solve(){
    st = 0,ed = -1;
    q[++ ed] = 0;
    int ans = -0x3f3f3f3f,l,r;
    for(int i = 1; i <= n; ++ i){
        //剔除过期元素。
        while(st <= ed && i - q[st] > m){
            st ++;
        }
        int sum = s[i] - s[q[st]];
        if(sum > ans){
            ans = sum,l = q[st] + 1,r = i;
        }
        while(st <= ed && s[q[ed]] > s[i]){
            ed -- ;
        }
        q[++ ed] = i;
    }
    printf("%d\n" ,ans);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    solve();
    return 0;
}