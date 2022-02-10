#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e2 + 10, P = 998244353;
int n, A[N][N], B[N][N];
int a[N][N], free_num;
int equ, var;
int pow2[N];
void cal(int n){
    pow2[0] = 1;
    for(int i = 1; i <= n; ++ i){
        pow2[i] = 1LL * pow2[i - 1] * 2 % P;
    }
}
void init(){
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            a[i][j] = A[i][j];
        }
    }
}
int Gauss(){
    int max_r, col, k;
    for(k = 0, col = 0; k < equ && col < var; ++ k, ++ col){
        max_r = k;
        for(int i = k + 1; i < equ; ++ i){
            if(abs(a[i][col]) > abs(a[max_r][col])){
                max_r = i;
            }
        }
        if(!a[max_r][col]){
            -- k;
            continue;
        }
        if(max_r != k){
            for(int j = k; j < var + 1; ++ j){
                swap(a[k][j], a[max_r][j]);
            }
        }
        for(int i = k + 1; i < equ; ++ i){
            if(a[i][col]){
                for(int j = col; j < var + 1; ++ j){
                    a[i][j] ^= a[k][j];
                }
            }
        }
    }
    for(int i = k; i < equ; ++ i){
        if(a[i][col]){
            return - 1;
        }
    }
    if(k < var)return var - k;//自由变元个数。
    return 0;
}
int main(){
    scanf("%d", &n);
    cal(n);
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            scanf("%d", &A[i][j]);
        }
    }
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            scanf("%d", &B[i][j]);
        }
    }
    equ = var = n;
    ll res = 1;
    for(int j = 0; j < n; ++ j){
        //枚举第一行乘c的解。
        init();
        for(int i = 0; i < n; ++ i){
            a[i][i] = (A[i][i] - B[i][j] + 2) % 2;
        }
        free_num = Gauss();
        if(free_num != -1){
            res = res * pow2[free_num] % P;
        }
    }
    printf("%lld\n", res);
    return 0;
}