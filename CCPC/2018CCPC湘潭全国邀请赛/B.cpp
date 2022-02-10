#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n,m,k;
int a[N];
int q1[N],s1,e1;//单调递减队列。
int q2[N],s2,e2;//单调递增队列。
void solve(){
    int maxx = 0,pos = 0;
    s1 = 0,e1 = 0,s2 = 0,e2 = 0;
    for(int i = 1; i <= n; ++ i){
        //注意这里可以相等。
        while(s1 < e1 && a[q1[e1 - 1]] < a[i])e1 --;//维护单调递减队列。
        while(s2 < e2 && a[q2[e2 - 1]] > a[i])e2 --;//维护单调递增队列。
        q1[e1 ++] = i;
        q2[e2 ++] = i;
        //维护题目要求，满足区间[m,k]
        while(s1 < e1 && s2 < e2 && a[q1[s1]] - a[q2[s2]] > k){
            //判断两者哪个下标更前，剔除。
            if(q1[s1] < q2[s2]){
                pos = q1[s1 ++];
            }
            else{
                pos = q2[s2 ++];
            }
        }
        if(s1 < e1 && s2 < e2 && a[q1[s1]] - a[q2[s2]] >= m){
            maxx = max(maxx,i - pos);
        }
    }
    printf("%d\n", maxx);
}
int main(){
    while(~scanf("%d%d%d", &n, &m, &k)){
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}