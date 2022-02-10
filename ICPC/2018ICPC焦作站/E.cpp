#include<bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;
int t, n;
int r[N];
vector<int> g;
int main(){
    scanf("%d", &t);
    for(int i = 2; i * i < N; ++ i){
        g.push_back(i * i);
    }
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            bool flag = false;
            for(auto v : g){
                if(v > i)break;
                if(i % v == 0){
                    flag = true;
                    break;
                }
            }
            if(flag)r[i] = 0;
            else r[i] = i;
        }
        int x = 3, y = 1;
        for(int i = 1; i <= n; ++ i){
            int p = 1, q = 1;
            for(int j = 2; j <= i; ++ j){
                if(i % j == 0){
                    if(r[j] == 0)continue;
                    //p / q + 1 / r[j];
                    p = p * r[j] + q;
                    q = q * r[j];
                    int gcd = __gcd(p, q);
                    p /= gcd, q /= gcd;
                }
            }
            //printf("the %d th:%d / %d\n", i, q, p);
            if(q * y < x * p){
                x = q, y = p;
            }
        }
        printf("%d / %d\n", x, y);
    }
    return 0;
}