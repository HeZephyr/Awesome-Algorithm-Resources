#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;

int step[maxn];
int main(){
    for(int i = 1; i <= 1000; ++i){
        step[i * i] = 1;
    }
    for(int i = 1; i <= 1000; ++i){
        for(int j = 1; j <= 1000; ++j){
            if(!step[i*i + j*j])step[i*i + j*j] = 2;
            if(i > j && !step[i*i - j*j])step[i*i - j*j] = 2;
        }
    }
    for(int i = 1; i <= 100000; ++i){
        if(step[i])continue;
        if(i < 50000){
            if(i % 2)step[i] = 2;
            else step[i] = 3;
        }
        else {
            step[i] = 3;
        }
    }
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        printf("%d\n", step[n]);
    }
}