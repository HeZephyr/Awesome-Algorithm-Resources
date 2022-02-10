#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, k, x, s[N], p[N], t[N];
int res[N];
double max = 0;
int main(){
    scanf("%d%d%d", &n, &k, &x, &p[0]);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &s[i]);
    }
    for(int i = 1; i <= k; ++ i){
        scanf("%d", &t[i]);
    }
    for(int i = 1; i <= k; ++ i){
        scanf("%d", &p[i]);
    }
    //p[0]为真实需要到达的时间。
    for(int i = 1; i <= k; ++ i){
        //给定时间为t[i]。
        double speed = 1.0 * x / t[i];
        
    }
    return 0;
}