#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, H, S;
int h[N], s[N], w[N];
int dp[N][N][N];
int main(){
    scanf("%d%d%d", &n, &H, &S);
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d%d", &h[i], &w[i], &s[i]);
    }
    int x, y;
    for(int i = 1; i <= n; ++ i){
        for(int j = h[i]; j <= H; ++ j){
            for(int k = s[i] - (j - h[i]); k <= S; ++ k){
                if(k <= s[i]){
                    
                }
            }
        }
    }
    return 0;
}